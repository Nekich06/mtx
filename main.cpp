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
  mtx.getNumRows(); // Method #1
  mtx.getNumColumns(); // Method #2
  std::cout << "Output of first matrix:\n";
  mtx.output(std::cout);
  Matrix mtx_2(mtx); // Copy-constructor
  std::cout << "Output of second matrix, which is copied from first:\n";
  mtx_2.output(std::cout);
  mtx_2.fillUpMatrix(1); // Method #3
  std::cout << "Output of second matrix after filling up it with other value:\n";
  mtx_2.output(std::cout);
  std::clog << "Check output of first:\n";
  mtx.output(std::cout);
}

