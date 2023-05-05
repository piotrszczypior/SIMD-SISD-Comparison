//
// Created by Piotr Szczypior on 05/05/2023.
//

#ifndef UNTITLED_TIMETESTERSIMD_H
#define UNTITLED_TIMETESTERSIMD_H

#include <vector>
#include "Timer.h"
#include "CalculatorSIMD.h"
#include "FileWriter.h"

using namespace std;

class TimeTesterSIMD {
private:
    CalculatorSIMD *calculator;
public:

    TimeTesterSIMD();

    template<typename T>
    long long test_add(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_subtract(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_multiply(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_divide(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);
};

TimeTesterSIMD::TimeTesterSIMD() {
    calculator = new CalculatorSIMD();
}

template<typename T>
long long TimeTesterSIMD::test_add(vector<T> first_vector, vector<T> second_vector,
                                   int size, vector<T> &result) {
    Timer timer;
    auto *fileWriter = new FileWriter();
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            calculator->add(first_vector[i],
                            second_vector[i],
                            result[i]);
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    auto time = whole_time / test_number;

    fileWriter->write_csv("simd", "add_simd", size, time);
    return time;
}

template<typename T>
long long TimeTesterSIMD::test_subtract(vector<T> first_vector, vector<T> second_vector,
                                        int size, vector<T> &result) {
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            calculator->subtract(first_vector[i],
                                 second_vector[i],
                                 result[i]);
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}

template<typename T>
long long TimeTesterSIMD::test_multiply(vector<T> first_vector, vector<T> second_vector,
                                        int size, vector<T> &result) {
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            calculator->multiply(first_vector[i],
                                 second_vector[i],
                                 result[i]);
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}


template<typename T>
long long TimeTesterSIMD::test_divide(vector<T> first_vector, vector<T> second_vector,
                                      int size, vector<T> &result) {
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            calculator->divide(first_vector[i],
                               second_vector[i],
                               result[i]);
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}

#endif //UNTITLED_TIMETESTERSIMD_H
