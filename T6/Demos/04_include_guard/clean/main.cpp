#include "subject.h"      
#include "weatherdata.h"    

int main() {
    WeatherData wd;
    wd.notifyObservers();
    return 0;
}

// Q4.1. Include guard
//
// subject.h has NO include guard and is reached by two include paths (directly, and via weatherdata.h), as shown above. You build it.
// What happens?
//   a) it compiles and runs fine
//   b) compiler error: redefinition of 'Subject'
//   c) a linker error
//   d) a runtime crash
