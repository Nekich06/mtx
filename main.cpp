#include <iostream>
#include "matrix.hpp"
#include "class_matrix.hpp"

int main()
{
  size_t m = 0, n = 0;
  if (!(std::cin >> m >> n))
  {
    std::cerr << "ERROR:Invalid value\n";
    return 1;
  }
  Matrix mtx(m, n);
  mtx.input(std::cin);
  if (!std::cin)
  {
    std::cerr << "ERROR:Invaliud value\n";
    return 1;
  }
  mtx.output(std::cout);
}

