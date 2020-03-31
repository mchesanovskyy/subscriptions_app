#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
class serializer
{
public:
	virtual string to_string(T* entity) = 0;
	virtual T* to_object(string source) = 0;

protected:
	serializer() {
	}

	serializer(char delimiter) {
		delimiter_ = delimiter;
	}

	char delimiter_ = '|';
	vector<string> split(string source, char delimiter)
	{
		stringstream ss(source);
		string item;
		vector<string> splittedStrings;
		while (getline(ss, item, delimiter))
		{
			splittedStrings.push_back(item);
		}
		return splittedStrings;
	}
};



