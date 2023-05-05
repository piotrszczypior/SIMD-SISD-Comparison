//
// Created by Piotr Szczypior on 05/05/2023.
//

#ifndef UNTITLED_CALCULATORSIMD_H
#define UNTITLED_CALCULATORSIMD_H
#pragma once

class CalculatorSIMD {
public:
    template<class T>
    void add(T &first_vector, T &second_vector, T &result);

    template<class T>
    void subtract(T &first_vector, T &second_vector, T &result);

    template<class T>
    void divide(T &first_vector, T &second_vector, T &result);

    template<class T>
    void multiply(T &first_vector, T &second_vector, T &result);
};

template<class T>
void CalculatorSIMD::multiply(T &first_vector, T &second_vector, T &result) {
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "mulps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
}

template<class T>
void CalculatorSIMD::divide(T &first_vector, T &second_vector, T &result) {
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "divps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
}

template<class T>
void CalculatorSIMD::subtract(T &first_vector, T &second_vector, T &result) {
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "subps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
}

template<class T>
void CalculatorSIMD::add(T &first_vector, T &second_vector, T &result) {
    __asm__ (
            "movups %1, %%xmm0\n\t"
            "movups %2, %%xmm1\n\t"
            "addps %%xmm0, %%xmm1\n\t"
            "movups %%xmm1, %0\n\t"
            : "=m" (result)
            : "m" (first_vector), "m" (second_vector)
            );
}


#endif //UNTITLED_CALCULATORSIMD_H
