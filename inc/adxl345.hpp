#include <vector>

class ADXL { 
    private:
        std::vector<int> accel;
        uint8_t pin;
    public:
        ADXL();
};