#include <iostream>
#include <string>
#include "MyClass.h"
using namespace std;



int main() {
    HybridStore s("Milk", 40);
    s.showInfo();

    CashPayment cash;
    CardPayment card;

    s.pay(&cash, 40);
    s.pay(&card, 40);

    return 0;
}
