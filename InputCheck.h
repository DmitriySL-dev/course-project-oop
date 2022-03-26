#pragma once

#include <iostream>
#include <string>

using std::string;

class InputCheck {
public:
	template<typename T>
	T GetValue(T& value)
	{
		while (true) {
			try
			{
				if (!(std::cin >> value) || std::cin.peek() != '\n') throw 1;
				else { return value; }
			}
			catch (const int&)
			{
				std::cout << message << std::endl;
				std::cin.clear();
				fflush(stdin);
				std::cin.ignore(32767, '\n');
			}

		}
	}

	template<>
	unsigned int GetValue(unsigned int& value) {
		int buf;
		while (true) {
			try
			{
				if (!(std::cin >> buf) || std::cin.peek() != '\n') throw 1;
				else if (buf < 0) throw 2;
				else { value = buf; return value; }
			}
			catch (const int&)
			{
				std::cout << std::endl<<message << std::endl<<std::endl;
				std::cin.clear();
				fflush(stdin);
				std::cin.ignore(32767, '\n');
			}

		}

	}
private:

	string message = "Ќеверное значение, попытайтесь снова";
};
