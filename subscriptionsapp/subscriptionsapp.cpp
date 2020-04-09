#include <iostream>
#include "card_repository.h"
#include "file_repository_uow.h"
#include "repository_uow.h"

using namespace std;

int main()
{
	repository_uow* repositories = new file_repository_uow;
	card_repository* repository = repositories->get_card_repository();

	card* c = new card;
	c->id = 3;
	c->number = "444314232";
	repository->add(c);

	vector<card*> cards = repository->get_collection();
	for (size_t i = 0; i < cards.size(); i++)
	{
		cout << "ID: " << cards[i]->id;
		cout << "Number: " << cards[i]->number;
		cout << endl << endl;
	}
}
