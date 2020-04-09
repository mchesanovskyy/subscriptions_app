#pragma once
#include "pch.h"

class subscription
{
public:
	int id = 0;
	string name = {};
	string type = {};
	date_time* effective_from = nullptr;
	date_time* effective_to = nullptr;
	string unit_title = {};
	int max_unit_count = 0;
	int hours = 0;
};

