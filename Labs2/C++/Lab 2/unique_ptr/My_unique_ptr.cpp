#include "My_unique_ptr.h"


template <class Type>
My_unique_ptr<Type>::My_unique_ptr(Type* pointer_)
	: pointer(pointer_)
{}

template <class Type>
My_unique_ptr<Type>::~My_unique_ptr()
{
	delete pointer;
}

template <class Type>
My_unique_ptr<Type>::My_unique_ptr(My_unique_ptr& new_pointer)
	: pointer(new_pointer)
{
	new_pointer.pointer = nullptr;
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
	return pointer;
}
