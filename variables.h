#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>

const int MAX_POP = 1000;

enum SexType{
    MALE,
    FEMALE
};

namespace Names{
    enum MALE_NAMES{
        M1,
        M2,
        M3,
        M4
    };

    enum FEMALE_NAMES{
        F1,
        F2,
        F3,
        F4
    };
};
enum FurType{
    WHITE,
    BROWN,
    BLACK,
    SPOTTED
};

#endif // VARIABLES_H
