//
// Created by Pavi on 2016-10-22.
//
#include <iostream>
#include "Selector.h"
#include "Encoder.h"
#include "Setup.h"

void Selector::print(){
    std::cout << "hi";
}

int Selector::mainLoop(Setup mainModule){
    bool run = true;
    //boolean true is weather false is current
    bool next = true;
    char* message;
    char* encodedMessage;
    Encoder msgEncode;
    int messagesSent = 0;

   // while (run){
        if (messagesSent > 50){
            mainModule.testHardware();
        }
       /* //emergency situation
        if (mainModule.weather.GetPriority() && mainModule.current.GetPriority()) {
            if (next){
                message = mainModule.weather.dequeue();
            }else{
                message = mainModule.current.dequeue();
            }
            next = !next;
        }else if (mainModule.weather.GetPriority()){
            message = mainModule.weather.dequeue();
        }else if (mainModule.current.GetPriority()){
            message = mainModule.current.dequeue();
            //no emergencies, broadcast weather next
        }else if (next){
            message = mainModule.weather.dequeue();
            next = !next;
            //no emergencies, broadcast current next
        }else{
            message = mainModule.current.dequeue();
            next = !next;
        }*/
        encodedMessage = msgEncode.encodeString(message);
        mainModule.broadcaster.broadCast(encodedMessage);
        messagesSent++;
   // }
    return 0;
}