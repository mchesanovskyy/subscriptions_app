#pragma once
#include "date_time.h"
#include "entity_base.h"

class card_subs_history : public entity_base
{
public:
	int card_subscription_id = 0;
	date_time created_at;
	int units_used = 0;
};

