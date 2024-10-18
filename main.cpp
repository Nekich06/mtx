#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  if (!std::cin)
  {
    std::cerr << "ERROR:Invalid value\n";
    return 1;
  }
  int ** t = nullptr;
  try
  {
    t = create_matrix(M, N);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR:Out of memory\n";
    return 2;
  }
  input_matrix(t, M, N);
  if (!std::cin)
  {
    del_matrix(t, M);
    std::cerr << "ERROR:Invalid value\n";
    return 1;
  }
  output_matrix(t, M, N);
  del_matrix(t, M);
}

