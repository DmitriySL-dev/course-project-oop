#pragma once

#include <vector>
#include <fstream>
#include "Account.h"

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;


class File {
public:
    template<typename T>
    void InFile(vector<T>& vec, string filename)
    {
        ofstream write(filename);
        for (int i = 0; i < vec.size(); ++i) {
            write << vec[i] << endl;
        }
    }

    template<typename T>
    void FromFile(vector<T>& vec, string filename)
    {
        ifstream read(filename);
        for (T obj; read >> obj;) {
            vec.push_back(obj);
        }
    }
};