#pragma once
#include "repository_uow.h"
#include "card_serializer.h"

class file_repository_uow : public repository_uow
{
	card_repository* card_repository_ = nullptr;
public:
	card_repository* get_card_repository() override;
};

