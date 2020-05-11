#pragma once
#include "service_base.h"
class location_service : public service_base<location>
{
public:
	location_service(repository_base<location>& repository, repository_uow& repositories)
		: service_base<location>(repository, repositories)
	{
		
	}

	void create_location(string name) const;
};

