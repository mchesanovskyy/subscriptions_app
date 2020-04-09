#pragma once
#include "card.h"
#include "repository_base.h"

class card_repository : public repository_base<card>
{
public:
	card_repository(file_provider<card>* provider);

	card* get_by_number(const string& number) const;
};
