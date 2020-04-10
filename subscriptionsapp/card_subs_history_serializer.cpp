#include "card_subs_history_serializer.h"

string card_subs_history_serializer::to_string(card_subs_history* entity)
{
	return join({
		std::to_string(entity->id),
		std::to_string(entity->card_subscription_id),
		entity->created_at.to_string(),
		std::to_string(entity->units_used),
	}, delimiter_);
}

card_subs_history* card_subs_history_serializer::to_object(string source)
{
	auto parts = split(source, delimiter_);
	if (parts.size() < 7)
	{
		// throw exception
		return nullptr;
	}

	auto subs_history = new card_subs_history;
	subs_history->id = stoi(parts[0]);
	subs_history->card_subscription_id = stoi(parts[1]);
	subs_history->created_at = date_time::parse(parts[2]);
	subs_history->units_used = stoi(parts[3]);

	return subs_history;
}
