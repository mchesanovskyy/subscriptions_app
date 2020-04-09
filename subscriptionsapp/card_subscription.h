#pragma once
#include "date_time.h"
#include "entity_base.h"

class card_subscription : public entity_base
{
public:
	int card_id = 0;
	int subscription_id = 0;
	date_time* created_at = nullptr;
	int unit_count = 0;
	date_time* effective_from = nullptr;
	date_time* effective_to = nullptr;
};

