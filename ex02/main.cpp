#include "Array.hpp"
#include <cstdlib>
#include <iostream>

#define MAX_VAL 5
int main(int, char **)
{
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++)
  {
    const int value = rand();
    numbers[i] = value;
    // std::cout << numbers[i] << std::endl;
    mirror[i] = value;
    // std::cout << mirror[i] << std::endl;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    if (mirror[i] != numbers[i])
    {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try
  {
    numbers[-2] = 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
  try
  {
    numbers[MAX_VAL] = 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    numbers[i] = rand();
    // std::cout << numbers[i] << std::endl;
  }
  delete[] mirror;
  Array<int> yo(2);
  std::cout << yo.size() << std::endl;
  yo = numbers;
  std::cout << yo.size() << std::endl;
  return 0;
}
