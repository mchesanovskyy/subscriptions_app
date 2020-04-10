#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
using namespace std;

class date_time
{
	static string format_;
	tm& inner_tm_ = *new tm;

public:
	explicit date_time();

	explicit date_time(tm& tm);

	explicit date_time(const string& str);

	string to_string() const;

	int get_total_seconds() const;

	static date_time& now();

	static date_time& parse(string value);

	static date_time& parse(tm& value);

	date_time& operator=(const date_time& dt);

	bool operator ==(const date_time& dt) const;

	bool operator !=(const date_time& dt) const;

	bool operator >(const date_time& dt) const;

	bool operator >=(const date_time& dt) const;

	bool operator <(const date_time& dt) const;

	bool operator <=(const date_time& dt) const;

private:
	static tm* parse_str(string value);
};

#endif