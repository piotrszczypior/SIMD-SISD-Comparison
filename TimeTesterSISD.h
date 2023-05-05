//
// Created by Piotr Szczypior on 30/04/2023.
//

#ifndef UNTITLED_TIMETESTERSISD_H
#define UNTITLED_TIMETESTERSISD_H

#include <vector>
#include "CalculatorSISD.h"
#include "Timer.h"
#include "FileWriter.h"

using namespace std;

class TimeTesterSISD {
private:
    CalculatorSISD *calculator;
public:

    TimeTesterSISD();

    template<typename T>
    long long test_add(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_subtract(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_multiply(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);

    template<typename T>
    long long test_divide(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result);
};


TimeTesterSISD::TimeTesterSISD() {
    calculator = new CalculatorSISD();
}

template<typename T>
long long TimeTesterSISD::test_add(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    auto *fileWriter = new FileWriter();
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                calculator->add(first_vector[i].data[j],
                                second_vector[i].data[j],
                                result[i].data[j]);
            }
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    auto time = whole_time / test_number;
    fileWriter->write_csv("", "add_sisd", size, time);
    return time;
}

template<typename T>
long long TimeTesterSISD::test_subtract(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                calculator->subtract(first_vector[i].data[j],
                                     second_vector[i].data[j],
                                     result[i].data[j]);
            }
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}

template<typename T>
long long TimeTesterSISD::test_multiply(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    Timer timer;

    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                calculator->multiply(first_vector[i].data[j],
                                     second_vector[i].data[j],
                                     result[i].data[j]);
            }
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}


template<typename T>
long long TimeTesterSISD::test_divide(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    Timer timer;
    long long whole_time = 0L;
    int test_number = 1;
    for (; test_number <= 10; test_number++) {
        timer.timeStart();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 4; j++) {
                calculator->divide(first_vector[i].data[j],
                                   second_vector[i].data[j],
                                   result[i].data[j]);
            }
        }
        timer.timeStop();
        whole_time += timer.elapsedTime();
    }
    return whole_time / test_number;
}

#endif //UNTITLED_TIMETESTERSISD_H
