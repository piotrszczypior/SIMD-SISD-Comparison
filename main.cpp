#include <iostream>
#include "CalculatorSISD.h"
#include "TimeTesterSISD.h"
#include "Vector4f.h"
#include "Vector4l.h"
#include "RandomGenerator.h"
#include "CalculatorSIMD.h"
#include "TimeTesterSIMD.h"
#include "FileWriter.h"
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {

    auto *fileWriter = new FileWriter();
    TimeTesterSIMD timeTesterSIMD;
    TimeTesterSISD timeTesterSISD;
    int sizes[] = {2048, 4096, 8192};

    RandomGenerator randomGenerator;
    auto calculation_type = argv[1];
    cout << "Calculation type: " << calculation_type << endl;

    if(strcmp(calculation_type, "SISD") == 0) {
        for (int size: sizes) {
            auto time_add = 0L;
            auto time_subtract = 0L;
            auto time_divide = 0L;
            auto time_multiply = 0L;
            for(int test_count = 1; test_count <= 10; test_count++) {
                vector<Vector4f> v1(size), v2(size);
                vector<Vector4f> result(size);

                randomGenerator.fill_collection_float(v1, size);
                randomGenerator.fill_collection_float(v2, size);

                time_add += timeTesterSISD.test_add(v1, v2, size, result);
                time_subtract += timeTesterSISD.test_subtract(v1, v2, size, result);
                time_divide += timeTesterSISD.test_divide(v1, v2, size, result);
                time_multiply += timeTesterSISD.test_multiply(v1, v2, size, result);
            }

            time_add /= 10;
            time_subtract /= 10;
            time_divide /= 10;
            time_multiply /= 10;
            fileWriter->write_csv("sisd", "add", size, time_add);
            fileWriter->write_csv("sisd", "subtract", size, time_subtract);
            fileWriter->write_csv("sisd", "multiply", size, time_multiply);
            fileWriter->write_csv("sisd", "divide", size, time_divide);
            fileWriter->write_to_txt("sisd_time_" + to_string(size), "SISD", size, time_add,
                                    time_subtract, time_multiply, time_divide);
        }
    } else if (strcmp(calculation_type, "SIMD") == 0) {
        for (int size: sizes) {
            auto time_add = 0L;
            auto time_subtract = 0L;
            auto time_divide = 0L;
            auto time_multiply = 0L;
            for(int test_count = 1; test_count <= 10; test_count++) {
                vector<Vector4f> v1(size), v2(size);
                vector<Vector4f> result(size);

                randomGenerator.fill_collection_float(v1, size);
                randomGenerator.fill_collection_float(v2, size);

                time_add += timeTesterSIMD.test_add(v1, v2, size, result);
                time_subtract += timeTesterSIMD.test_subtract(v1, v2, size, result);
                time_divide += timeTesterSIMD.test_divide(v1, v2, size, result);
                time_multiply += timeTesterSIMD.test_multiply(v1, v2, size, result);
            }
            time_add /= 10;
            time_subtract /= 10;
            time_divide /= 10;
            time_multiply /= 10;

            fileWriter->write_csv("simd", "add", size, time_add);
            fileWriter->write_csv("simd", "subtract", size, time_subtract);
            fileWriter->write_csv("simd", "multiply", size, time_multiply);
            fileWriter->write_csv("simd", "divide", size, time_divide);
            fileWriter->write_to_txt("simd_time_" + to_string(size), "SIMD", size, time_add,
                                    time_subtract, time_multiply, time_divide);
        }
    }

    delete fileWriter;

//    vector<Vector4f> vector1(1);
//    vector<Vector4f> vector2(1);
//    vector1[0].data[0] = 0.5;
//    vector1[0].data[1] = 0.5;
//    vector1[0].data[2] = 0.5;
//    vector1[0].data[3] = 0.5;
//    vector2[0].data[0] = 0.6;
//    vector2[0].data[1] = 0.6;
//    vector2[0].data[2] = 0.6;
//    vector2[0].data[3] = 0.6;

//    vector<Vector4f> result(1);

//    CalculatorSIMD calculatorSimd;
//    calculatorSimd.multiply(vector1[0], vector2[0], result[0]);

//    for(int i = 0; i < 4; i++) {
//        cout << vector2[0].data[i] << " * " << vector1[0].data[i] << " = " << result[0].data[i] << endl;
//    }
    return 0;
}