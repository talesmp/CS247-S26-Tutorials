#include "account.h"
#include "cheapaccount.h"
#include <iostream>

int main() {
    Account a("A-001");
    a.bill();
    a.print();                // Account A-001: balance = 30

    CheapAccount c("C-002");
    c.addMinutes(250);
    c.bill();                 // 0 + 30 + (250-200) = 80
    c.print();                // CheapAccount balance = 80

    c.addMinutes(250);
    c.bill();                 // minutes were reset -> 80 + 30 + (250-200) = 160
    c.print();                // CheapAccount balance = 160

    Account *p = &c;
    std::cout << "(via Account*) ";
    p->print();
    return 0;
}
