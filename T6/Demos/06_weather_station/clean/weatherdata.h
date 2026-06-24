#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include "subject.h"
#include "observer.h"
#include <vector>
class WeatherData : public Subject {          
    std::vector<Observer*> observers;        
    float temperature{0.0f};
    float humidity{0.0f};
    float pressure{0.0f};
public:
    void registerObserver(Observer* o) override;
    void removeObserver(Observer* o)   override;
    void notifyObservers()             override;
    float getTemperature() const { return temperature; }
    float getHumidity()    const { return humidity; }
    float getPressure()    const { return pressure; }
    void setMeasurements(float t, float h, float p);
};
#endif 
