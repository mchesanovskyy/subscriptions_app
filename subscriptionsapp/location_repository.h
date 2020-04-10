#pragma once
#include "location.h"
#include "repository_base.h"

class location_repository : public repository_base<location>
{
public:
	explicit location_repository(file_provider<location>* provider)
		: repository_base<location>(provider)
	{
		
	}
};

