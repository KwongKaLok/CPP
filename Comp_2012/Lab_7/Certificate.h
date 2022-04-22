#ifndef Certificate_H
#define Certificate_H
#include <iostream>
#include "Issuer.h"

class CertificateBase {
    protected:
        int residualTime_;
        double faceValue_;

    public:
        bool TestMaturity(int years) {  
            residualTime_ -= years;
            if (residualTime_ <= 0) {
                return true;
            }
            return false;
        }

        double GetFaceValue() const {
            return faceValue_;
        }

        virtual void Maturity() = 0;
};

template<enum BondType bondType>
class Certificate : public CertificateBase {
    //TODO: Friend class declaration
    private:
        static int transactionsNum_;
        static double interestRate_;
        static int period_;

    private:
        Issuer<bondType>* issuer_;
        Certificate(double value, Issuer<bondType>* issuer) {
        //TODO:
            //1. Initialized non-static member
            //2. Increase transactionsNum_ by one 
        }

        virtual ~Certificate() {
        //TODO:
            //Decrease transactionsNum_ by one 
        }

        static void SetRateAndPeriod(double rate, int year) {
        //TODO:
            //Assign argument to the corresponding static member
        }


    public:
        virtual void  Maturity() {
            issuer_->Settlement(this);
        }
};


//TODO: Static member initialization, initialize to zero

#endif