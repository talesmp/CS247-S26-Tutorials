// Topic: Exception safety
// Q8.1: After the (failed, but caught) transfer, what is alice + bob?
//   a) `100` — the exception was caught, so nothing changed
//   b) `0` — the money left alice and never reached bob
//   c) `200`
//   d) it crashes
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
    to.deposit(amount);
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
