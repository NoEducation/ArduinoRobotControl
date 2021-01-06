#include <Arduino.h>
#include <IRremote.h>
#include <Servo.h>
#include "movement.h"
#include "infrared.h"
#include "obstacleCheckerUltrasonic.h"

void setup() {
  Serial.begin(9600);//open serial and set the baudrate
  movement::setupMovement();
  infrared::setupInfrared();
  obstacle_cheker_ultrasonic::setupObstacleChekerUltrasonic();
}

//Repeat execution
void loop() {
  auto infarared_response = infrared::checkInfraredSignal();

  if(infarared_response.isResponse){
      switch(infarared_response.code){
        case infrared::down:{
          movement::back();
          break;
        }
        case infrared::left:{
          movement::left();
          break;
        }
        case infrared::right:{
          movement::right();
          break;
        }
        case infrared::forward:{
          movement::forward();
          break;
        }
        case infrared::stop:{
          movement::stop();
          break;
        }
        case infrared::hash:{
          movement::increaseSpeed();
          break;
        }
        case infrared::star:{
          movement::reduceSpeed();
          break;
        }
        case infrared::key_1:{
          //TODO.DA 
          break;
        }
      }
  }
}
