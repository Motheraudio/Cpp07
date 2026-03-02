#pragma once

#include <cstdlib>
#include <exception>
template <typename T> class Array
{
public:
  Array()
  {
    this->arr = NULL;
    this->sz = 0;
  };
  Array(unsigned int n)
  {
    this->sz = n;
    if (n == 0)
      this->arr = NULL;
    else
      this->arr = new T[n];
    for (unsigned int i = 0; i < n; i++)
      this->arr[i] = 0;
  };
  Array(const Array &obj) : sz(obj.sz)
  {
    if (obj.arr != NULL)
      this->arr = new T[obj.sz];
    else
      this->arr = NULL;
    *this = obj;
  }
  ~Array() { delete[] this->arr; };
  Array &operator=(const Array &obj)
  {
    if (this == &obj)
      return (*this);
    if (this->sz != obj.sz)
    {
      delete[] this->arr;
      this->arr = new T[obj.sz];
    }
    this->sz = obj.sz;
    for (unsigned int i = 0; i < this->sz; i++)
      this->arr[i] = obj.arr[i];
    return (*this);
  };
  T &operator[](const size_t index)
  {
    if (index >= this->sz)
      throw(std::exception());
    return (this->arr[index]);
  }
  unsigned int &size() { return (this->sz); }

private:
  T *arr;
  unsigned int sz;
};
