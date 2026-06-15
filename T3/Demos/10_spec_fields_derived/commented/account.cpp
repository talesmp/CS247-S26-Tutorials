#include "account.h"
#include <iostream>
#include <utility>

Account::Account(std::string num)
    : actNo_(std::move(num)), balance_(0), fee_(30) {}

void Account::bill() {
    balance_ = balance_ + fee_;          // balance@pre + fee
}

void Account::print() const {
    std::cout << "Account " << actNo_ << ": balance = " << balance_ << "\n";
}
