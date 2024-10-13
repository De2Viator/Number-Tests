#ifndef SOLOVEYSHTRASSEN_H
#define SOLOVEYSHTRASSEN_H
#include "number.h"
#include <cmath>


class SoloveyShtrassenTest {
    static short jacobiSymbol(number a, number p);
    static int legendreSymbol(number a, number p);
public:
    static void test(number p, number k);
};



#endif //SOLOVEYSHTRASSEN_H
