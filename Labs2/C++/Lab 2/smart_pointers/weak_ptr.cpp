#include "weak_ptr.h"

template <typename Type>
bool My_weak_ptr<Type>::expired() const
{
	return cpointer->shared_count == 0;
}

