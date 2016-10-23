//
// Created by Pavi on 2016-10-22.
//
#include <iostream>
#include "Selector.h"
#include "Encoder.h"
#include "Broadcaster.h"

void Selector::print(){
    std::cout << "hi";
}

int Selector::mainLoop(SetUp mainModule){
    bool run = true;
    //boolean true is weather false is current
    bool next = true;
    char* message;
    char* encodedMessage;
    Encoder msgEncode;
    int messagesSent = 0;

    while (run){
        if (messagesSent > 50){
            mainModule.testHardware();
        }
        //emergency situation
        if (weather.GetPriority() && current.GetPriority()) {
            if (next){
                message = weather.dequeue();
            }else{
                message = current.dequeue();
            }
            next = !next;
        }else if (weather.GetPriority()){
            message = weather.dequeue();
        }else if (current.GetPriority()){
            message = current.dequeue();
            //no emergencies, broadcast weather next
        }else if (next){
            message = weather.dequeue();
            next = !next;
            //no emergencies, broadcast current next
        }else{
            message = current.dequeue();
            next = !next;
        }

        encodedMessage = msgEncode.encodeString(message);
        mainModule.broadcaster.broadcast(encodedMessage);
        messagesSent++;
    }
    return 0;
}