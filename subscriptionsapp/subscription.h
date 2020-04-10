#pragma once
#include "date_time.h"
#include "entity_base.h"

class subscription : public entity_base
{
public:
	string name = {};
	string type = {};
	date_time* effective_from = nullptr;
	date_time* effective_to = nullptr;
	string unit_title = {};
	int max_unit_count = 0;
	int hours = 0;
};

