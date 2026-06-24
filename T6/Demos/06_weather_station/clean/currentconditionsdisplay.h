#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include <iostream>
#include "observer.h"
#include "displayelement.h"
#include "weatherdata.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement {
    float temperature{0.0f};
    float humidity{0.0f};
    WeatherData* weatherData;                  
public:
    explicit CurrentConditionsDisplay(WeatherData* wd) : weatherData(wd) {
        weatherData->registerObserver(this);     
    }
    void update() override {
        temperature = weatherData->getTemperature();  
        humidity    = weatherData->getHumidity();
        display();
    }
    void display() const override {
        std::cout << "Current conditions: " << temperature
                  << "F and " << humidity << "% humidity\n";
    }
};
#endif
