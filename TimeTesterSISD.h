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

    ~TimeTesterSISD();
};


TimeTesterSISD::TimeTesterSISD() {
    calculator = new CalculatorSISD();
}

template<typename T>
long long TimeTesterSISD::test_add(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    // FileWriter fileWriter;
    long long whole_time = 0L;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            whole_time += calculator->add(first_vector[i].data[j],
                            second_vector[i].data[j],
                            result[i].data[j]);
        }
    }

    auto time = whole_time;
    // fileWriter.write_csv("sisd", "add", size, time);
    return time;
}

template<typename T>
long long TimeTesterSISD::test_subtract(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    // FileWriter fileWriter;
    long long whole_time = 0L;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            whole_time += calculator->subtract(first_vector[i].data[j],
                                    second_vector[i].data[j],
                                    result[i].data[j]);
        }
    }
    
    auto time = whole_time;
    // fileWriter.write_csv("sisd", "subtract", size, time);
    return time;
}

template<typename T>
long long TimeTesterSISD::test_multiply(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    // FileWriter fileWriter;
    long long whole_time = 0L;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            whole_time += calculator->multiply(first_vector[i].data[j],
                                    second_vector[i].data[j],
                                    result[i].data[j]);
        }
    }
    
    auto time = whole_time;
    // fileWriter.write_csv("sisd", "multiply", size, time);
    return time;
}


template<typename T>
long long TimeTesterSISD::test_divide(vector<T> first_vector, vector<T> second_vector, int size, vector<T> &result) {
    // FileWriter fileWriter;
    long long whole_time = 0L;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            whole_time += calculator->divide(first_vector[i].data[j],
                                second_vector[i].data[j],
                                result[i].data[j]);
        }
    }
    
    auto time = whole_time;
    // fileWriter.write_csv("sisd", "divide", size, time);
    return time;
}

TimeTesterSISD::~TimeTesterSISD() {
    delete calculator;
}

#endif //UNTITLED_TIMETESTERSISD_H
