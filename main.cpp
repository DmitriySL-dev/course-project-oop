
#include "Functions.h"
#include <Windows.h>


void NewTerminate() {
	cout << "Необработанное исключение" << endl;
	exit(0);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(NewTerminate);
	Functions::Authorization();
}
