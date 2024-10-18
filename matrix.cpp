#include <iostream>
#include "matrix.hpp"

int ** create_matrix(size_t m, size_t n)
{
  int ** t = new int*[m];
  size_t created = 0;
  try
  {
    for(; created < m; ++created)
    {
      t[created] = new int[n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    del_matrix(t, created);
    throw;
  }
  return t;
}

void input_matrix(int ** t, size_t m, size_t n)
{
  try
  {
    for (size_t i = 0; i < m; ++i)
    {
      for (size_t j = 0; j < n; ++j)
      {
        std::cin >> t[i][j];
      }
    }
  }
  catch (const std::invalid_argument & e)
  {
    throw;
  }
}

void output_matrix(const int * const * t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    std::cout << t[i][0];
    for (size_t j = 1; j < n; ++j)
      {
        std::cout << " " << t[i][j];
      }
    std::cout << "\n";
  }
}

void del_matrix(int ** t, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] t[i];
  }
  delete[] t;
}
