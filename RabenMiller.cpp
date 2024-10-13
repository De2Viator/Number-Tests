#include "RabenMiller.h"
#include "helpers.h"
RabenMillerInfo RabenMillerTest::getInfo(number p) {
    unsigned long s = 0;
    while(p % 2 == 0 && p != 0) {
        p/=2;
        s++;
    }
    return {p, s};
}
void RabenMillerTest::test(number p) {
    bool isComposite = false;
    number a = generateRandomNumber(3,p-1);
    number gcd = GCD(a,p);
    unsigned long k = 1;
    if(gcd != 1) {
        isComposite = true;
    }
    if(!isComposite) {
        RabenMillerInfo info = getInfo(p-1);
        unsigned long long b = static_cast<number>(pow(a, info.t)) % p;
        if(b != p - 1 && b != 1) {
            isComposite = true;
        }
        if(!isComposite) {
            while(k < info.s) {
                if(b != 1 && b != p -1) {
                    k++;
                    b = static_cast<number>(pow(b,2)) % p;
                }
                if(b == p-1) {
                    break;
                }
            }
        }
    }
    showResults(isComposite,p, 1/pow(4,k));
}