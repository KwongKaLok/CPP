#include "Certificate.h"
#include "BondHolder.h"
#include "Issuer.h"

int main() {
    IssuerBase* i1 = new Issuer<T1>("HK Bond");
    i1->SetRateAndPeriod(0.04, 1);
    i1->IssueBond(60000);
    IssuerBase* i2 = new Issuer<T2>("New York Bond");
    i2->SetRateAndPeriod(0.09, 2);
    i2->IssueBond(80000);
    IssuerBase* i3 = new Issuer<T3>("London Bond");
    i3->SetRateAndPeriod(0.15, 3);
    i3->IssueBond(100000);

    BondHolder* john = new BondHolder("John");
    BondHolder* tom = new BondHolder("Tom");
    BondHolder* lucy = new BondHolder("Lucy");

    std::cout << "[Transaction round 1]" << std::endl;
    john->PurchaseBond(i1, 5000); john->PurchaseBond(i2, 10000);
    tom->PurchaseBond(i2, 6000); tom->PurchaseBond(i3, 6000); 
    lucy->PurchaseBond(i3, 10000); lucy->PurchaseBond(i1, 10000);
    i1->Log(); i2->Log(); i3->Log();

    std::cout << "\n[1 years later]" << std::endl;
    john->Elapse(1); tom->Elapse(1); lucy->Elapse(1);
    john->Log(); tom->Log(); lucy->Log();

    std::cout << "\n[Transaction round 2]" << std::endl;
    john->PurchaseBond(i2, 5000); john->PurchaseBond(i3, 20000);
    tom->PurchaseBond(i3, 18000); tom->PurchaseBond(i1, 8000); 
    lucy->PurchaseBond(i1, 5000); lucy->PurchaseBond(i2, 10000);
    i1->Log(); i2->Log(); i3->Log();

    std::cout << "\n[2 years later]" << std::endl;
    john->Elapse(2); tom->Elapse(2); lucy->Elapse(2);
    john->Log(); tom->Log(); lucy->Log();

    i1->SetRateAndPeriod(0.05, 1);
    i2->SetRateAndPeriod(0.11, 2);

    std::cout << "\n[Transaction round 3]" << std::endl;
    john->PurchaseBond(i3, 5000); john->PurchaseBond(i1, 10000);
    tom->PurchaseBond(i1, 6000); tom->PurchaseBond(i2, 6000); 
    lucy->PurchaseBond(i2, 10000); lucy->PurchaseBond(i3, 10000);
    i1->Log(); i2->Log(); i3->Log();

    std::cout << "\n[3 years later]" << std::endl;
    john->Elapse(3); tom->Elapse(3); lucy->Elapse(3);
    john->Log(); tom->Log(); lucy->Log();
    i1->Log(); i2->Log(); i3->Log();


    delete john; delete tom; delete lucy;
    delete i1; delete i2; delete i3;
}