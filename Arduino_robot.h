// Left wheel controlled by pins 2,3,5
// Right wheel cpntrolled by pins 9,11,10


#define RIGHT_ODOMETRY 9
#define RIGHT_PWMF 11
#define RIGHT_PWMR 10
//#define RIGHT_ALARMF A2
//#define RIGHT_ALARMR A3


#define LEFT_ODOMETRY 2
#define LEFT_PWMF 3
#define LEFT_PWMR 5
//#define LEFT_ALARMF A0
//#define LEFT_ALARMR A1



#define GEAR_RATIO  82
#define DIAMETER 150
#define PULSES_2_MM (DIAMETER * 3.1415) / GEAR_RATIO

int calculateDistance(int pulses);
