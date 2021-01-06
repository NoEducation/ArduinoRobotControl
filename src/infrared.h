// INFRARED SETUP
// ---------------------------------------

#include <IRremote.h>

namespace infrared {
    #define F 16736925  // FORWARD
    #define B 16754775  // BACK
    #define L 16720605  // LEFT
    #define R 16761405  // RIGHT
    #define S 16712445  // STOP
    #define UNKNOWN_F 5316027     // FORWARD
    #define UNKNOWN_B 2747854299  // BACK
    #define UNKNOWN_L 1386468383  // LEFT
    #define UNKNOWN_R 553536955   // RIGHT
    #define UNKNOWN_S 3622325019  // STOP
    #define KEY1 16738455
    #define KEY2 16750695
    #define KEY3 16756815
    #define KEY4 16724175
    #define KEY5 16718055
    #define KEY6 16743045
    #define KEY7 16716015
    #define KEY8 16726215
    #define KEY9 16734885
    #define KEY0 16730805
    #define KEY_STAR 16728765
    #define KEY_HASH 16732845
    #define RECV_PIN  12

    enum response_code{
        left = L,
        right = R,
        down = B,
        stop = S,
        forward = F,
        key_1 = KEY1,
        key_2 = KEY2,
        key_3 = KEY3,
        key_4 = KEY4,
        key_5 = KEY5,
        key_6 = KEY6,
        key_7 = KEY7,
        key_8 = KEY8,
        key_9 = KEY9,
        key_0 = KEY0,
        star = KEY_STAR,
        hash = KEY_HASH
    };

    struct infrared_response
    {
        response_code code;
        bool isResponse;

        infrared_response(){
            isResponse = false;
        }
    };
    

    IRrecv irrecv(RECV_PIN);
    decode_results results;

    void setupInfrared(){
        irrecv.enableIRIn();  
    }

    infrared_response checkInfraredSignal(){
        infrared_response response = infrared_response();

        if(irrecv.decode(&results))
        {
            auto preMillis = millis();
            auto signal = results.value;
            Serial.println(signal);
            irrecv.resume();
            response.code = (response_code)signal;
            response.isResponse = true;
        }

        return response;
    }
}
