#pragma once
#include "card_subscription.h"
#include "repository_base.h"

class card_subscription_repository : public repository_base<card_subscription>
{
public:
	explicit card_subscription_repository(file_provider<card_subscription>* provider, int_id_tracker* tracker)
		: repository_base<card_subscription>(provider, tracker)
	{
	}
};

