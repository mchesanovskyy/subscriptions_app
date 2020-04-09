#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <locale>
using namespace std;


class date_time
{
	static string format_;
	tm& inner_tm_;

public:
	date_time(tm& tm) : inner_tm_(tm) { }

	date_time(const string& str)
		: date_time(*parse_str(str)) { }

	string to_string() const;

	int get_total_seconds() const;

	static date_time& now();

	static date_time& parse(string value);

	static date_time& parse(tm& value);

	bool operator == (const date_time& dt) const
	{
		return get_total_seconds() == dt.get_total_seconds();
	}

	bool operator != (const date_time& dt) const
	{
		return get_total_seconds() != dt.get_total_seconds();
	}

	bool operator > (const date_time& dt) const
	{
		return get_total_seconds() > dt.get_total_seconds();
	}

	bool operator >= (const date_time& dt) const
	{
		return get_total_seconds() >= dt.get_total_seconds();
	}

	bool operator < (const date_time& dt) const
	{
		return get_total_seconds() < dt.get_total_seconds();
	}

	bool operator <= (const date_time& dt) const
	{
		return get_total_seconds() <= dt.get_total_seconds();
	}

private:
	static tm* parse_str(string value);
};

string date_time::format_{ "%Y-%m-%dT%H:%M:%S" };

inline ostream& operator <<(ostream& lhs, const date_time& dt)
{
	lhs << dt.to_string();
	return lhs;
}

inline tm* date_time::parse_str(const string value)
{
	stringstream ss(value);
	auto t = new tm;
	ss >> get_time(t, format_.c_str());
	return t;
}

inline string date_time::to_string() const
{
	std::stringstream ss;
	ss << put_time(&inner_tm_, format_.c_str());
	return ss.str();
}

inline int date_time::get_total_seconds() const
{
	return mktime(&inner_tm_);
}

inline date_time& date_time::now()
{
	time_t today = time(NULL);
	tm* tm_today = new tm;
	localtime_s(tm_today, &today);
	return parse(*tm_today);
}

inline date_time& date_time::parse(string value)
{
	return *new date_time(value);
}

inline date_time& date_time::parse(tm& value)
{
	return *new date_time(value);
}

