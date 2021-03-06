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
    SigType GetType() const;
    virtual void Print() const = 0;
    virtual ~Signature() = 0;
};

class SchnorrSignature : public Signature
{
public:
    // Todo
    SchnorrSignature(const Number *, const Number *);
    void Print() const
    {
        cout << "s=";
        s->Print();
        cout << ", e=";
        e->Print();
        cout << endl;
    }
    ~SchnorrSignature();
    const Number *s;
    const Number *e;
};

class DSASignature : public Signature
{
public:
    // Todo
    DSASignature(const Number *, const Number *);
    void Print() const
    {
        cout << "r=";
        r->Print();
        cout << ", s=";
        s->Print();
        cout << endl;
    }
    ~DSASignature();
    const Number *r;
    const Number *s;
};

class PublicKey
{
public:
    PublicKey();
    virtual ~PublicKey();
    virtual bool Verify(const string &, const Signature &) const = 0;
    virtual void Print() const = 0;
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
    DSAPublicKey(const Number *);
    ~DSAPublicKey();
    bool Verify(const string &, const Signature &) const;
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
    virtual const Signature *Sign(const string &) const = 0;
    virtual void Print() const = 0;
};

class SchnorrSecretKey : public SecretKey
{
public:
    const Number *x;
    SchnorrSecretKey(const Number *);
    ~SchnorrSecretKey();
    const Signature *Sign(const string &) const;
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