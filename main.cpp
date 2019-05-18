#include "mbed.h"
//#include <ros.h>
//#include "library/ScrpSlave.hpp"
//#include "library/RotaryInc.hpp"
//#include "library/GY521.hpp"

/*USBでPCにつなぐポートと、基板上でRasPiとつなぐポートを同時に開く。
 *RedePinの有り無しの選択、ポートを一つだけ開くことも可。
 *以下から選択。
 *ScrpSlave(PinName TX1,PinName RX1,uint32_t addr);//RedePinなし、１ポート
 *ScrpSlave(PinName TX1,PinName RX1,PinName REDE1,uint32_t addr);//RedePinあり、１ポート
 *ScrpSlave(PinName TX1,PinName RX1,PinName TX2,PinName RX2,uint32_t addr);//RedePinなし、２ポート
 *ScrpSlave(PinName TX1,PinName RX1,PinName REDE1,PinName TX2,PinName RX2,uint32_t addr);//RedePinあり、１ポート＋RedePinなし、１ポート
 */
//ScrpSlave slave(PC_12,PD_2,PH_1,SERIAL_TX,SERIAL_RX,0x0807ffff);

/*ロータリーエンコーダーを使う。
 *速度計測は、タイヤの円周とロリコンの分解能を指定した場合に有効になる。
 *RotaryInc(PinName pinA, PinName pinB,double circumference,int Resolution,int mode = 0);//速度計測有効
 *RotaryInc(PinName pinA, PinName pinB,int mode = 0);//速度計測無効
 */
//RotaryInc rotary(PA_6,PA_7,2 * 50.8 * M_PI,200);

/*GY521を使う。
 *I2Cオブジェクトを渡す
 *GY521(I2C &i2c,int bit = 2,int calibration = 1000,double user_reg = 1.0);
 */
//I2C i2c(PB_3,PB_10);
//GY521 gyro(i2c);

int main(){
    //setup
    while(true){
        //loop
    }
}