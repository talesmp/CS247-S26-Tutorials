// Answer (Q10.1): 410 -- bill() never resets minutes, so period 2 bills 500 minutes, not
// 250: 80 + 30 + (500−200)=>1 = 410 (should be 160). Compiles, runs, silently wrong =>
// the hazard of "base behaviour + a bit extra." An override must restate the complete
// spec.

#include "account.h"
#include "cheapaccount.h"
#include <iostream>

int main() {
    Account a("A-001");
    a.bill();                 // 0 + 30
    a.print();                // Account A-001: balance = 30

    CheapAccount c("C-002");
    c.addMinutes(250);        // 50 minutes over the 200 free
    c.bill();                 // 0 + 30 + (250-200)*1 = 80
    c.print();                // CheapAccount balance = 80

    c.addMinutes(250);        // another 250 minutes this period
    c.bill();
    // CORRECT spec: minutes were reset last period -> 80 + 30 + (250-200) = 160
    // BROKEN code:  minutes never reset (now 500) -> 80 + 30 + (500-200) = 410
    c.print();

    // Substitutability: a CheapAccount IS-A Account. Through a base pointer,
    // print() still dispatches to CheapAccount::print (it is virtual).
    Account *p = &c;
    std::cout << "(via Account*) ";
    p->print();
    return 0;
}
