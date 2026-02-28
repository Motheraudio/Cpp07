#pragma once

#include <cstdlib>
#include <exception>
template <typename T>
class Array {
public:
  Array(){this->arr = NULL; this->sz = 0;};
  Array(unsigned int n){ 
	  this->arr = new T[n];
	  this->sz = n;
	  for (unsigned int i = 0; i < n; i++)
		  this->arr[i] = 0;
  };
  Array(const Array& obj){
	  this->arr = new T[obj.sz];
	  *this = obj;

  }
  ~Array(){delete[] this->arr;};
  Array& operator=(const Array& obj){
	  this->sz = obj.sz;
	  for (unsigned int i = 0; i < this->sz; i++)
		  this->arr[i] = obj.arr[i];
	  return (*this);
  };
  T& operator[](const size_t index){
	  if (index >= this->sz)
		  throw (std::exception());
	  return (this->arr[index]);
  }
  unsigned int& size() const{
	return (this->size);
  }
private:
  T *arr;
  unsigned int sz;
};


