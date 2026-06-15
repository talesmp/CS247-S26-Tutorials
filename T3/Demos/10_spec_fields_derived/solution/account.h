#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string actNo_;
protected:
    double balance_;
    double fee_;
public:
    explicit Account(std::string num);
    // ensures: ActNo == num, balance == 0, fee == 30

    virtual void bill();
    // modifies: this->balance
    // ensures:  this->balance == this@pre->balance + fee

    virtual void print() const;
    // modifies: cout

    double balance() const { return balance_; }
    virtual ~Account() = default;
};

#endif // ACCOUNT_H
