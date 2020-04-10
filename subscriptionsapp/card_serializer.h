#pragma once
#include "card.h"
#include "serializer.h"

class card_serializer : public serializer<card>
{
	string to_string(card* entity) override;

	card* to_object(string source) override;
};
