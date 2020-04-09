#include "file_repository_uow.h"

#include "card_serializer.h"
#include "card_subs_history_serializer.h"
#include "card_subscription_serializer.h"
#include "location_serializer.h"
#include "subscription_serializer.h"

card_repository* file_repository_uow::get_card_repository()
{
	if (card_repository_ == nullptr) {
		const auto serializer = new card_serializer;
		auto* provider = new file_provider<card>(*serializer, "cards.txt");
		card_repository_ = new card_repository(provider);
	}

	return card_repository_;
}

location_repository* file_repository_uow::get_location_repository()
{
	if (location_repository_ == nullptr) {
		const auto serializer = new location_serializer;
		auto* provider = new file_provider<location>(*serializer, "locations.txt");
		location_repository_ = new location_repository(provider);
	}

	return location_repository_;
}

card_subscription_repository* file_repository_uow::get_card_subscription_repository()
{
	if (card_subscription_repository_ == nullptr) {
		const auto serializer = new card_subscription_serializer;
		auto* provider = new file_provider<card_subscription>(*serializer, "cardSubscriptions.txt");
		card_subscription_repository_ = new card_subscription_repository(provider);
	}

	return card_subscription_repository_;
}

card_subs_history_repository* file_repository_uow::get_card_subs_history_repository()
{
	if (card_subs_history_repository_ == nullptr) {
		const auto serializer = new card_subs_history_serializer;
		auto* provider = new file_provider<card_subs_history>(*serializer, "cardSubsHistory.txt");
		card_subs_history_repository_ = new card_subs_history_repository(provider);
	}

	return card_subs_history_repository_;
}

subscription_repository* file_repository_uow::get_subscription_repository()
{
	if (subscription_repository_ == nullptr) {
		const auto serializer = new subscription_serializer;
		auto* provider = new file_provider<subscription>(*serializer, "subscriptions.txt");
		subscription_repository_ = new subscription_repository(provider);
	}

	return subscription_repository_;
}
