#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Specification fields -- an ABSTRACT model of observable state.
//   ActNo   = account id
//   balance = amount owed
//   fee     = monthly fee
// (Here they happen to match the private members, but a spec field need not be
//  a real data member -- e.g. a bank could store a ledger and compute balance.)
class Account {
private:
    std::string actNo_;
protected:                 // protected so the derived class can implement bill()
    double balance_;
    double fee_;
public:
    explicit Account(std::string num);
    // ensures: ActNo == num, balance == 0, fee == 30

    virtual void bill();
    // modifies: this->balance
    // ensures:  this->balance == this@pre->balance + fee

    virtual void print() const;
    // modifies: cout      <-- producing output IS a modification 

    double balance() const { return balance_; }
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
