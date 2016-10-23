//
// Created by Pavi on 2016-10-22.
//

#include <iostream>
#include "Broadcaster.h"

void  Broadcaster::setFreqAm(int freq) {
    std::cout << freq;
}

void  Broadcaster::setFreqFm(int freq) {
    std::cout << freq;
}

void  Broadcaster::broadCast(char * message) {
    std::cout << message;
}