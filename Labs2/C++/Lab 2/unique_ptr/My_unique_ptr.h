#pragma once


template <class Type>
class My_unique_ptr
{

public:
	My_unique_ptr(T*);
	~My_unique_ptr();


private:
	T* pointer;
};

