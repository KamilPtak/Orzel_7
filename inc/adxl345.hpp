#include <stdint.h>
#include <vector>
#pragma once

class ADXL { 
    private:
        std::vector<int> accel;
        uint8_t pin;
    public:
        ADXL();
};