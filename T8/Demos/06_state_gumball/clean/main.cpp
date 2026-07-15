#include <iostream>
#include <memory>
#include <string_view>

class GumballMachine;   // forward declaration -- breaks the State <-> Machine cycle

class State {
public:
    virtual ~State() = default;
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter()  = 0;
    virtual void turnCrank()     = 0;
    virtual void dispense()      = 0;
    virtual std::string_view getStateName() const = 0;
protected:
    State() = default;
};

class NoQuarterState final : public State {
    GumballMachine& machine_;
public:
    explicit NoQuarterState(GumballMachine& m) : machine_(m) {}
    void insertQuarter() override;
    void ejectQuarter()  override { std::cout << "You haven't inserted a quarter\n"; }
    void turnCrank()     override { std::cout << "You turned, but there's no quarter\n"; }
    void dispense()      override { std::cout << "You need to pay first\n"; }
    std::string_view getStateName() const override { return "NoQuarter"; }
};

class HasQuarterState final : public State {
    GumballMachine& machine_;
public:
    explicit HasQuarterState(GumballMachine& m) : machine_(m) {}
    void insertQuarter() override { std::cout << "You can't insert another quarter\n"; }
    void ejectQuarter()  override;
    void turnCrank()     override;
    void dispense()      override { std::cout << "No gumball dispensed\n"; }
    std::string_view getStateName() const override { return "HasQuarter"; }
};

class SoldState final : public State {
    GumballMachine& machine_;
public:
    explicit SoldState(GumballMachine& m) : machine_(m) {}
    void insertQuarter() override { std::cout << "Please wait, we're already giving you a gumball\n"; }
    void ejectQuarter()  override { std::cout << "Sorry, you already turned the crank\n"; }
    void turnCrank()     override { std::cout << "Turning twice doesn't get you another gumball\n"; }
    void dispense()      override;
    std::string_view getStateName() const override { return "Sold"; }
};

class SoldOutState final : public State {
public:
    SoldOutState() = default;   // no back-reference: SoldOut causes no transitions
    void insertQuarter() override { std::cout << "Sorry, we're sold out\n"; }
    void ejectQuarter()  override { std::cout << "You can't eject, you haven't inserted a quarter yet\n"; }
    void turnCrank()     override { std::cout << "You turned, but there are no gumballs\n"; }
    void dispense()      override { std::cout << "No gumball dispensed\n"; }
    std::string_view getStateName() const override { return "SoldOut"; }
};

class GumballMachine {
    std::unique_ptr<State> soldOutState_, noQuarterState_, hasQuarterState_, soldState_;
    State* state_{nullptr};
    int count_{0};
public:
    explicit GumballMachine(int numberGumballs)
        : soldOutState_(std::make_unique<SoldOutState>())
        , noQuarterState_(std::make_unique<NoQuarterState>(*this))
        , hasQuarterState_(std::make_unique<HasQuarterState>(*this))
        , soldState_(std::make_unique<SoldState>(*this))
        , count_(numberGumballs)
    { state_ = (numberGumballs > 0) ? noQuarterState_.get() : soldOutState_.get(); }

    void insertQuarter() { state_->insertQuarter(); }
    void ejectQuarter()  { state_->ejectQuarter();  }
    void turnCrank() {
        state_->turnCrank();       // may change state_ ...
        state_->dispense();        // ... so this runs on the (possibly new) state
    }
    void setState(State* s) { state_ = s; }
    void releaseBall() { std::cout << "A gumball comes rolling out...\n"; if (count_ > 0) --count_; }
    int    getCount()          const noexcept { return count_; }
    State* getNoQuarterState() const noexcept { return noQuarterState_.get(); }
    State* getHasQuarterState()const noexcept { return hasQuarterState_.get(); }
    State* getSoldState()      const noexcept { return soldState_.get(); }
    State* getSoldOutState()   const noexcept { return soldOutState_.get(); }
};

void NoQuarterState::insertQuarter() {
    std::cout << "You inserted a quarter\n";
    machine_.setState(machine_.getHasQuarterState());
}
void HasQuarterState::ejectQuarter() {
    std::cout << "Quarter returned\n";
    machine_.setState(machine_.getNoQuarterState());
}
void HasQuarterState::turnCrank() {
    std::cout << "You turned...\n";
    machine_.setState(machine_.getSoldState());
}
void SoldState::dispense() {
    machine_.releaseBall();
    if (machine_.getCount() > 0) machine_.setState(machine_.getNoQuarterState());
    else { std::cout << "Oops, out of gumballs!\n"; machine_.setState(machine_.getSoldOutState()); }
}

int main() {
    GumballMachine machine(2);
    machine.insertQuarter();
    machine.turnCrank();
    std::cout << "---\n";
    machine.insertQuarter();
    machine.turnCrank();
}
