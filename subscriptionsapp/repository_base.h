#pragma once
#include "file_provider.h"

template <class T>
class repository_base
{
protected:
	file_provider<T>* provider_;

	repository_base(file_provider<T>* provider)
	{
		provider_ = provider;
	}

public:
	virtual void add(T* entity) {
		provider_->append(entity);
	}

	virtual vector<T*> get_collection() {
		return provider_->get_collection();
	}
};

