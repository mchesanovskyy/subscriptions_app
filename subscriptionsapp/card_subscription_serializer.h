#pragma once
#include "card_subscription.h"
#include "serializer.h"

class card_subscription_serializer : public serializer<card_subscription>
{
public:
	string to_string(card_subscription* entity) override;
	card_subscription* to_object(string source) override;
};

