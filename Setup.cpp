//
// Created by Pavi on 2016-10-22.
//
#include <stdlib.h>
#include <iostream>
#include "Setup.h"
#include "TestBand.h"

int Setup::setUp() {
    //khz frequency range 540khz ~ 1600khz by 10khz
    int amGen = (rand() % 106)*10 + 540 ;
    //khz frequency range 88100khz ~ 108001khz by 200khz
    int fmGen = (rand() % 100)*200 + 88100 ;

    TestBand testAm;
    do{
        amGen = (rand() % 106)*10 + 540 ;
        testAm.freq(amGen);
    }while(!testAm.test());

    TestBand testFm;
    do{
        fmGen = (rand() % 100)*200 + 88100 ;
        testAm.freq(fmGen);
    }while(!testFm.test());

    //setup broadcaster
    broadcaster.setFreqAm(amGen);
    broadcaster.setFreqFm(fmGen);
}

void Setup::testHardware() {
    std::cout << "hardware Tested";
}