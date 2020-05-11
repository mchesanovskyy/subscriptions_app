#pragma once

template <class T>
class id_tracker
{
public:
	virtual T get_id() = 0;
};
