#include "date_time.h"

//2020-04-10T10:33:25
string date_time::format_{"%Y-%m-%dT%H:%M:%S"};


tm* date_time::parse_str(const string value)
{
	stringstream ss(value);
	auto t = new tm;
	ss >> get_time(t, format_.c_str());
	return t;
}

ostream& operator<<(ostream& lhs, const date_time& dt)
{
	lhs << dt.to_string();
	return lhs;
}

date_time::date_time()
{
}

date_time::date_time(tm& tm): inner_tm_(tm)
{
}

date_time::date_time(const string& str): date_time(*parse_str(str))
{
}

date_time& date_time::operator=(const date_time& dt)
{
	inner_tm_ = dt.inner_tm_;
	return *this;
}

bool date_time::operator==(const date_time& dt) const
{
	return get_total_seconds() == dt.get_total_seconds();
}

bool date_time::operator!=(const date_time& dt) const
{
	return get_total_seconds() != dt.get_total_seconds();
}

bool date_time::operator>(const date_time& dt) const
{
	return get_total_seconds() > dt.get_total_seconds();
}

bool date_time::operator>=(const date_time& dt) const
{
	return get_total_seconds() >= dt.get_total_seconds();
}

bool date_time::operator<(const date_time& dt) const
{
	return get_total_seconds() < dt.get_total_seconds();
}

bool date_time::operator<=(const date_time& dt) const
{
	return get_total_seconds() <= dt.get_total_seconds();
}

string date_time::to_string() const
{
	std::stringstream ss;
	ss << put_time(&inner_tm_, format_.c_str());
	return ss.str();
}

int date_time::get_total_seconds() const
{
	return mktime(&inner_tm_);
}

date_time& date_time::now()
{
	time_t today = time(nullptr);
	tm* tm_today = new tm;
	localtime_s(tm_today, &today);
	return parse(*tm_today);
}

date_time& date_time::parse(string value)
{
	return *new date_time(value);
}

date_time& date_time::parse(tm& value)
{
	return *new date_time(value);
}
