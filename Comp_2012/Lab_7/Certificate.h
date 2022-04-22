#ifndef Certificate_H
#define Certificate_H
#include <iostream>
#include "Issuer.h"

class CertificateBase
{
protected:
    int residualTime_;
    double faceValue_;

public:
    bool TestMaturity(int years)
    {
        residualTime_ -= years;
        if (residualTime_ <= 0)
        {
            return true;
        }
        return false;
    }

    double GetFaceValue() const
    {
        return faceValue_;
    }

    virtual void Maturity() = 0;
};

template <enum BondType bondType>
class Certificate : public CertificateBase
{
    // TODO: Friend class declaration
    friend class Issuer<bondType>;

private:
    static int transactionsNum_;
    static double interestRate_;
    static int period_;

private:
    Issuer<bondType> *issuer_;
    Certificate(double value, Issuer<bondType> *issuer)
    {
        // TODO:
        // 1. Initialized non-static member
        issuer_ = issuer;
        faceValue_ = value;
        residualTime_ = period_;
        // 2. Increase transactionsNum_ by one
        transactionsNum_++;
    }

    virtual ~Certificate()
    {
        // TODO:
        // Decrease transactionsNum_ by one
        transactionsNum_--;
    }

    static void SetRateAndPeriod(double rate, int year)
    {
        // TODO:
        // Assign argument to the corresponding static member
        interestRate_ = rate;
        period_ = year;
    }

public:
    virtual void Maturity()
    {
        issuer_->Settlement(this);
    }
};

// TODO: Static member initialization, initialize to zero
template <enum BondType bondType>
int Certificate<bondType>::transactionsNum_{0};
template <enum BondType bondType>
double Certificate<bondType>::interestRate_{0};
template <enum BondType bondType>
int Certificate<bondType>::period_{0};

#endif