#pragma once
#include "stdafx.h"
#include "Swappity.hpp"

using std::vector;
//template <typename Type> using iter = std::iterator<std::random_access_iterator_tag, Type>;

/*	(Bad) implementation of Quicksort. This produces a new array instead of sorting in-place.
@param param	Array to be sorted.
@param size		Size of param.
@return			New array with the elements of param now sorted.
*/
template <typename Type> void nMTQSort(Type* const left, Type* const right)
{
	if (std::distance(left,right)<2)
		return;

	std::thread		*lw     = nullptr,
					*rw     = nullptr;
	Type			*pivot  = right;
	static size_t	threads = 0,
					maxth   = std::thread::hardware_concurrency();

	for (Type* i = left; std::distance(i, pivot) > 0; ++i)
		if (*i >= *pivot)
		{
			auto tmp = pivot;
			swappity(i, tmp, --pivot);
		}
	
	if (threads < maxth)
	{
		void (*func)(Type* const, Type* const) = &nMTQSort<Type>;
		lw = new std::thread(func, left, (pivot - 1));
		++threads;
		if (threads < maxth)
		{
			rw = new std::thread(func, (pivot + 1), right);
			++threads;
		}
		else
			nMTQSort(pivot + 1, right);
	}

	else
	{
		nMTQSort(left, pivot - 1);
		nMTQSort(pivot + 1, right);
	}

	if (lw)
	{
		lw->join();
		delete lw;
		--threads;
	}

	if (rw)
	{
		rw->join();
		delete rw;
		--threads;
	}
}

template <typename Type> void nMTQSort(vector<Type>& param)
{
	nMTQSort(&*param.begin(), &*param.end());
}

template <typename Type> vector<Type>* nMTQSort(const vector<Type>& param)
{
	vector<Type> res = new vector<Type>{ param };
	nMTQSort(&*res->begin(), &*res->end());
	return res;
}

template <typename Type> void nMTQSort(Type param[], const size_t& size)
{
	nMTQSort(param, param + size - 1);
}

template <typename Type> Type* nMTQSort(const Type param[], const size_t& size)
{
	auto res = new Type[size];
	for (size_t i = 0; i < size; ++i)
		res[i] = param[i];
	nMTQSort(res, res + size - 1);
	return res;
}