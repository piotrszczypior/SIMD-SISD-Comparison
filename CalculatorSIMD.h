#ifndef UNTITLED_CALCULATORSIMD_H
#define UNTITLED_CALCULATORSIMD_H
#include "Timer.h"
 
class CalculatorSIMD {
private:
    Timer *timer;
public:
    CalculatorSIMD();

    template<class T>
    long long add(T &first_vector, T &second_vector, T &result);

    template<class T>
    long long subtract(T &first_vector, T &second_vector, T &result);

    template<class T>
    long long divide(T &first_vector, T &second_vector, T &result);

    template<class T>
    long long multiply(T &first_vector, T &second_vector, T &result);

    ~CalculatorSIMD();
};

CalculatorSIMD::CalculatorSIMD() {
    timer = new Timer();
}

template<class T>
long long CalculatorSIMD::multiply(T &first_vector, T &second_vector, T &result) {
    timer->timeStart();
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "mulps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

template<class T>
long long CalculatorSIMD::divide(T &first_vector, T &second_vector, T &result) {
    timer->timeStart();
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "divps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

template<class T>
long long CalculatorSIMD::subtract(T &first_vector, T &second_vector, T &result) {
    timer->timeStart();
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "subps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

template<class T>
long long CalculatorSIMD::add(T &first_vector, T &second_vector, T &result) {
    timer->timeStart();
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "addps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
    timer->timeStop();
    return timer->elapsedTime();
}

CalculatorSIMD::~CalculatorSIMD() {
    delete timer;
}

#endif //UNTITLED_CALCULATORSIMD_H
