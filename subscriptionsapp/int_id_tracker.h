#pragma once
#include "id_tracker.h"
class int_id_tracker : public id_tracker<int>
{
public:
	int get_id() override = 0; // Optional
};

