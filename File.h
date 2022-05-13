#pragma once

#include <vector>
#include <fstream>
#include <map>
#include <memory>

#include "Account.h"
#include "History.h"


using std::vector;
using std::string;
using std::pair;
using std::multimap;
using std::ofstream;
using std::ifstream;
using std::endl;


class File { //Класс файла с шаблонными методами
public:
    template<typename T>
    void InFile(vector<shared_ptr<T>>& vec, string filename)
    {
        ofstream write(filename);
        for (int i = 0; i < vec.size(); ++i) {
            write << *(vec[i]) << endl;
        }
    }

    template<typename T>
    void InFile(vector<T>& vec, string filename)
    {
        ofstream write(filename);
        for (int i = 0; i < vec.size(); ++i) {
            write << vec[i] << endl;
        }
    }

    template<typename T>
    void FromFile(vector<shared_ptr<T>>& vec, string filename)
    {
        ifstream read(filename);
        for (;;) {
            T obj;
            if (!(read >> obj)) break;
            shared_ptr<T> pt = make_shared<T>(obj);
            vec.push_back(pt);
        }
    }

    template<typename T>
    void FromFile(vector<T>& vec, string filename)
    {
        ifstream read(filename);
        for (;;) {
            T obj;
            if (!(read >> obj)) break;
            vec.push_back(obj);
        }
    }
};