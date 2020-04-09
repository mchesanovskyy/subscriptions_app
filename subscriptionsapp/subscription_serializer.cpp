#include "subscription_serializer.h"

string subscription_serializer::to_string(subscription* entity)
{
	return join({
		std::to_string(entity->id),
		entity->name,
		entity->type,
		entity->unit_title,
		std::to_string(entity->max_unit_count),
		entity->effective_from == nullptr ? "" : entity->effective_from->to_string(),
		entity->effective_to == nullptr ? "" : entity->effective_to->to_string(),
		std::to_string(entity->hours)
		}, delimiter_);
}

subscription* subscription_serializer::to_object(string source)
{
	auto parts = split(source, delimiter_);
	if (parts.size() < 8)
	{
		// throw exception
		return nullptr;
	}

	auto subs = new subscription;
	subs->id = stoi(parts[0]);
	subs->name = parts[1];
	subs->type = parts[2];
	subs->unit_title = parts[3];
	subs->max_unit_count = stoi(parts[4]);
	if (!parts[5].empty()) {
		subs->effective_from = &date_time::parse(parts[5]);
	}
	
	if (!parts[6].empty()) {
		subs->effective_to = &date_time::parse(parts[6]);
	}
	subs->hours = stoi(parts[7]);

	return subs;
}
