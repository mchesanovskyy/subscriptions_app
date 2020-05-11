#include <iostream>

#include "app_setting_manager.h"
#include "app_settings_initializer.h"
#include "card_repository.h"
#include "file_repository_uow.h"
#include "repository_uow.h"
#include "test_data.h"
using namespace std;


void init_test_data()
{
	// create an instance of Repository UnitOfWork
	repository_uow* repositories = new file_repository_uow;

	// Create an instance of test_data class.
	// The test_data class takes the instance of repository_uow in constructor.
	test_data test(repositories);

	// Populate default values if no data
	test.run();

	// Display all collections
	test.show();
}

int main()
{
	// CHECK APP SETTINGS
	// add default values for required app settings if they are missed
	app_settings_initializer app_settings_initializer;
	app_settings_initializer.check_and_init_settings();

	// For testing purposes.
	// The method sets default values for all existing collections
	init_test_data();
}
