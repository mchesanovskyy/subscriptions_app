#include "card_subscription_serializer.h"

string card_subscription_serializer::to_string(card_subscription* entity)
{
	return join({
		std::to_string(entity->id),
		std::to_string(entity->card_id),
		std::to_string(entity->subscription_id),
		entity->created_at == nullptr ? "" : entity->created_at->to_string(),
		entity->effective_from == nullptr ? "" : entity->effective_from->to_string(),
		entity->effective_to == nullptr ? "" : entity->effective_to->to_string(),
		std::to_string(entity->unit_count)
	}, delimiter_);
}

card_subscription* card_subscription_serializer::to_object(string source)
{
	auto parts = split(source, delimiter_);
	if (parts.size() < 7)
	{
		// throw exception
		return nullptr;
	}

	auto subs = new card_subscription;
	subs->id = stoi(parts[0]);
	subs->card_id = stoi(parts[1]);
	subs->subscription_id = stoi(parts[2]);
	if (!parts[3].empty()) {
		subs->created_at = &date_time::parse(parts[3]);
	}
	
	if (!parts[4].empty()) {
		subs->effective_from = &date_time::parse(parts[4]);
	}

	if (!parts[5].empty()) {
		subs->effective_to = &date_time::parse(parts[5]);
	}
	
	subs->unit_count = stoi(parts[6]);

	return subs;
}
