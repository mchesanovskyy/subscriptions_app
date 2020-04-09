#include "card_serializer.h"

string card_serializer::to_string(card* entity)
{
	return std::to_string(entity->id) + delimiter_ + entity->number;
}

card* card_serializer::to_object(string source)
{
	auto parts = split(source, delimiter_);
	if (parts.size() < 2)
	{
		// throw exception
		return nullptr;
	}
	card* c = new card;
	c->id = stoi(parts[0]);
	c->number = parts[1];
	return c;
}

