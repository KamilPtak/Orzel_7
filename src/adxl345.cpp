#include "adxl345.hpp"

ADXL::ADXL() {
    for(auto elem: accel) {
        elem = 0;
    }
}