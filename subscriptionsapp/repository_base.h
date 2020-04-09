#pragma once
#include "file_provider.h"
#include "entity_base.h"

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
	static_assert(std::is_base_of<entity_base, T>::value, "T must derive from entity_base");
	provider_ = provider;
}

template <class T>
repository_base<T>::~repository_base() = default;

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