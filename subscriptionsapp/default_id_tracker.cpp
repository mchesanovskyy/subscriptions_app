#include "default_id_tracker.h"

default_id_tracker* default_id_tracker::create(string key)
{
	return new default_id_tracker(app_setting_manager::get_instance(), key);
}

int default_id_tracker::get_id()
{
	// get the latest used ID;
	const auto value = settings_manager_.get_value(track_key_);

	// init id variable
	int integer = 0;

	// 2. The value converts to integer it is not empty
	if (!value.empty())
	{
		integer = stoi(value);
	}

	// increment the value by one so it becomes a new ID
	++integer;

	// update the setting with a new ID
	settings_manager_.add_or_update_value(track_key_, to_string(integer));

	// return new ID
	return integer;
}
