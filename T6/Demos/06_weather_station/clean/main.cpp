#include "weatherdata.h"
#include "currentconditionsdisplay.h"
#include "thirdpartydisplay.h"

int main() {
    WeatherData weatherData;

    CurrentConditionsDisplay current(&weatherData);
    ThirdPartyDisplay        thirdParty(&weatherData);  

    weatherData.setMeasurements(80, 65, 30.4f);
    weatherData.setMeasurements(82, 70, 29.2f);
    return 0;
}

// Q6.1. Observer broadcast
//
// Two displays are registered with one WeatherData, then setMeasurements is called twice, as shown above.
// What does it print?
//   a) both Current conditions lines, then both ThirdParty lines (each display batched)
//   b) Current conditions + ThirdParty for round 1, then both again for round 2
//   c) only the last measurement, shown once
//   d) nothing — WeatherData has no displays hard-coded into it
