class Subject {
public:
    virtual ~Subject() = default;
    virtual void notifyObservers() = 0;
};

