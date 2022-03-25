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

SchnorrPublicKey::SchnorrPublicKey(const Number *y) : y(y) {}

DSAPublicKey::DSAPublicKey(const Number *y) : y(y) {}

SecretKey::SecretKey() {}

SchnorrSecretKey::SchnorrSecretKey(const Number *x) : x(x) {}

DSASecretKey::DSASecretKey(const Number *x) : x(x) {}

Signature::~Signature() {}

SchnorrSignature::~SchnorrSignature()
{
    cout << "Destruct SchnorrSignature..." << endl;
}
DSASignature::~DSASignature()
{
    cout << "Destruct DSASignature..." << endl;
}
SchnorrPublicKey::~SchnorrPublicKey()
{
    cout << "Destruct SchnorrPublicKey..." << endl;
}
DSAPublicKey::~DSAPublicKey()
{
    cout << "Destruct DSAPublicKey..." << endl;
}
SchnorrSecretKey::~SchnorrSecretKey()
{
    cout << "Destruct SchnorrSecretKey..." << endl;
}
DSASecretKey::~DSASecretKey()
{
    cout << "Destruct DSASecretKey..." << endl;
}

bool SchnorrPublicKey::Verify(const string &message, const Signature &signature) const
{
    // Todo

    return true;
}

bool DSAPublicKey::Verify(const string &message, const Signature &signature) const
{
    // Todo

    return true;
}

const Signature *SchnorrSecretKey::Sign(const string &message) const
{
    // Todo

    return nullptr;
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

SigPair::SigPair(const PublicKey *publicKey, const SecretKey *secretKey)
    : publicKey(publicKey), secretKey(secretKey)
{
}

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
        // Todo

        return nullptr;
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
