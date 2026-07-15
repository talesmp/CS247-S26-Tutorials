#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

// Minimal Observer slice to expose the LIFETIME hazard of non-owning Observer*.

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
protected:
    Observer() = default;
};

class Subject {
    std::vector<Observer*> observers_;                 // NON-owning raw pointers
public:
    virtual ~Subject() = default;
    void addObserver(Observer* o) {
        if (o && std::find(observers_.begin(), observers_.end(), o) == observers_.end())
            observers_.push_back(o);
    }
    void removeObserver(Observer* o) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), o), observers_.end());
    }
    void notifyObservers() { for (auto* o : observers_) o->update(); }  // deref each observer
protected:
    Subject() = default;
};

class GradeStrategy {
public:
    virtual ~GradeStrategy() = default;
    virtual char calculateGrade(double) const = 0;
protected:
    GradeStrategy() = default;
};
class SimpleGradeStrategy final : public GradeStrategy {
public:
    char calculateGrade(double s) const override {
        if (s >= 90) return 'A'; if (s >= 80) return 'B';
        if (s >= 70) return 'C'; if (s >= 60) return 'D'; return 'F';
    }
};

class Student : public Subject {
    std::string rollNo_, name_;
    double score_;
    std::shared_ptr<GradeStrategy> gradeStrategy_;
public:
    Student(std::string rollNo, std::string name, double score, std::shared_ptr<GradeStrategy> gs)
        : rollNo_(std::move(rollNo)), name_(std::move(name)), score_(score), gradeStrategy_(std::move(gs)) {}
    void setScore(double s) { score_ = s; notifyObservers(); }
    std::string_view getName()   const { return name_; }
    std::string_view getRollNo() const { return rollNo_; }
    char getGrade() const { return gradeStrategy_->calculateGrade(score_); }
};

class CompositeStudentGroup final : public Observer {
    std::vector<std::shared_ptr<Student>> students_;
    std::string groupName_;
public:
    explicit CompositeStudentGroup(std::string name) : groupName_(std::move(name)) {}
    void addStudent(std::shared_ptr<Student> s) {
        if (!s) return;
        s->addObserver(this);              // registers this group's ADDRESS with the student
        students_.push_back(std::move(s));
    }
    void update() override {
        std::cout << "Group " << groupName_ << " updated.\n";
    }
    // THE BUG: no destructor. Unlike StudentController, this group never calls removeObserver(this). 
    // If the group dies before the student, the student's observer list keeps a DANGLING pointer to freed memory.
};

int main() {
    auto strategy = std::make_shared<SimpleGradeStrategy>();
    auto robert   = std::make_shared<Student>("R001", "Robert", 85.0, strategy);

    auto* cs101 = new CompositeStudentGroup("CS101");
    cs101->addStudent(robert);     // robert now holds Observer* -> cs101
    delete cs101;                  // freed -- but NEVER deregistered from robert

    // notifyObservers() walks robert's list and calls update() on the freed group:
    robert->setScore(95.0);        // heap-use-after-free (undefined behavior)
    std::cout << "(if you see this with no ASan report, UB just happened to not crash)\n";
}
