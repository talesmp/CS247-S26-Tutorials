// Answer (Q8.1): `0` => the money left Alice and never reached Bob.
// withdraw ran (alice 100→0), then deposit threw => the amount vanished from the system. 
// Catching the exception does not restore the invariant; this isn't even basic -safe. 
// The strong guarantee rolls back the withdrawal on failure.

// Exception safety. This transfer is NOT even basic-safe. 
// withdraw() succeeds, then deposit() throws (bob frozen).
// The money left alice and never reached bob, so the invariant "total is conserved" is broken. 
//Catching it doesn't undo that.
#include <iostream>
#include <stdexcept>
#include <string>

struct Account {
    std::string name;
    int balance;
    bool frozen = false;

    void withdraw(int amt) { balance -= amt; }
    void deposit(int amt) {
        if (frozen) throw std::runtime_error(name + " is frozen");
        balance += amt;
    }
};

void transfer(Account& from, Account& to, int amount) {
    from.withdraw(amount);   // step 1 succeeds
    to.deposit(amount);      // step 2 THROWS -> amount left 'from', never reached 'to'
}

int main() {
    Account alice{"alice", 100};
    Account bob{"bob", 0, /*frozen=*/true};

    std::cout << "before: total = " << alice.balance + bob.balance << '\n';
    try {
        transfer(alice, bob, 100);
    } catch (const std::exception& e) {
        std::cout << "transfer failed: " << e.what() << '\n';
    }
    std::cout << "after:  alice = " << alice.balance
              << ", bob = " << bob.balance
              << ", total = " << alice.balance + bob.balance << '\n';
    return 0;
}
// Output — $100 vanished from the system:
//   before: total = 100
//   transfer failed: bob is frozen
//   after:  alice = 0, bob = 0, total = 0
//
// THE FIX (solution/): the STRONG guarantee — commit-or-rollback. 
// Wrap step 2; on failure, undo step 1 and rethrow with a bare throw. Total stays 100.
