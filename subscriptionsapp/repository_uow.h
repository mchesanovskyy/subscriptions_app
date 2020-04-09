#pragma once
#include "card_repository.h"
class repository_uow
{
public:
	virtual card_repository* get_card_repository() = 0;
};