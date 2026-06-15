// Topic: Spec fields (derived)
// Q10.1: Consider: fee = $30, freemin = 200, rate = $1/min The second balance is:
//   a) 160
//   b) 320
//   c) 410
//   d) 80
//   e) Crash
#include "account.h"
#include "cheapaccount.h"
#include <iostream>

int main() {
    Account a("A-001");
    a.bill();
    a.print();

    CheapAccount c("C-002");
    c.addMinutes(250);
    c.bill();
    c.print();

    c.addMinutes(250);
    c.bill();
    c.print();

    Account *p = &c;
    std::cout << "(via Account*) ";
    p->print();
    return 0;
}
