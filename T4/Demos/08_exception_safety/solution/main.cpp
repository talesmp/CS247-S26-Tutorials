// Strong guarantee (commit-or-rollback). 
// If deposit() throws, undo the withdrawal so it's as if the transfer never happened, then re-raise the original exception with a bare throw. 
// The invariant is preserved.
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
    from.withdraw(amount);
    try {
        to.deposit(amount);
    } catch (...) {
        from.deposit(amount);   // roll back step 1
        throw;                  // re-raise the original (bare rethrow)
    }
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
// Output — money conserved; alice is whole again:
//   before: total = 100
//   transfer failed: bob is frozen
//   after:  alice = 100, bob = 0, total = 100
