#pragma once
#include "location.h"
#include "serializer.h"

class location_serializer : public serializer<location>
{
	// Inherited via serializer
	string to_string(location* entity) override;
	location* to_object(string source) override;
};

