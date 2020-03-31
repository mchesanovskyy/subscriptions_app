#pragma once
#include "card_repository.h"
#include "card_serializer.h"
class repository_uow
{
public:
	virtual card_repository* get_card_repository() = 0;
};

class file_repository_uow : public repository_uow
{
	card_repository* card_repository_ = nullptr;
public:
	card_repository* get_card_repository() override;
};

inline card_repository* file_repository_uow::get_card_repository()
{
	if (card_repository_ == nullptr) {
		card_serializer* serialiizer = new card_serializer;
		file_provider<card>* provider = new file_provider<card>(*serialiizer, "cards.txt");
		card_repository_ = new card_repository(provider);
	}

	return card_repository_;
}
