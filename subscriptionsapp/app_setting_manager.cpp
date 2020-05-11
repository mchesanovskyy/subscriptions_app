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
