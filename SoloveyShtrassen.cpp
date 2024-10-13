//
// Created by Yurij on 13.10.2024.
//
#include "SoloveyShtrassen.h"
#include "helpers.h"
short SoloveyShtrassenTest::jacobiSymbol(number a, number p) {
    if (a % p == 0) return 0;
    int result = 1;
    if (a < 0) {
        a = -a;
        if (p % 4 == 3) result = -result;
    }
    while (a != 0) {
        while (a % 2 == 0) {
            a /= 2;
            if (p % 8 == 3 || p % 8 == 5) result = -result;
        }
        std::swap(a, p);
        if (a % 4 == 3 && p % 4 == 3) result = -result;
        a %= p;
    }
    if (p == 1) return result;
    return 0;
}

int SoloveyShtrassenTest::legendreSymbol(number a, number p) {
    if (a == 0) {
        return 0;
    } else if (a == 1) {
        return 1;
    } else if (a % 2 == 0) {
        return legendreSymbol(a/2, p) * pow(-1, ((p*p - 1) / 8));
    } else {
        return legendreSymbol(p % a, a) * pow(-1, ((a - 1) * (p - 1) / 4));
    }
}

void ::SoloveyShtrassenTest::test(number p, number k) {
    bool isComposite = false;
    for(number i =0; i < k;i++) {
        number a = generateRandomNumber(3,p-1);
        number gcd = GCD(a,p);
        if(gcd != 1) {
            isComposite = true;
            break;
        }
        short L = legendreSymbol(a,p);
        number e = static_cast<number>(pow(a, ((p-1)/2))) % p;
        if(e != L) {
            isComposite = true;
            break;
        }
        short J = jacobiSymbol(a,p);
        if(J != L) {
            isComposite = true;
            break;
        }
    }
    showResults(isComposite,p, 1/pow(2,k));
};
