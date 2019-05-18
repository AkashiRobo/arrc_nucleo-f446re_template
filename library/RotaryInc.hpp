#pragma once
#include "mbed.h"
#ifndef M_PI
#define M_PI 3.14159265358979
#endif

class RotaryInc{
public:
    RotaryInc(PinName userA, PinName userB,double circumference,int Resolution,int mode = 0);//速度計測有効
    RotaryInc(PinName userA, PinName userB,int mode = 0);//速度計測無効
    ~RotaryInc();
    long long get();
    double getSpeed();
    void reset(); 
    int diff();
private:
    InterruptIn *A,*B;
    Timer time;
    long long pulse;
    long long last[20];
    long long prev;
    int spend;
    int count;
    int mode;
    int Resolution;
    double now;
    double sum;
    double pre_t[20];
    double speed;
    double circumference;
    bool measur;
    bool startflag;
    bool flag;
    void init(PinName,PinName);
    void riseA(void);
    void riseB(void);
    void fallA(void);
    void fallB(void);
    void calcu(void);
    void zero(void);
};