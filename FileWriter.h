#ifndef UNTITLED_FILEWRITER_H
#define UNTITLED_FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class FileWriter {
public:
    void write_to_txt(string file_name, string operation_type, int elements_number,
                      long long add_time, long long sub_time, long long mul_time, long long div_time);

    void write_csv(const string& dir, string operation, int elements_size, long long time);
};


#endif //UNTITLED_FILEWRITER_H
