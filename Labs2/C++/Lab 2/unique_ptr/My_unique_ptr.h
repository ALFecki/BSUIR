#pragma once

#include<iostream>
#include<cassert>

template <class Type>
class My_unique_ptr
{

public:
	My_unique_ptr(Type* pointer = nullptr);
	~My_unique_ptr();
	My_unique_ptr(My_unique_ptr&);
	Type* get();
	Type* release();
	void operator=(My_unique_ptr&);
	Type& operator*();
	Type* operator->();

private:
	Type* pointer;
};

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



template <class Type>
class My_shared_ptr
{
public:
	My_shared_ptr(Type* pointer = nullptr);
	~My_shared_ptr();
	My_shared_ptr(My_shared_ptr&);
	Type* get();
	void operator=(My_shared_ptr&);
	Type& operator*();
	Type* operator->();
private:
	Type* pointer;
	int* count;
};

template <class Type>
My_shared_ptr<Type>::My_shared_ptr(Type* pointer)
	: pointer(pointer)
{}

template <class Type>
My_shared_ptr<Type>::~My_shared_ptr()
{
	if (!pointer)
	{
		return;
	}
	if (!--(*count))
	{
		delete pointer;
		delete count;
	}
}

template <class Type>
My_shared_ptr<Type>::My_shared_ptr(My_shared_ptr& new_pointer)
	:pointer(new_pointer.pointer), count(new_pointer.count)
{
	if (!pointer)
	{
		return;
	}
	++(*count);
}



