#include "weatherdata.h"
#include <algorithm>

void WeatherData::registerObserver(Observer* o) {
    if (o) { observers.push_back(o); }
}

void WeatherData::removeObserver(Observer* o) {
    if (auto it = std::find(observers.begin(), observers.end(), o);  
        it != observers.end()) {
        observers.erase(it);
    }
}

void WeatherData::notifyObservers() {
    for (auto* observer : observers) {
        observer->update();                     
    }
}

void WeatherData::setMeasurements(float t, float h, float p) {
    temperature = t;
    humidity    = h;
    pressure    = p;
    notifyObservers();                          
}
