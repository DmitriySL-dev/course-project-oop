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
    void InFile(vector<Account>& acc, string filename);

    void FromFile(vector<Account>& acc, string filename);
};