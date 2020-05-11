#pragma once
#include "int_id_tracker.h"
#include "app_setting_manager.h"

/// The class tracks Ids for entities.
/// The default implementation uses app_setting_manager.h
/// to store the latest used ids
class default_id_tracker : public int_id_tracker
{
	string track_key_;
	app_setting_manager& settings_manager_;

public:
	default_id_tracker(app_setting_manager& settings_manager, string& track_key)
		: track_key_(std::move(track_key)),
		settings_manager_(settings_manager)
	{

	}

	/// The method of quick instance creation
	static default_id_tracker* create(string key);
	
	int get_id() override;
};

