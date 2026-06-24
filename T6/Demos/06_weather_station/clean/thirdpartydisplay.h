#ifndef THIRDPARTYDISPLAY_H
#define THIRDPARTYDISPLAY_H
#include <iostream>
#include "observer.h"
#include "displayelement.h"
#include "weatherdata.h"

// A brand-new display type, added LATER. Note: WeatherData was not edited.
class ThirdPartyDisplay : public Observer, public DisplayElement {
    float temperature{0.0f};
    float humidity{0.0f};
    float pressure{0.0f};
    WeatherData* weatherData;
public:
    explicit ThirdPartyDisplay(WeatherData* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }
    void update() override {
        temperature = weatherData->getTemperature();
        humidity    = weatherData->getHumidity();
        pressure    = weatherData->getPressure();
        display();
    }
    void display() const override {
        std::cout << "ThirdParty: T=" << temperature
                  << " H=" << humidity << " P=" << pressure << "\n";
    }
};
#endif 
