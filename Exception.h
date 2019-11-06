#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct EmptyHeap : public exception
{
	const char* what() const throw ()
	{
		return "Heap is empty.";
	}
};

#endif