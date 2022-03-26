#include "File.h"


void File::InFile(vector<Account>& acc, string filename)
{
    ofstream write(filename);
    for (int i = 0; i < acc.size(); ++i) {
        write << acc[i] << endl;
    }
}

void File::FromFile(vector<Account>& acc, string filename)
{
    ifstream read(filename);

    for (Account obj; read >> obj;) {
        acc.push_back(obj);
    }
}
