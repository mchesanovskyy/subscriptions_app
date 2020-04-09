#pragma once
#include "repository_uow.h"

class file_repository_uow : public repository_uow
{
	card_repository* card_repository_ = nullptr;
	location_repository* location_repository_ = nullptr;
	card_subscription_repository* card_subscription_repository_ = nullptr;
	card_subs_history_repository* card_subs_history_repository_ = nullptr;
	subscription_repository* subscription_repository_ = nullptr;
public:
	card_repository* get_card_repository() override;
	location_repository* get_location_repository() override;
	card_subscription_repository* get_card_subscription_repository() override;
	card_subs_history_repository* get_card_subs_history_repository() override;
	subscription_repository* get_subscription_repository() override;
};

