#include <iostream>

#include "app_setting_manager.h"
#include "app_settings_initializer.h"
#include "card_repository.h"
#include "file_repository_uow.h"
#include "repository_uow.h"
#include "test_data.h"
using namespace std;


int main()
{
	// CHECK APP SETTINGS
	// add default values for required app settings if they are missed
	app_settings_initializer app_settings_initializer;
	app_settings_initializer.check_and_init_settings();
	
	repository_uow* repositories = new file_repository_uow;
	
	test_data test(repositories);
	test.run();
	test.show();
}
