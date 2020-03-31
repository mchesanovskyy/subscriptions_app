#pragma once
#include "card.h"
#include "serializer.h"

class card_serializer : public serializer<card>
{
	virtual string to_string(card* entity) override
	{
		return std::to_string(entity->id) + delimiter_ + entity->number;
	}

	virtual card* to_object(string source) override
	{
		auto parts = split(source, delimiter_);
		if (parts.size() < 2) {
			// throw exception
			return nullptr;
		}
		card* c = new card;
		c->id = stoi(parts[0]);
		c->number = parts[1];
		return c;
	}
};

