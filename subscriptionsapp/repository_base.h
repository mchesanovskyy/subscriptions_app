#pragma once
#include "file_provider.h"
#include "entity_base.h"
#include "int_id_tracker.h"

template <class T>
class repository_base
{
protected:
	file_provider<T>* provider_;
	int_id_tracker* tracker_;

	repository_base(file_provider<T>* provider, int_id_tracker* tracker);

public:
	virtual ~repository_base();
	virtual void add(T* entity);

	virtual vector<T*> get_collection();
};

template <class T>
repository_base<T>::repository_base(file_provider<T>* provider, int_id_tracker* tracker): tracker_(tracker) {
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
	entity->id = tracker_->get_id();
	provider_->append(entity);
}