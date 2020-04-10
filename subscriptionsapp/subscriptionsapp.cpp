#include <iostream>
#include "card_repository.h"
#include "file_repository_uow.h"
#include "repository_uow.h"
#include "test_data.h"
using namespace std;

int main()
{
	repository_uow* repositories = new file_repository_uow;
	
	test_data test(repositories);
	test.run();
	test.show();
}
