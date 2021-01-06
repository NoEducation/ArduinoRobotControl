#include <Servo.h>
#include <Arduino.h>

namespace obstacle_cheker_ultrasonic{
    unsigned long val;
    unsigned long preMillis;
    int Echo = A4;  
    int Trig = A5; 
    int rightDistance = 0;
    int leftDistance = 0;
    int middleDistance = 0;

    Servo myservo;     

    void setupObstacleChekerUltrasonic(){
        myservo.attach(3,700,2400); 
        pinMode(Echo, INPUT);    
        pinMode(Trig, OUTPUT);  
    }

    int distanceTest() {
        digitalWrite(Trig, LOW);   
        delayMicroseconds(20);
        digitalWrite(Trig, HIGH);  
        delayMicroseconds(20);
        digitalWrite(Trig, LOW);   
        float Fdistance = pulseIn(Echo, HIGH);  
        Fdistance= Fdistance / 58;       
        return (int)Fdistance;
    }  

}