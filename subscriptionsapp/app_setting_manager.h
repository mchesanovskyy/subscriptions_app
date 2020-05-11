#pragma once
#include <ostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include "app_setting.h"
#include "string_helpers.h"

using namespace std;

class app_setting_manager
{
	app_setting_manager() = default;
	std::vector<app_setting*> settings_;
public:
	static app_setting_manager& get_instance();

	void add_value(string key, string value)
	{
		auto s = new app_setting;
		s->key = std::move(key);
		s->value = std::move(value);
		settings_.push_back(s);
		save_and_reload();
	}

	void add_or_update_value(const string& key, const string& value);

	string get_value(string key)
	{
		const auto setting = find(std::move(key));
		return setting == nullptr
			? ""
			: setting->value;
	}

private:
	string file_name_ = "settings.config";

	app_setting* find(const string key)
	{
		for (auto setting : get_settings())
		{
			if (equals_ignore_case(setting->key, key))
			{
				return setting;
			}
		}

		return nullptr;
	}

	std::vector<app_setting*>& get_settings()
	{
		if (settings_.empty())
		{
			load_settings();
		}

		return settings_;
	}

	void save_and_reload()
	{
		save_settings();
		load_settings();
	}

	void save_settings()
	{
		ofstream writer;
		writer.open("settings.config");
		for (size_t i = 0; i < settings_.size(); i++)
		{
			writer << settings_[i]->key << "|";
			writer << settings_[i]->value;
			writer << std::endl;
		}
		writer.close();
	}

	void load_settings()
	{
		settings_.clear();
		string line;
		ifstream myfile(file_name_);
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				vector<string> parts = split(line, '|');
				auto* u = new app_setting;
				u->key = parts[0];
				u->value = (parts.size() > 1) 
					? parts[1]
					: "";
				
				settings_.push_back(u);
			}
			myfile.close();
		}
	}
};

