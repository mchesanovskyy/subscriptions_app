#pragma once
#include <map>
#include "app_setting_manager.h"
#include "app_setting_keys.h"
using namespace app_setting_keys;

class app_settings_initializer
{
	/// first = app_setting key,
	/// last = default value for the setting
	map<string, string> _defaultSettings = 
	{
		{LOCATION_FILEPATH_KEY,"location.txt"},
		{SUBSCRIPTION_FILEPATH_KEY,"subs.txt"},
		{CARD_SUBSCRIPTION_FILEPATH_KEY,"card_subs.txt"},
		{CARD_FILEPATH_KEY,"card.txt"},
		{CARD_SUBS_HISTORY_FILEPATH_KEY,"card_subs_history.txt"},
	};
	
public:
	void check_and_init_settings()
	{
		auto settings = app_setting_manager::get_instance();

		// check if all default settings exists
		for (const auto& default_setting : _defaultSettings)
		{
			// try get value by default setting key
			auto value = settings.get_value(default_setting.first);

			if(value.empty())
			{
				// add default app setting if not exists
				settings.add_value(default_setting.first, default_setting.second);
			}
		}
	}
};

