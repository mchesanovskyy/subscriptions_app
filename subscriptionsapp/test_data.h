#pragma once
#include <iostream>

#include "repository_uow.h"

class test_data
{

public:
	test_data(repository_uow* uow) : uow_(uow) {

	}
	void run()
	{
		add_locations();
		add_subs();
		add_cards();
		add_card_subs();
		add_car_subs_histories();
	}

	void show()
	{
		show_locations();
		show_subscriptions();
		show_cards();
		show_card_subscriptions();
		show_history();
	}

private:

	void show_locations()
	{
		auto entities = uow_->get_location_repository()->get_collection();
		cout << "Locations" << endl;
		for (auto& entity : entities)
		{
			cout << "ID: " << entity->id << endl;
			cout << "Name: " << entity->name;
			cout << endl;
		}
	}

	void show_subscriptions()
	{
		auto entities = uow_->get_subscription_repository()->get_collection();
		cout << "subscriptions" << endl;
		for (auto& entity : entities)
		{
			cout << "ID: " << entity->id << endl;
			cout << "Name: " << entity->name << endl;
			cout << "Type: " << entity->type << endl;
			cout << "From: " << entity->effective_from->to_string() << endl;
			cout << "To: " << entity->effective_to->to_string() << endl;
			cout << "Hours: " << entity->hours << endl;
			cout << "Unit Title: " << entity->unit_title << endl;
			cout << endl;
		}
	}

	void show_cards()
	{
		auto entities = uow_->get_card_repository()->get_collection();
		cout << "cards" << endl;
		for (auto& entity : entities)
		{
			cout << "ID: " << entity->id << endl;
			cout << "Name: " << entity->number;
			cout << endl;
		}
	}

	void show_card_subscriptions()
	{
		auto entities = uow_->get_card_subscription_repository()->get_collection();
		cout << "card_subscriptions" << endl;
		for (auto& entity : entities)
		{
			cout << "ID: " << entity->id << endl;
			cout << "Created at: " << entity->created_at->to_string() << endl;
			cout << "CardId: " << entity->card_id << endl;
			cout << "SubscriptionId: " << entity->subscription_id << endl;
			cout << "From: " << entity->effective_from->to_string() << endl;
			cout << "To: " << entity->effective_to->to_string() << endl;
			cout << "Unit Count: " << entity->unit_count << endl;
			cout << endl;
		}
	}

	void show_history()
	{
		auto entities = uow_->get_card_subs_history_repository()->get_collection();
		cout << "History" << endl;
		for (auto& entity : entities)
		{
			cout << "ID: " << entity->id << endl;
			cout << "Created at: " << entity->created_at.to_string() << endl;
			cout << "CardId: " << entity->card_subscription_id << endl;
			cout << "Used: " << entity->units_used << endl;
			cout << endl;
		}
	}
	
	void add_car_subs_histories() const
	{
		auto repo = uow_->get_card_subs_history_repository();
		if (!repo->get_collection().empty())
		{
			return;
		}

		auto h = new card_subs_history;
		h->card_subscription_id = 12;
		h->created_at = date_time::now();
		h->units_used = 1;
		h->id = 4;

		repo->add(h);
	}

	void add_card_subs() const
	{
		auto repo = uow_->get_card_subscription_repository();
		if (!repo->get_collection().empty())
		{
			return;
		}

		auto cs = new card_subscription;
		cs->id = 12;
		cs->card_id = 1;
		cs->subscription_id = 1;
		cs->effective_from = &date_time::now();
		cs->effective_to = &date_time::parse("2022-03-04T10:00:00");
		cs->created_at = &date_time::now();
		cs->unit_count = 8;

		repo->add(cs);
	}

	void add_cards() const
	{
		auto repo = uow_->get_card_repository();
		if (!repo->get_collection().empty())
		{
			return;
		}

		auto c = new card;
		c->id = 1;
		c->number = "1234567890";

		repo->add(c);
	}

	void add_subs() const
	{
		auto repo = uow_->get_subscription_repository();
		if (!repo->get_collection().empty())
		{
			return;
		}

		auto s = new subscription;
		s->id = 1;
		s->name = "pay as you go";
		s->effective_from = &date_time::parse("2020-03-04T10:00:00");
		s->effective_to = &date_time::parse("2021-03-04T20:59:59");
		s->hours = 12;
		s->max_unit_count = 0;
		s->unit_title = "day";
		s->type = "PayAsYouGo";
		repo->add(s);
	}

	void add_locations() const
	{
		auto repo = uow_->get_location_repository();
		if (!repo->get_collection().empty())
		{
			return;
		}

		auto l = new location;
		l->id = 1;
		l->name = "gym";
		repo->add(l);
	}


	repository_uow* uow_;
};

