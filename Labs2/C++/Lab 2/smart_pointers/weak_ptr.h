#pragma once

#include "shared_ptr.h"

template <typename Type>
class My_weak_ptr 
{
private:
	
	My_shared_ptr::CBlock<Type>* cpointer;


public:
	
	My_weak_ptr(){}



	My_weak_ptr(const My_shared_ptr<Type>& pointer)
		: cpointer(pointer.cpointer) {};
	bool expired() const;
	My_shared_ptr<Type> lock() const;
	
	//~My_weak_ptr();


};