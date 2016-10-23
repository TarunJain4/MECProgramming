//
// Created by Pavi on 2016-10-22.
//

#include <cstdlib>
#include <iostream>
#include "TestBand.h"
int frequency;

void TestBand::freq(int inputFreq) {
    frequency = inputFreq;
}

bool TestBand::test() {
    std::cout << "Testing Band: " << frequency << std::endl;
    return (rand() % 2) == 1;
}