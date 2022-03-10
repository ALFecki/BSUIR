#pragma once


template <class Type>
class My_unique_ptr
{

public:
	My_unique_ptr(Type* pointer = nullptr);
	~My_unique_ptr();
	My_unique_ptr(My_unique_ptr&);
	void operator=(My_unique_ptr&);
	Type& operator*();
	Type& operator->();

private:
	Type* pointer;
};

