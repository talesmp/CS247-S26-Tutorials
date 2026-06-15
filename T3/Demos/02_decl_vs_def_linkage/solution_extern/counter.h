#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

// FIX #2 (works in every standard). The header DECLARES only (extern);
// exactly ONE .cpp DEFINES the variable. External linkage, one shared copy.
extern int counter;

void show();

#endif // COUNTER_H
