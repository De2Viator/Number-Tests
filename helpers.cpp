#include "helpers.h"

#include <iostream>
#include <ostream>
#include <random>

number GCD(number a, number b) {
    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}
number generateRandomNumber(number from ,number to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(from, to);

    return dis(gen);
}
void showResults(bool isComposite, number p, double k) {
    if(isComposite) {
        std::cout<<"Number "<<p<<" is composite"<<std::endl;
    } else {
        std::cout<<"Number "<<p<<" is composite with chance "<<k<<std::endl;;
    }
}
