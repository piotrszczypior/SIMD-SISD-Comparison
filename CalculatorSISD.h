#ifndef UNTITLED_CALCULATORSISD_H
#define UNTITLED_CALCULATORSISD_H

#include <vector>
#include "Timer.h"

using namespace std;

class CalculatorSISD {
private:
    Timer *timer;
public:
    CalculatorSISD();

    template<class T>
    long long add(T &first_number, T &second_number, T &result);

    template<class T>
    long long subtract(T &first_number, T &second_number, T &result);

    template<class T>
    long long divide(T &first_number, T &second_number, T &result);

    template<class T>
    long long multiply(T &first_number, T &second_number, T &result);

    ~CalculatorSISD();
};

CalculatorSISD::CalculatorSISD() {
    this->timer = new Timer();
}

template<class T>
long long CalculatorSISD::add(T &first_number, T &second_number, T &result) {
    timer->timeStart();
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "faddp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

template<class T>
long long CalculatorSISD::subtract(T &first_number, T &second_number, T &result) {
    timer->timeStart();
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fsubp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
    timer->timeStop();
    return timer->elapsedTime();
}


template<class T>
long long CalculatorSISD::multiply(T &first_number, T &second_number, T &result) {
    timer->timeStart();
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fmulp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

template<class T>
long long CalculatorSISD::divide(T &first_number, T &second_number, T &result) {
    timer->timeStart();
    __asm__ (
            "flds %1\n\t"
            "flds %2\n\t"
            "fdivp\n\t"
            "fstps %0\n\t"
            : "=m" (result)
            : "m" (first_number), "m" (second_number)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

CalculatorSISD::~CalculatorSISD() {
    delete timer;
}


#endif //UNTITLED_CALCULATORSISD_H
