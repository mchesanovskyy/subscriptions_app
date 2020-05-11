#include "location_service.h"

#include <utility>

void location_service::create_location(string name) const
{
	// create a new instance of location
	location* new_location = new ::location;

	// set name of the location
	new_location->name = std::move(name);

	// pass the instance to the location repository.
	// The location repository is responsible for storing data in the storage.
	repository_.add(new_location);
}
