#pragma once
#include "repository_base.h"
#include "repository_uow.h"

template <class T>
class service_base
{
protected:
	repository_base<T>& repository_;
	repository_uow& repositories_;

	service_base(repository_base<T>& repository, repository_uow& repositories)
		: repository_(repository),
		  repositories_(repositories)
	{
		
	}
};