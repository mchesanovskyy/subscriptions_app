#include  "card_repository.h"

card_repository::card_repository(file_provider<card>* provider): repository_base(provider)
{
}

card* card_repository::get_by_number(const string& number) const
{
	auto cards = provider_->get_collection();
	for (auto& card : cards)
	{
		if (card->number == number)
		{
			return card;
		}
	}
	return nullptr;
}
