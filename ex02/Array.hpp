#pragma once

#include <iostream>
template <typename T>
class Array {
public:
  Array(){this->arr = NULL; this->size = 0;};
  Array(unsigned int n){ 
	  this->arr = new T[n];
	  this->size = n;
	  for (unsigned int i = 0; i < n; i++)
		  this->arr[i] = 0;
  };
  Array(const Array& obj){
	  this->arr = new T[obj.size];
	  *this = obj;

  }
  ~Array(){delete this->arr;};
  Array& operator=(const Array& obj){
	  this->size = obj.size;
	  for (unsigned int i = 0; i < this->size; i++)
		  this->arr[i] = obj.arr[i];
	  return (*this);
  };
  T& operator[](const size_t index){
	  if (index >= this->size)
		  throw (std::exception());
	  return (this->arr[index]);
  }

  
private:
  T *arr;
  unsigned int size;
};

std::ostream&	operator<<(std::ostream& os, const Array&obj);

