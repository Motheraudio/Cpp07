#pragma once
template <typename T> 

void	swap(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
}
template <typename U>

U min(U &a, U &b)
{
	return (a < b) ? a : b;
}

template <typename V>

V max(V &a, V &b)
{
	return (a > b) ? a : b;
}
