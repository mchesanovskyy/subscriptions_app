#pragma once
#include "card_subs_history.h"
#include "repository_base.h"

class card_subs_history_repository : public repository_base<card_subs_history>
{
public:
	explicit card_subs_history_repository(file_provider<card_subs_history>* provider)
		: repository_base<card_subs_history>(provider)
	{
		
	}
};

