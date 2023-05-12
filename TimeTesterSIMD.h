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

    ~TimeTesterSIMD();
};

TimeTesterSIMD::TimeTesterSIMD() {
    calculator = new CalculatorSIMD();
}

template<typename T>
long long TimeTesterSIMD::test_add(vector<T> first_vector, vector<T> second_vector,
                                   int size, vector<T> &result) {
    // auto *fileWriter = new FileWriter();
    long long whole_time = 0L;
  
    for (int i = 0; i < size; i++) {
        whole_time += calculator->add(first_vector[i],
                        second_vector[i],
                        result[i]);
    }
    
    auto time = whole_time;

    // fileWriter->write_csv("simd", "add", size, time);
    // delete fileWriter;
    return time;
}

template<typename T>
long long TimeTesterSIMD::test_subtract(vector<T> first_vector, vector<T> second_vector,
                                        int size, vector<T> &result) {
    long long whole_time = 0L;
    // auto *fileWriter = new FileWriter();
    for (int i = 0; i < size; i++) {
        whole_time += calculator->subtract(first_vector[i],
                                second_vector[i],
                                result[i]);
    }
    auto time = whole_time;

    // fileWriter->write_csv("simd", "subtract", size, time);
    // delete fileWriter;
    return time;
}

template<typename T>
long long TimeTesterSIMD::test_multiply(vector<T> first_vector, vector<T> second_vector,
                                        int size, vector<T> &result) {
    long long whole_time = 0L;
    // auto *fileWriter = new FileWriter();
    for (int i = 0; i < size; i++) {
        whole_time += calculator->multiply(first_vector[i],
                                second_vector[i],
                                result[i]);
    }
    
    auto time = whole_time;

    // fileWriter->write_csv("simd", "mutiply", size, time);
    // delete fileWriter;
    return time;
}


template<typename T>
long long TimeTesterSIMD::test_divide(vector<T> first_vector, vector<T> second_vector,
                                      int size, vector<T> &result) {
    long long whole_time = 0L;
    // auto *fileWriter = new FileWriter();
        for (int i = 0; i < size; i++) {
            whole_time += calculator->divide(first_vector[i],
                               second_vector[i],
                               result[i]);
        }
    auto time = whole_time;

    // fileWriter->write_csv("simd", "divide", size, time);
    // delete fileWriter;
    return time;
}

TimeTesterSIMD::~TimeTesterSIMD() {
    delete calculator;
}

#endif //UNTITLED_TIMETESTERSIMD_H
