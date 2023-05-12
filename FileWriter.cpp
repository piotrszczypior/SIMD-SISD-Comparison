#include <list>
#include "FileWriter.h"


void FileWriter::write_to_txt(string file_name, string operation_type, int elements_number, long long int add_time,
                              long long int sub_time, long long int mul_time, long long int div_time) {
    file_name += ".txt";
    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    if (file.is_open()) {
        string lines[7];
        lines[0] = "Calculation type:\t" + operation_type + "\n";
        lines[1] = "Number of elements:\t" + to_string(elements_number) + "\n";
        lines[2] = "Avg time: [microseconds]\n";
        lines[3] = "+\t" + to_string(add_time) + "\n";
        lines[4] = "-\t" + to_string(sub_time) + "\n";
        lines[5] = "*\t" + to_string(mul_time) + "\n";
        lines[6] = "/\t" + to_string(div_time) + "\n";

        for (const string &line: lines) {
            file << line;
        }
    }
}

void FileWriter::write_csv(const string& dir, string operation, int elements_size, long long int time) {
    operation += "_";
    operation += dir;
    operation += ".csv";
    string file_name = operation;
    std::ofstream file;
    file.open(file_name, std::ios::in | std::ios::app);

    if (file.is_open()) {
        string line = to_string(elements_size) + ";" + to_string(time);
        file << line << endl;
    }
}
