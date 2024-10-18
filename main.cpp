#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int ** t = nullptr;
  try
  {
    t = create_matrix(M, N);
    input_matrix(t, M, N);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "ERROR:Out of memory\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "ERROR:Invalid value\n";
    return 2;
  }
  output_matrix(t, M, N);
  del_matrix(t, M);
}

