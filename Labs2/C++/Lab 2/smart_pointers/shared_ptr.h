#pragma once

#include "unique_ptr.h"

template <typename Type>
class My_shared_ptr
{

private:

	template <typename Type>
	struct CBlock {
		int shared_count;
		int weak_count;
		Type object;
	};

	Type* pointer;
	int* count;
	CBlock<Type>* cpointer = nullptr;

	struct make_shared_t;

	template <typename Type> // private constructor with CBlock
	My_shared_ptr(make_shared_t, CBlock<Type>* storage_ptr)
		: cpointer(storage_ptr) {}

public:
	My_shared_ptr() {}
	
	My_shared_ptr(Type* pointer = nullptr)
		: pointer(pointer), count(new int(1)) {}
	
	My_shared_ptr(const My_shared_ptr& new_pointer)
		: pointer(new_pointer.pointer), count(new_pointer.count)
	{
		if (!pointer)
		{
			return;
		}
		++(*count);
	}
	
	My_shared_ptr(My_shared_ptr&& new_pointer)
		: pointer(new_pointer.pointer), count(new_pointer.count)
	{
		new_pointer.pointer = nullptr;
		new_pointer.count = nullptr;
	}

	int get_count() const
	{
		return *count;
	}
	
	void operator=(My_shared_ptr& new_pointer) const
	{
		delete pointer;
		pointer = new_pointer.pointer;
		new_pointer.pointer = nullptr;
	}
	Type& operator*() const
	{
		assert(pointer);
		return *pointer;
	}
	Type* operator->() const
	{
		assert(pointer);
		return pointer;
	}


	~My_shared_ptr()
	{
		cpointer->shared_count -= 1;

		if (cpointer->shared_count > 0)
		{
			return;
		}
		if (cpointer->weak_count == 0)
		{
			delete cpointer;
			return;
		}

		cpointer->object.~Type();
	}
	
	
	template <typename OType, typename... Args>
	friend My_shared_ptr<OType> make_shared_ptr(Args&&... args);


};

template <typename Type, typename... Args>
My_shared_ptr<Type> make_shared_ptr(Args&&... args)
{
	auto pointer = new My_shared_ptr::CBlock<Type>(1, std::forward<Args>(args)...);
	return My_shared_ptr<Type>(pointer);
}


