//    The direction of the car's movement
//  ENA   ENB   IN1   IN2   IN3   IN4   Description  
//  HIGH  HIGH  HIGH  LOW   LOW   HIGH  Car is runing forward
//  HIGH  HIGH  LOW   HIGH  HIGH  LOW   Car is runing back
//  HIGH  HIGH  LOW   HIGH  LOW   HIGH  Car is turning left
//  HIGH  HIGH  HIGH  LOW   HIGH  LOW   Car is turning right
//  HIGH  HIGH  LOW   LOW   LOW   LOW   Car is stoped
//  HIGH  HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
//  LOW   LOW   N/A   N/A   N/A   N/A   Car is stoped
//  
// the setup function runs once when you press reset or power the board

#include <Arduino.h>

namespace movement {
    //define L298n module IO Pin
    #define ENA 5 // left enable
    #define ENB 6 // right enable
    #define IN1 7 // left front
    #define IN2 8 // left back
    #define IN3 9 // right back
    #define IN4 11 // right front

    int carSpeed = 125;
    int factor = 25;
    int delay = 20;

    // void setDelay(){
    //     delay()
    // }


    void setCarSpeed(int newSpeed){
        if(newSpeed > 0){
            carSpeed = newSpeed;
        }
    }

    void reduceSpeed(){
        if( (carSpeed - factor) > 50){
            carSpeed-=factor;
            analogWrite(ENA, carSpeed);
            analogWrite(ENB, carSpeed);
        }
    }

    void increaseSpeed(){
        if ((carSpeed + factor) < 255){
            carSpeed+=factor;
            analogWrite(ENA, carSpeed);
            analogWrite(ENB, carSpeed);
        }
    }

    void setupMovement(){
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(IN4, OUTPUT);
        pinMode(ENA, OUTPUT);
        pinMode(ENB, OUTPUT);
        setCarSpeed(carSpeed);
    }


    void forward(){ 
        analogWrite(ENA, carSpeed);
        analogWrite(ENB, carSpeed);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        Serial.println("Forward");
    }

    void back() {
        analogWrite(ENA, carSpeed);
        analogWrite(ENB, carSpeed);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        Serial.println("Back");
    }

    void left() {
        analogWrite(ENA, carSpeed);
        analogWrite(ENB, carSpeed);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH); 
        Serial.println("Left");
    }

    void right() {
        analogWrite(ENA, carSpeed);
        analogWrite(ENB, carSpeed);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        Serial.println("Right");
    }

    void stop() {
        digitalWrite(ENA, LOW);
        digitalWrite(ENB, LOW);
        Serial.println("Stop!");
    } 
}
