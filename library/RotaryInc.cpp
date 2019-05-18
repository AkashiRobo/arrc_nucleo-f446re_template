#include "RotaryInc.hpp"

RotaryInc::RotaryInc(PinName pinA, PinName pinB,int mode):mode(mode){
    measur = false;
    init(pinA,pinB);
}

RotaryInc::RotaryInc(PinName pinA,PinName pinB,double circumference,int Resolution,int mode)
    :mode(mode),Resolution(Resolution),circumference(circumference){
    measur = true;
    zero();
    init(pinA,pinB);
}

void RotaryInc::init(PinName pinA,PinName pinB){
    A = new InterruptIn(pinA,PullUp);
    B = new InterruptIn(pinB,PullUp);
    A->rise(callback(this,&RotaryInc::riseA));
        
    if(mode == 2){
        A->fall(callback(this,&RotaryInc::fallA));
    }else if(mode == 4){
        A->fall(callback(this,&RotaryInc::fallA));
        B->rise(callback(this,&RotaryInc::riseB));
        B->fall(callback(this,&RotaryInc::fallB));
    }else{
        mode = 1;
    }
}

void RotaryInc::zero(){
    time.stop();
    time.reset();
    startflag = false;
    flag = false;
    last[0] = pulse;
    speed = 0;
    count = 0;
    sum = 0;
    now = 0;
}

void RotaryInc::calcu(){
    if(!startflag){
        time.start();
        startflag = true;
        last[0] = pulse;
        pre_t[0] = 0;
        count = 1;
    }else if(flag){
        now = time.read();
        time.reset();
        sum -= pre_t[count];
        pre_t[count] = now;
        sum += now;
        speed = (double)(pulse - last[count]) / sum;
        last[count] = pulse;
        if(count < 19){
            count++;
        }else{
            count = 0;
        }
    }else{
        now = time.read();
        time.reset();
        pre_t[count] = now;
        sum += now;
        speed = (double)(pulse - last[0]) / sum;
        last[count] = pulse;
        count++;
        if(count > 19){
            count = 0;
            flag = true;
        }
    }
}

void RotaryInc::riseA(){
    B->read() ? pulse-- : pulse++;
    if(measur)calcu();    
}

void RotaryInc::fallA(){
    B->read() ? pulse++ : pulse--;
    if(measur)calcu();
}

void RotaryInc::riseB(){
    A->read() ? pulse++ : pulse--;
    if(measur)calcu();
}

void RotaryInc::fallB(){
    A->read() ? pulse-- : pulse++;
    if(measur)calcu();
}

long long RotaryInc::get(){
    return pulse;
}

double RotaryInc::getSpeed(){
    if(!measur)return 0;
    if(time.read_ms() > 150){
        zero();
    }
    return speed / Resolution / mode * circumference;
}

int RotaryInc::diff(){
    int diff = pulse - prev;
    prev = pulse;
    return diff;
}
    
void RotaryInc::reset(){
    pulse = 0;
    prev = 0;
    if(measur)zero();
}

RotaryInc::~RotaryInc(){
    A->disable_irq();
    B->disable_irq();
    delete A;
    delete B;
}