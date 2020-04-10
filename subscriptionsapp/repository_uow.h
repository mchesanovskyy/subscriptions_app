#pragma once
#include "card_repository.h"
#include "subscription_repository.h"
#include "card_subscription_repository.h"
#include "card_subs_history_repository.h"
#include "location_repository.h"

class repository_uow
{
public:
	virtual ~repository_uow() = default;
	virtual card_repository* get_card_repository() = 0;
	virtual location_repository* get_location_repository() = 0;
	virtual card_subscription_repository* get_card_subscription_repository() = 0;
	virtual card_subs_history_repository* get_card_subs_history_repository() = 0;
	virtual subscription_repository* get_subscription_repository() = 0;
};