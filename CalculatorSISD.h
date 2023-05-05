//
// Created by Piotr Szczypior on 30/04/2023.
//

#ifndef UNTITLED_CALCULATORSISD_H
#define UNTITLED_CALCULATORSISD_H

#include <vector>

using namespace std;

class CalculatorSISD {
public:
    template<class T>
    void add(T &first_number, T &second_number, T &result);

    template<class T>
    void subtract(T &first_number, T &second_number, T &result);

    template<class T>
    void divide(T &first_number, T &second_number, T &result);

    template<class T>
    void multiply(T &first_number, T &second_number, T &result);
};

template<class T>
void CalculatorSISD::add(T &first_number, T &second_number, T &result) {
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "faddp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
}

template<class T>
void CalculatorSISD::subtract(T &first_number, T &second_number, T &result) {
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fsubp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
}


template<class T>
void CalculatorSISD::multiply(T &first_number, T &second_number, T &result) {
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fmulp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
}

template<class T>
void CalculatorSISD::divide(T &first_number, T &second_number, T &result) {
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fdivp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
}


#endif //UNTITLED_CALCULATORSISD_H
