#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  std::cout << M << " " << N << "\n";
  int ** t = create_matrix(M, N);
  input_matrix(t, M, N);
  output_matrix(t, M, N);
  del_matrix(t, M, N);
}

