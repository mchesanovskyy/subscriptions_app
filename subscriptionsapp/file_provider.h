#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "serializer.h"
#include "card.h"

using namespace std;

template< class T>
class file_provider
{
	serializer<T>* serializer_ = nullptr;
	string file_name_;

public:
	file_provider(serializer<T>& serializer, const string file_name) {
		serializer_ = &serializer;
		file_name_ = file_name;
	}
	
	vector<T*> get_collection() {
		ifstream reader(file_name_);
		vector<card*> entities;
		if (reader.is_open()) {
			string line;
			while (getline(reader, line))
			{
				T* entity = serializer_->to_object(line);
				if (entity != nullptr) {
					entities.push_back(entity);
				}
			}
			reader.close();
		}
		return entities;
	}

	void append(T* entity) {
		ofstream writer(file_name_, ios::app);
		if (writer.is_open()) {
			string line = serializer_->to_string(entity);
			writer << line << endl;
			writer.close();
		}
	}

	void append_range(vector<T*> entities) {
		ofstream writer(file_name_, ios::app);
		if (writer.is_open()) {

			for (size_t i = 0; i < entities.size(); i++)
			{
				string line = serializer_->to_string(entities[i]);
				writer << line << endl;
			}
			writer.close();
		}
	}

	bool clear() {
		std::ofstream ofs;
		ofs.open(file_name_, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		return true;
	}
};

