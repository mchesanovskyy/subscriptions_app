#pragma once
#include "repository_base.h"
#include "subscription.h"

class subscription_repository : public repository_base<subscription>
{
public:
	subscription_repository(file_provider<subscription>* provider, int_id_tracker* tracker)
		: repository_base<subscription>(provider, tracker)
	{
		
	}
};

