//
// Created by Piotr Szczypior on 05/05/2023.
//

#include "RandomGenerator.h"

void RandomGenerator::fill_collection_float(vector<Vector4f> &vector, int size) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_real_distribution<float> random_value_distribution(0.0, 100.0);

    for (int i = 0; i < size; i++) {
        for (float & j : vector[i].data)
            j = random_value_distribution(generator);
    }
}

void RandomGenerator::fill_collection_long(vector<Vector4l> &vector, int size) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<long> random_value_distribution(0, 100);

    for (int i = 0; i < size; i++) {
        for (long & j : vector[i].data)
            j = random_value_distribution(generator);
    }
}
