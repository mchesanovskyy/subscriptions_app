#pragma once
#include "serializer.h"
#include "subscription.h"
class subscription_serializer : public serializer<subscription>
{
	// Inherited via serializer
	string to_string(subscription* entity) override;
	subscription* to_object(string source) override;
};

