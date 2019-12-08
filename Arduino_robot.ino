#include "Arduino_robot.h" 

int right_pulse = 0;
int prev_right_pulse = 0;
int left_pulse = 0;
int prev_left_pulse = 0;
int right_odo_counter = 0;
int left_odo_counter = 0;

 
void setup() {
 

 // setup right wheel pins 
  pinMode(RIGHT_ODOMETRY, INPUT);  // make pin 9 an input (odometry)  
  pinMode(RIGHT_PWMF,OUTPUT); // make pin 11 an output (PWM forward)
  pinMode(RIGHT_PWMR,OUTPUT); // make pin 10 an output (PWM reverse)
    
  // setup left wheel pins 
  pinMode(LEFT_ODOMETRY,INPUT);  // make pin 2 an input  (odometry)
  pinMode(LEFT_PWMF,OUTPUT); // make pin 3 an output (PWM forward)
  pinMode(LEFT_PWMR,OUTPUT); // make pin 4 an output (PWM reverse)
   
  Serial.begin(9600);
  
  TCCR2B=(TCCR2B&0xF8) | 1; //set PWM frequency to 3906 Hz for pin 3 (and 11)
  

}

void loop() {
  // put your main code here, to run repeatedly:
 
  analogWrite(RIGHT_PWMF,120); //do 50% PWM on pin 3 at the frequency set in TCCR2B(right wheel)
  analogWrite(LEFT_PWMF,120);  //do 50% PWM on pin 3 at the frequency set in TCCR2B(left wheel)

  right_pulse= digitalRead( RIGHT_ODOMETRY); 
  left_pulse= digitalRead( LEFT_ODOMETRY); 
     
     
 if(right_pulse==0 && prev_right_pulse== 1 )  //the point where high goes to low(end of the pulse) 
  {
    right_odo_counter = right_odo_counter + 1;
    Serial.print("Right counter: ");
    Serial.println(right_odo_counter);
    Serial.print("right distance: ");
    Serial.println(calculateDistance(right_odo_counter));
  }     
  prev_right_pulse=right_pulse;
  delay(2); 
    if(left_pulse==0 && prev_left_pulse== 1 )  //the point where high goes to low(end of the pulse) 
  {
    left_odo_counter = left_odo_counter + 1;
   Serial.print("Left counter: ");
    Serial.println(left_odo_counter);
    Serial.print("Left distance: ");
    Serial.println(calculateDistance(left_odo_counter));
  }     
  prev_left_pulse=left_pulse;
    
  delay(2);
}

int calculateDistance(int pulses)
{
 return int(pulses*PULSES_2_MM);
}
