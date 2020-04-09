#include "file_repository_uow.h"

card_repository* file_repository_uow::get_card_repository()
{
	if (card_repository_ == nullptr) {
		const auto serializer = new card_serializer;
		auto* provider = new file_provider<card>(*serializer, "cards.txt");
		card_repository_ = new card_repository(provider);
	}

	return card_repository_;
}
