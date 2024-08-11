#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int lowerLimit, int upperLimit) {
    return rand() % (upperLimit - lowerLimit + 1) + (lowerLimit);
}