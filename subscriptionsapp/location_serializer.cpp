#include "location_serializer.h"

string location_serializer::to_string(location* entity)
{
	return join({ std::to_string(entity->id), entity->name }, delimiter_);
}

location* location_serializer::to_object(string source)
{
	auto parts = split(source, delimiter_);
	if (parts.size() < 2)
	{
		// throw exception
		return nullptr;
	}

	auto l = new location;
	l->id = stoi(parts[0]);
	l->name = parts[1];
	return l;
}
