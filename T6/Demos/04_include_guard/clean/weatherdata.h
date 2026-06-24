#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include "subject.h"
class WeatherData : public Subject {
public:
    void notifyObservers() override {}
};
#endif 
