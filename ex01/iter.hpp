#pragma once
#include <cstddef>
template <typename T>
void iter(T *arr, const size_t len, void f(T &param))
{
	for (size_t i = 0; i < len; i++)
		(f)(arr[i]);
}
template <typename U>
void iter(const U *arr, const size_t len, void f(const U &param))
{
	for (size_t i = 0; i < len; i++)
		(f)(arr[i]);
}
