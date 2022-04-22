#ifndef BOND_HOLDER_H
#define BOND_HOLDER_H
#include <list>
#include <string>
#include "Certificate.h"

class BondHolder {
    private:
        double profit_;
        std::string name_;
        std::list<CertificateBase*> certificates_;

    public:
        void PurchaseBond(IssuerBase* issuer, int amount);
        void Elapse(int year);
        BondHolder(std::string name);
        ~BondHolder();

        //correctness check
        void Log() const;
};

#endif