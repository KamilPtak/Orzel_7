#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "MPU6050.h"

#define G 9.81;
float a[3], g[3];
float X=0, Y=0;
void getPosition(float deltaT);
float integral(float integratedValue, float timeStep);
int main()
{
    MPU6050 * mpu = new MPU6050(0x68);

    // float a[3], g[3];
    float aRaw[3], gRaw[3];
    float aOff[3], gOff[3];
    float *angle;
    char aAxis[3] = {'X', 'Y', 'Z'};
    char gAxis[3] = {'R', 'P', 'Y'};
    bool isFirtIteration = true;
    std::chrono::high_resolution_clock::time_point start, stop;
    std::chrono::duration<float> duration;

    while(1)
    {
        if(isFirtIteration)
        {
            isFirtIteration = false;
            start = std::chrono::high_resolution_clock::now();
        }
        else
        {
            stop = std::chrono::high_resolution_clock::now();
            duration = stop - start;
            getPosition(duration.count());
            // getPosition(duration.count(), sensor->getAccelX(), sensor->getAccelY(), sensor->getAngleX());
            //pid->PIDcalculateOutput(WARTOSC_W_TYM_PRZYPADKU - sensor->getAngleX(), duration.count());
            start = std::chrono::high_resolution_clock::now();
        }
        mpu->getAccelRaw(aRaw, aRaw+1, aRaw+2);
        mpu->getAccel(a, a+1, a+2);
        mpu->getGyroRaw(gRaw, gRaw+1, gRaw+2);
        // mpu->getOffsets(aOff, aOff+1, aOff+2, gOff, gOff+1, gOff+2);
        // for(int i = 0; i<3; i++)
        // {
        //     std::cout<<"Axis raw "<<aAxis[i]<<": "<<aRaw[i]<<", scaled: "<<a[i]<<std::endl;
        // }
        // for(int i = 0; i<3; i++)
        // {
        //     std::cout<<"Axis raw"<<gAxis[i]<<": "<<gRaw[i]<<" , scaled: "<<g[i]<<std::endl;
        // }
        // std::cout<<"Accel offsets "<<aOff[0]<<", "<<aOff[1]<<", "<<aOff[2]<<std::endl;
        // std::cout<<"Gyro offsets "<<gOff[0]<<", "<<gOff[1]<<", "<<gOff[2]<<std::endl;
        // for(int i = 0; i<3; i++)
        // {
        //     mpu->getAngle(i, angle);
        //     std::cout<<"Angle "<<gAxis[i]<<": "<<*angle<<std::endl;
        // }
        // std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
void getPosition(float deltaT)//sprawdzic jednostki !!!!!
{
    float accelX = a[0]*G;
    float accelY = a[1]*G;
    float angle = g[2]*deltaT; //yaw
    float tempX = accelX * cos(angle) + accelY * sin(angle);
    float tempY = accelX * cos(angle) - accelY * sin(angle);
    for(int i = 0; i<2; i++)
    {
        tempX += integral(tempX, deltaT);
        tempY += integral(tempY, deltaT);
    }
    X+=tempX;
    Y+=tempY;
    std::cout<<"X: "<<X<<std::endl;
    std::cout<<"Y: "<<Y<<std::endl;
}
float integral(float integratedValue, float timeStep)
{
    return integratedValue*timeStep;
}