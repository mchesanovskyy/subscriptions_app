#pragma once
#include "file_provider.h"

template <class T>
class repository_base
{
protected:
	file_provider<T>* provider_;

	repository_base(file_provider<T>* provider);

public:
	virtual ~repository_base();
	virtual void add(T* entity);

	virtual vector<T*> get_collection();
};



template <class T>
repository_base<T>::repository_base(file_provider<T>* provider)
{
	provider_ = provider;
}

template <class T>
repository_base<T>::~repository_base()
{
}

template <class T>
vector<T*> repository_base<T>::get_collection()
{
	return provider_->get_collection();
}

template <class T>
void repository_base<T>::add(T* entity)
{
	provider_->append(entity);
}


