#include <iostream>
#include "MPU6050.h"

int main()
{
    MPU6050 * mpu = new MPU6050(0x68);

    float a[3], g[3];
    float aRaw[3], gRaw[3];
    float aOff[3], gOff[3];
    float *angle;
    char aAxis[3] = {'X', 'Y', 'Z'};
    char gAxis[3] = {'R', 'P', 'Y'};

    while(1)
    {
        mpu->getAccelRaw(aRaw, aRaw+1, aRaw+2);
        mpu->getAccel(a, a+1, a+2);
        mpu->getGyroRaw(gRaw, gRaw+1, gRaw+2);
        mpu->getOffsets(aOff, aOff+1, aOff+2, gOff, gOff+1, gOff+2);
        for(int i = 0; i<3; i++)
        {
            std::cout<<"Axis raw "<<aAxis[i]<<": "<<aRaw[i]<<", scaled: "<<a[i]<<std::endl;
        }
        for(int i = 0; i<3; i++)
        {
            std::cout<<"Axis raw"<<gAxis[i]<<": "<<gRaw[i]<<" , scaled: "<<g[i]<<std::endl;
        }
        std::cout<<"Accel offsets "<<aOff[0]<<", "<<aOff[1]<<", "<<aOff[2]<<std::endl;
        std::cout<<"Gyro offsets "<<gOff[0]<<", "<<gOff[1]<<", "<<gOff[2]<<std::endl;
        for(int i = 0; i<3; i++)
        {
            mpu->getAngle(i, angle);
            std::cout<<"Angle "<<gAxis[i]<<": "<<*angle<<std::endl;
        }
    }

    return 0;
}