#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

// ---- Observer ------------------------------------------------------------
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
protected:
    Observer() = default;
};

class Subject {
    std::vector<Observer*> observers_;                 // NON-owning
public:
    virtual ~Subject() = default;
    void addObserver(Observer* o) {
        if (o && std::find(observers_.begin(), observers_.end(), o) == observers_.end())
            observers_.push_back(o);
    }
    void removeObserver(Observer* o) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), o), observers_.end());
    }
    void notifyObservers() { for (auto* o : observers_) o->update(); }
protected:
    Subject() = default;
};

// ---- Strategy ------------------------------------------------------------
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

// ---- Model ---------------------------------------------------------------
class Student : public Subject {
    std::string rollNo_, name_;
    double score_;
    std::shared_ptr<GradeStrategy> gradeStrategy_;
public:
    Student(std::string rollNo, std::string name, double score, std::shared_ptr<GradeStrategy> gs)
        : rollNo_(std::move(rollNo)), name_(std::move(name)), score_(score), gradeStrategy_(std::move(gs)) {}
    void setScore(double s) { score_ = s; notifyObservers(); }        // every setter notifies
    std::string_view getName()   const { return name_; }
    std::string_view getRollNo() const { return rollNo_; }
    char getGrade() const { return gradeStrategy_->calculateGrade(score_); }
};

// ---- View ----------------------------------------------------------------
class StudentView {
public:
    void printStudentDetails(std::string_view name, std::string_view rollNo, char grade) const {
        std::cout << "Student:\nName: " << name << "\nRoll No: " << rollNo << "\nGrade: " << grade << '\n';
    }
};

// ---- Controller (an Observer) --------------------------------------------
class StudentController final : public Observer {
    std::shared_ptr<Student> model_;
    StudentView view_;
public:
    StudentController(std::shared_ptr<Student> model, StudentView view)
        : model_(std::move(model)), view_(std::move(view)) { model_->addObserver(this); }
    ~StudentController() override { if (model_) model_->removeObserver(this); }
    StudentController(const StudentController&) = delete;
    StudentController& operator=(const StudentController&) = delete;
    void setStudentScore(double s) { model_->setScore(s); }          // input -> model
    void updateView() const { view_.printStudentDetails(model_->getName(), model_->getRollNo(), model_->getGrade()); }
    void update() override { updateView(); }                         // model changed -> refresh
};

// ---- Composite (a group that is ALSO an Observer) ------------------------
class CompositeStudentGroup final : public Observer {
    std::vector<std::shared_ptr<Student>> students_;
    std::string groupName_;
public:
    explicit CompositeStudentGroup(std::string name) : groupName_(std::move(name)) {}
    void addStudent(std::shared_ptr<Student> s) {
        if (!s) return;
        s->addObserver(this);                                        // the group observes each student
        students_.push_back(std::move(s));
    }
    void update() override {
        std::cout << "Group " << groupName_ << " updated.\n";
        for (const auto& s : students_)
            std::cout << "Student " << s->getName() << " (Roll No: " << s->getRollNo()
                      << ") has new grade: " << s->getGrade() << '\n';
    }
};

int main() {
    auto strategy = std::make_shared<SimpleGradeStrategy>();
    auto robert   = std::make_shared<Student>("R001", "Robert", 85.0, strategy);

    StudentController controller(robert, StudentView{});   // registers as observer #1
    CompositeStudentGroup cs101("CS101");
    cs101.addStudent(robert);                              // registers as observer #2

    std::cout << "== initial ==\n";
    controller.updateView();

    std::cout << "== controller sets score to 95 ==\n";
    controller.setStudentScore(95.0);                      // ONE setter -> BOTH observers fire
}
