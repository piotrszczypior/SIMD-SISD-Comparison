//
// Created by Piotr Szczypior on 30/04/2023.
//

#ifndef UNTITLED_RANDOMGENERATOR_H
#define UNTITLED_RANDOMGENERATOR_H

#include <random>
#include "Vector4f.h"
#include "Vector4l.h"

#ifndef LIST_RANDOMGENERATOR_H
#define LIST_RANDOMGENERATOR_H

#endif //LIST_RANDOMGENERATOR_H
using namespace std;

class RandomGenerator {
public:
    void fill_collection_float(vector<Vector4f> &vector, int size);

    void fill_collection_long(vector<Vector4l> &vector, int size);

};



#endif //UNTITLED_RANDOMGENERATOR_H
