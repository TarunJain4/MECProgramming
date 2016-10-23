//
// Created by Pavi on 2016-10-22.
//

#include <iostream>
#include "Broadcaster.h"

void  Broadcaster::setFreqAm(int freq) {
    std::cout << "AM Frequency set: " << freq << std::endl;
}

void  Broadcaster::setFreqFm(int freq) {
    std::cout << "FM Frequency set: " << freq << std::endl;
}

int  Broadcaster::broadCast(char * message) {
    std::cout << "Broadcasting Message: " << message <<std::endl;
    return 1;
}