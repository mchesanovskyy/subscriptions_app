#pragma once
#include "repository_base.h"
class card_repository : public repository_base<card>
{
public:
	card_repository(file_provider<card>* provider) : repository_base(provider) {

	}

	card* get_by_number(string number) {
		auto cards = provider_->get_collection();
		for (size_t i = 0; i < cards.size(); i++)
		{
			if (cards.at(i)->number == number) {
				return cards[i];
			}
		}
		return nullptr;
	}
};

