#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

inline bool equals_ignore_case(const string& a, const string& b)
{
	return equal(a.begin(), a.end(), b.begin(), b.end(), [](char a, char b) { return tolower(a) == tolower(b); });
}

inline vector<string> split(const string& value, const char delimiter)
{
	stringstream ss(value);
	string item;
	vector<string> parts;
	while (getline(ss, item, delimiter))
	{
		parts.push_back(item);
	}
	return parts;
}