#include "BondHolder.h"

BondHolder::BondHolder(std::string name) {
    profit_ = 0;
    name_ = name;
}

void BondHolder::PurchaseBond(IssuerBase* issuer, int amount) {
    //1. Buy bond from issuer, then push it into certificate list 
    //2. Decrease profit by amount

    certificates_.push_back(issuer->SellBond(amount)); //push_back: add a value to back of the list
    profit_ -= amount;
}

// Time elapse
void BondHolder::Elapse(int year) {
    //1. Invoke TestExpire to decrease residualTime and check whether maturity
    //2. If maturity, then calculate the interest, update profit, invoke maturity method, and delete it from list

    std::list<CertificateBase*>::iterator it = certificates_.begin(); //const iterator, points to the begin of list
    while(it != certificates_.end()) { // iterate all members
        CertificateBase* cert = *it;
        if (cert->TestMaturity(year)) {
            profit_ += cert->GetFaceValue();
            cert->Maturity();
            it = certificates_.erase(it);  //When we erase a member from the list, 
        }                                  //the previous iterator will be invalid. 
                                           //We need to get a valid iterator from the return value of erase method.
        else
            it++;                          //Add the iterator by one, points to next member.
    }
}

BondHolder::~BondHolder() {
    std::list<CertificateBase*>::iterator it = certificates_.begin();
    while(it != certificates_.end()) {  //iterate all members
        (*it++)->Maturity();
    }
}

//CORRECTNESS CHECK - DO NOT MODIFY
void BondHolder::Log() const {
    std::cout << name_ << " holds " << certificates_.size() << " certificates, and the current profit is " 
        << profit_ << std::endl;
}