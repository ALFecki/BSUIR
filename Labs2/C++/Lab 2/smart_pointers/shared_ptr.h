#pragma once


template <typename Type>
class My_shared_ptr
{
public:
	My_shared_ptr(Type* pointer = nullptr);
	My_shared_ptr(const My_shared_ptr&);
	My_shared_ptr(My_shared_ptr&&);
	int get_count() const;
	void operator=(My_shared_ptr&) const;
	Type& operator*() const;
	Type* operator->() const;
	~My_shared_ptr();
private:

	Type* pointer;
	int* count;
	
	template <typename OType, typename... Args>
	friend My_shared_ptr<OType> make_shared_ptr(Args&&... args);

	struct make_shared_t;

	struct CBlock {
		int shared_count;
		int weak_count;
		Type object;
	};

	CBlock<Type>* cpointer = nullptr;


	template <typename... Args>
	My_shared_ptr(make_shared_t, CBlock<Type>* storage_ptr)
		: cpointer(storage_ptr){}


};