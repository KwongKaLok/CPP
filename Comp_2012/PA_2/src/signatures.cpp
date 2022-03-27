#include "signatures.h"
#include "number.h"

SigType Signature::GetType() const
{
    string name = typeid(*this).name();

    if (name == "12DSASignature")
        return DSA;
    else if (name == "16SchnorrSignature")
        return Schnorr;
    else
        throw invalid_argument("Signature Type does not exist!");
}

// Todo: Constructors/Destructors
Signature::Signature() {}

SchnorrSignature::SchnorrSignature(const Number *s, const Number *e) : s(s), e(e) {}

DSASignature::DSASignature(const Number *r, const Number *s) : r(r), s(s) {}

PublicKey::PublicKey() {}

DSAPublicKey::DSAPublicKey(const Number *y) : y(y) {}

SecretKey::SecretKey() {}

SchnorrSecretKey::SchnorrSecretKey(const Number *x) : x(x) {}

Signature::~Signature() {}

PublicKey::~PublicKey() {}

SecretKey::~SecretKey() {}

SchnorrSignature::~SchnorrSignature()
{
    cout << "Destruct SchnorrSignature..." << endl;
    delete s;
    delete e;
}
DSASignature::~DSASignature()
{
    cout << "Destruct DSASignature..." << endl;
    delete r;
    delete s;
}
SchnorrPublicKey::~SchnorrPublicKey()
{
    cout << "Destruct SchnorrPublicKey..." << endl;
    delete y;
}
DSAPublicKey::~DSAPublicKey()
{
    cout << "Destruct DSAPublicKey..." << endl;
    delete y;
}
SchnorrSecretKey::~SchnorrSecretKey()
{
    cout << "Destruct SchnorrSecretKey..." << endl;
    delete x;
}
DSASecretKey::~DSASecretKey()
{
    cout << "Destruct DSASecretKey..." << endl;
    delete x;
}

bool SchnorrPublicKey::Verify(const string &message, const Signature &signature) const
{
    // Todo
    if (signature.GetType() == Schnorr)
    {
        const SchnorrSignature *SCHsig = dynamic_cast<const SchnorrSignature *>(&signature);
        Number s = *SCHsig->s;
        Number e = *SCHsig->e;
        Number q = *Number::Q;
        Number g = *Number::G;
        Number p = *Number::P;
        Number y = *SchnorrPublicKey::y;

        if (Number::NSign(s) != 1) // check s is non-zero and positive
            return false;
        if (Number::NSign(e) != 1) // check e is non-zero and positive
            return false;
        if (Number::NSign(Number::Sub(q, s)) != 1) // check s < q
            return false;
        if (Number::NSign(Number::Sub(q, e)) != 1) // check e < q
            return false;

        Number rv = Number::Mul_Mod(Number::Pow(g, s, p), Number::Pow(y, e, p), p);
        Number ev = Number::Mod(Number::Hash(rv, message), q);
        if (Number::NSign(Number::Sub(ev, e)) == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool DSAPublicKey::Verify(const string &message, const Signature &signature) const
{
    // Todo
    if (signature.GetType() == DSA)
    {
        const DSASignature *DSAsig = dynamic_cast<const DSASignature *>(&signature);
        Number s = *DSAsig->s;
        Number r = *DSAsig->r;
        Number q = *Number::Q;
        Number g = *Number::G;
        Number p = *Number::P;
        Number y = *DSAPublicKey::y;

        if (Number::NSign(r) != 1) // check r is non-zero and positive
            return false;
        if (Number::NSign(s) != 1) // check s is non-zero and positive
            return false;
        if (Number::NSign(Number::Sub(q, r)) != 1) // check r < q
            return false;
        if (Number::NSign(Number::Sub(q, s)) != 1) // check s < q
            return false;

        Number w = Number::Inv(s, q);
        Number z = Number::Hash(message);
        Number u1 = Number::Mul_Mod(z, w, q);
        Number u2 = Number::Mul_Mod(r, w, q);
        Number result1 = Number::Pow(g, u1, p);
        Number result2 = Number::Pow(y, u2, p);
        Number result = Number::Mul_Mod(result1, result2, p);
        result = Number::Mod(result, q);
        if (Number::NSign(Number::Sub(result, r)) == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}

const Signature *SchnorrSecretKey::Sign(const string &message) const
{
    // Todo
    while (true)
    {
        Number k = Number::Rand(1, *Number::Q);
        Number r = Number::Pow(*Number::G, k, *Number::P);
        Number e = Number::Mod(Number::Hash(r, message), *Number::Q);
        Number s = Number::Mod(Number::Sub(Number::Mod(k, *Number::Q), Number::Mul_Mod(*(this->x), e, *Number::Q)), *Number::Q);

        if (Number::NSign(s) > 0 && Number::NSign(e) > 0)
            return new SchnorrSignature(new Number(s), new Number(e));
    }
}

const Signature *DSASecretKey::Sign(const string &message) const
{
    while (true)
    {
        Number k = Number::Rand(1, *Number::Q);
        Number r = Number::Mod(Number::Pow(*Number::G, k, *Number::P), *Number::Q);
        Number z = Number::Hash(message);
        Number zxr = Number::Mod(Number::Add(z, Number::Mul_Mod(*(this->x), r, *Number::Q)), *Number::Q);
        Number ki = Number::Inv(k, *Number::Q);
        Number s = Number::Mul_Mod(ki, zxr, *Number::Q);

        if (Number::NSign(r) > 0 && Number::NSign(s) > 0)
            return new DSASignature(new Number(r), new Number(s));
    }
}

SigPair::SigPair(const PublicKey *publicKey, const SecretKey *secretKey) : publicKey(publicKey), secretKey(secretKey) {}

SigPair::~SigPair()
{
    cout << "Destruct SigPair..." << endl;
    delete publicKey;
    delete secretKey;
}

const SigPair *GenerateKey(SigType sigType, const string &info)
{
    if (sigType == DSA)
    {
        Number x = Number::Rand(Number(1), *Number::Q);
        Number y = Number::Pow(*Number::G, x, *Number::P);
        const Number *newX = new Number(x);
        const Number *newY = new Number(y);

        DSASecretKey *sk = new DSASecretKey(newX);
        DSAPublicKey *pk = new DSAPublicKey(newY);

        SigPair *sigPair = new SigPair(pk, sk);

        return sigPair;
    }
    else if (sigType == Schnorr)
    {
        Number x = Number::Rand(Number(1), *Number::Q);
        Number y = Number::Pow(*Number::G, x, *Number::P);
        const Number *newX = new Number(x);
        const Number *newY = new Number(y);

        SchnorrSecretKey *sk = new SchnorrSecretKey(newX);
        SchnorrPublicKey *pk = new SchnorrPublicKey(newY);

        SigPair *sigPair = new SigPair(pk, sk);

        return sigPair;
    }
    return nullptr;
}

vector<SigType> SigTypes()
{
    vector<SigType> s;
    s.push_back(DSA);
    s.push_back(Schnorr);
    return s;
}
