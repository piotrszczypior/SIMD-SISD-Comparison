#include <iostream>
#include "CalculatorSISD.h"
#include "TimeTesterSISD.h"
#include "Vector4f.h"
#include "RandomGenerator.h"
#include "CalculatorSIMD.h"
#include "TimeTesterSIMD.h"
#include "FileWriter.h"

using namespace std;

int main() {

    auto *fileWriter = new FileWriter();
    TimeTesterSIMD timeTester;
    int sizes[] = {2048, 4096, 8192};
    for (int size: sizes) {
        vector<Vector4f> v1(size), v2(size);
        vector<Vector4f> result(size);
        RandomGenerator randomGenerator;
        randomGenerator.fill_collection_float(v1, size);
        randomGenerator.fill_collection_float(v2, size);

        auto time_add = timeTester.test_add(v1, v2, size, result);
        auto time_subtract = timeTester.test_subtract(v1, v2, size, result);
        auto time_divide = timeTester.test_divide(v1, v2, size, result);
        auto time_multiply = timeTester.test_multiply(v1, v2, size, result);

        fileWriter->write_to_txt("sisd_time_" + to_string(size), "SISD", size, time_add,
                                 time_subtract, time_multiply, time_divide);
    }
    delete fileWriter;

//    vector<Vector4f> vector2(1);
//    vector1[0].data[0] = 0.5;
//    vector1[0].data[1] = 0.5;
//    vector1[0].data[2] = 0.5;
//    vector1[0].data[3] = 0.5;
//    vector2[0].data[0] = 0.6;
//    vector2[0].data[1] = 0.6;
//    vector2[0].data[2] = 0.6;
//    vector2[0].data[3] = 0.6;
//
//    vector<Vector4f> result(1);
//
//    CalculatorSIMD calculatorSimd;
//    calculatorSimd.multiply(vector1[0], vector2[0], result[0]);
//
//    for(int i = 0; i < 4; i++) {
//        cout << vector2[0].data[i] << " - " << vector1[0].data[i] << " = " << result[0].data[i] << endl;
//    }
    return 0;
}