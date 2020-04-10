#pragma once
#include "serializer.h"
#include "card_subs_history.h"

class card_subs_history_serializer : public serializer<card_subs_history>
{
public:
	string to_string(card_subs_history* entity) override;
	card_subs_history* to_object(string source) override;
};

