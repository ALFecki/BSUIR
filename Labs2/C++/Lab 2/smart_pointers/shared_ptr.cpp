#include "shared_ptr.h"

template <class Type>
My_shared_ptr<Type>::My_shared_ptr(Type* pointer)
	: pointer(pointer), count(new int(1)) {}


template <class Type>
My_shared_ptr<Type>::My_shared_ptr(const My_shared_ptr& new_pointer)
	: pointer(new_pointer.pointer), count(new_pointer.count)
{
	if (!pointer)
	{
		return;
	}
	++(*count);
}

template <class Type>
My_shared_ptr<Type>::My_shared_ptr(My_shared_ptr&& new_pointer)
	: pointer(new_pointer.pointer), count(new_pointer.count)
{
	new_pointer.pointer = nullptr;
	new_pointer.count = nullptr;
}

template <class Type>
int My_shared_ptr<Type>::get_count() const
{
	return *count;
}

template <class Type>
void My_shared_ptr<Type>::operator=(My_shared_ptr& new_pointer) const
{
	delete pointer;
	pointer = new_pointer.pointer;
	new_pointer.pointer = nullptr;
}


template <class Type>
Type& My_shared_ptr<Type>::operator*() const
{
	assert(pointer);
	return *pointer;
}

template <class Type>
Type* My_shared_ptr<Type>::operator->() const
{
	assert(pointer);
	return pointer;
}

template <class Type>
My_shared_ptr<Type>::~My_shared_ptr()
{
	cpointer->shared_count -= 1;

	if (cpointer->shared_pointer > 0)
	{
		return;
	}
	if (cpointer->weak_pointer == 0)
	{
		delete cpointer;
		return;
	}

	cpointer->object.~Type();
}

template <typename Type, typename... Args>
My_shared_ptr<Type> make_shared_ptr(Args&&... args)
{
	auto pointer = new Type(std::forward<Args>(args)...);
	return My_shared_ptr<Type>(pointer);
}
