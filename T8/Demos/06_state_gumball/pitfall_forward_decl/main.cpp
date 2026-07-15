#include <iostream>
#include <memory>
#include <string_view>

class GumballMachine;   // forward declaration: names the type, but it is INCOMPLETE

class State {
public:
    virtual ~State() = default;
    virtual void insertQuarter() = 0;
    virtual void turnCrank()     = 0;
    virtual std::string_view getStateName() const = 0;
protected:
    State() = default;
};

class NoQuarterState final : public State {
    GumballMachine& machine_;
public:
    explicit NoQuarterState(GumballMachine& m) : machine_(m) {}

    // THE PITFALL: defining the body HERE, inline, feels natural -- but at this point GumballMachine is only forward-declared (incomplete). 
    // You cannot call members on an incomplete type, so machine_.setState(...) will not compile:
    //     error: member access into incomplete type 'GumballMachine'
    // FIX: only DECLARE the method here; 
    // DEFINE it after GumballMachine's full definition is visible (see clean/, which does exactly that).
    void insertQuarter() override {
        std::cout << "You inserted a quarter\n";
        machine_.setState(machine_.getHasQuarterState());
    }
    void turnCrank() override { std::cout << "You turned, but there's no quarter\n"; }
    std::string_view getStateName() const override { return "NoQuarter"; }
};

class GumballMachine {
    std::unique_ptr<State> noQuarterState_, hasQuarterState_;
    State* state_{nullptr};
public:
    GumballMachine()
        : noQuarterState_(std::make_unique<NoQuarterState>(*this))
    { state_ = noQuarterState_.get(); }
    void setState(State* s) { state_ = s; }
    State* getHasQuarterState() const noexcept { return hasQuarterState_.get(); }
    void insertQuarter() { state_->insertQuarter(); }
};

int main() {
    GumballMachine machine;
    machine.insertQuarter();
}
