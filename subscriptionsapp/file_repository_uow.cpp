#include "file_repository_uow.h"
#include "app_setting_keys.h"
#include "card_serializer.h"
#include "card_subs_history_serializer.h"
#include "card_subscription_serializer.h"
#include "location_serializer.h"
#include "subscription_serializer.h"
#include "default_id_tracker.h"

using namespace app_setting_keys;

file_repository_uow::file_repository_uow()
	: app_setting_manager_(app_setting_manager::get_instance())
{
}

card_repository* file_repository_uow::get_card_repository()
{
	if (card_repository_ == nullptr) {
		const auto serializer = new card_serializer;
		const auto file_path = app_setting_manager_.get_value(CARD_FILEPATH_KEY);
		auto* provider = new file_provider<card>(*serializer, file_path);
		auto* tracker = default_id_tracker::create(CARD_ID_TRACKER_KEY);
		card_repository_ = new card_repository(provider, tracker);
	}

	return card_repository_;
}

location_repository* file_repository_uow::get_location_repository()
{
	if (location_repository_ == nullptr) {
		const auto serializer = new location_serializer;
		const auto file_path = app_setting_manager_.get_value(LOCATION_FILEPATH_KEY);
		auto* provider = new file_provider<location>(*serializer, file_path);
		auto* tracker = default_id_tracker::create(LOCATION_ID_TRACKER_KEY);
		location_repository_ = new location_repository(provider, tracker);
	}

	return location_repository_;
}

card_subscription_repository* file_repository_uow::get_card_subscription_repository()
{
	if (card_subscription_repository_ == nullptr) {
		const auto serializer = new card_subscription_serializer;
		const auto file_path = app_setting_manager_.get_value(CARD_SUBSCRIPTION_FILEPATH_KEY);
		auto* provider = new file_provider<card_subscription>(*serializer, file_path);
		auto* tracker = default_id_tracker::create(CARD_SUBSCRIPTION_ID_TRACKER_KEY);
		card_subscription_repository_ = new card_subscription_repository(provider, tracker);
	}

	return card_subscription_repository_;
}

card_subs_history_repository* file_repository_uow::get_card_subs_history_repository()
{
	if (card_subs_history_repository_ == nullptr) {
		const auto serializer = new card_subs_history_serializer;
		const auto file_path = app_setting_manager_.get_value(CARD_SUBS_HISTORY_FILEPATH_KEY);
		auto* provider = new file_provider<card_subs_history>(*serializer, file_path);
		auto* tracker = default_id_tracker::create(CARD_SUBS_HISTORY_ID_TRACKER_KEY);
		card_subs_history_repository_ = new card_subs_history_repository(provider, tracker);
	}

	return card_subs_history_repository_;
}

subscription_repository* file_repository_uow::get_subscription_repository()
{
	if (subscription_repository_ == nullptr) {
		const auto serializer = new subscription_serializer;
		const auto file_path = app_setting_manager_.get_value(SUBSCRIPTION_FILEPATH_KEY);
		auto* provider = new file_provider<subscription>(*serializer, file_path);
		auto* tracker = default_id_tracker::create(SUBSCRIPTION_ID_TRACKER_KEY);
		subscription_repository_ = new subscription_repository(provider, tracker);
	}

	return subscription_repository_;
}
