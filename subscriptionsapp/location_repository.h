#pragma once
#include "location.h"
#include "repository_base.h"

class location_repository : public repository_base<location>
{
public:
	explicit location_repository(file_provider<location>* provider, int_id_tracker* tracker)
		: repository_base<location>(provider, tracker)
	{
		
	}
};

