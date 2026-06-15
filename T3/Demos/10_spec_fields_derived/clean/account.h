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
    virtual void bill();
    virtual void print() const;
    double balance() const { return balance_; }
    virtual ~Account() = default;
};

#endif
