#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <string>
#include <vector>
#include "number.h"

using namespace std;

enum SigType
{
    DSA,
    Schnorr
};

class Signature
{
public:
    // Todo
    Signature();
    SigType GetType() const = 0;
    virtual void Print() = 0;
    virtual ~Signature();
};

class SchnorrSignature : public Signature
{
public:
    // Todo
    SchnorrSignature(const Number *s, const Number *e) : s(s), e(e) {}
    void Print() const
    {
        cout << "s=";
        s->Print();
        cout << ", e=";
        e->Print();
        cout << endl;
    }
    virtual ~SchnorrSignature();
    const Number *s;
    const Number *e;
};

class DSASignature : public Signature
{
public:
    // Todo
    DSASignature(const Number *r, const Number *s) : r(r), s(s) {}
    void Print() const
    {
        cout << "r=";
        r->Print();
        cout << ", s=";
        s->Print();
        cout << endl;
    }
    virtual ~DSASignature();
    const Number *r;
    const Number *s;
};

class PublicKey
{
public:
    PublicKey();
    virtual ~PublicKey();
    bool Verify(const string &message, const Signature &signature) const;
    virtual void Print();
};

class SchnorrPublicKey : public PublicKey
{
public:
    const Number *y;
    SchnorrPublicKey(const Number *y) : y(y) {}
    ~SchnorrPublicKey();

    bool Verify(const string &message, const Signature &signature) const;
    void Print() const
    {
        cout << "Schnorr Public Key is: ";
        y->Print();
        cout << endl;
    };
};
class DSAPublicKey : public PublicKey
{
public:
    const Number *y;
    DSAPublicKey(const Number *y) : y(y) {}
    virtual ~DSAPublicKey();
    bool Verify(const string &message, const Signature &signature) const;
    void Print() const
    {
        cout << "DSA Public Key is: ";
        y->Print();
        cout << endl;
    }
};

class SecretKey
{
public:
    SecretKey();
    virtual ~SecretKey();
    const Signature *Sign(const string &message) const;
    virtual void Print();
};

class SchnorrSecretKey : public SecretKey
{
public:
    const Number *x;
    SchnorrSecretKey(const Number *x) : x(x) {}
    ~SchnorrSecretKey();
    const Signature *Sign(const string &message) const;
    void Print() const
    {
        cout << "Schnorr Secret Key is: ";
        x->Print();
        cout << endl;
    };
};
class DSASecretKey : public SecretKey
{
public:
    const Number *x;

    DSASecretKey(const Number *x) : x(x) {}
    ~DSASecretKey();

    const Signature *Sign(const string &message) const;

    void Print() const
    {
        cout << "DSA Secret Key is: ";
        x->Print();
        cout << endl;
    }
};

class SigPair
{
public:
    const PublicKey *publicKey;
    const SecretKey *secretKey;
    SigPair(const PublicKey *publicKey, const SecretKey *secretKey);
    ~SigPair();
};

const SigPair *GenerateKey(SigType sigType, const string &info);

vector<SigType> SigTypes();

#endif