#include "unique_ptr.h"

template <class Type>
My_unique_ptr<Type>::My_unique_ptr(Type* pointer_)
	: pointer(pointer_)
{}

template <class Type>
My_unique_ptr<Type>::~My_unique_ptr()
{
	std::cout << "\nDeleted";
	delete pointer;
}

template <class Type>
My_unique_ptr<Type>::My_unique_ptr(My_unique_ptr& new_pointer)
	: pointer(new_pointer)
{
	new_pointer.pointer = nullptr;
}

template <class Type>
Type* My_unique_ptr<Type>::get()
{
	return pointer;
}

template <class Type>
Type* My_unique_ptr<Type>::release()
{
	Type* temp = pointer;
	pointer = nullptr;
	return temp;
}


template <class Type>
void My_unique_ptr<Type>::operator=(My_unique_ptr& new_pointer)
{
	delete pointer;
	pointer = new_pointer.pointer;
	new_pointer.pointer = nullptr;
}


template <class Type>
Type& My_unique_ptr<Type>::operator*()
{
	assert(pointer);
	return *pointer;
}

template <class Type>
Type* My_unique_ptr<Type>::operator->()
{
	assert(pointer);
	return pointer;
}

template <typename Type, typename... Args>
My_unique_ptr<Type> make_unique_ptr(Args&&... args)
{
	return My_unique_ptr<Type>(new Type(std::forward<Args>(args)...));
}

