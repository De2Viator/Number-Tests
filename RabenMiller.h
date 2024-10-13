//
// Created by Yurij on 13.10.2024.
//

#ifndef RABENMILLER_H
#define RABENMILLER_H
#include "number.h"
#include <cmath>
struct RabenMillerInfo{
    number t;
    unsigned long s;
};

class RabenMillerTest {
    static RabenMillerInfo getInfo(number p);
public:
    static void test(number p);
};



#endif //RABENMILLER_H
