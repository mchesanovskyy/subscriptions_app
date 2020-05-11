#include "app_setting_manager.h"

app_setting_manager& app_setting_manager::get_instance()
{
	static app_setting_manager* instance_;
	if (instance_ == nullptr)
	{
		instance_ = new app_setting_manager;
	}
	return *instance_;

}

void app_setting_manager::add_or_update_value(const string& key, const string& value)
{
	// try find setting by key;
	auto setting = find(key);
	if (setting == nullptr)
	{
		// add a new setting
		add_value(key, value);
	}
	else
	{
		// update the existing one
		setting->value = value;
	}

	// in both cases
	save_and_reload();
}
