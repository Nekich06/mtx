#ifndef CLASS_MATRIX_HPP
#define CLASS_MATRIX_HPP
#include "matrix.hpp"
#include <iostream>

struct Matrix 
{
public:
  Matrix(size_t m, size_t n): t_(::create_matrix(m, n)), m_(m), n_(n)
  {}

  Matrix(const Matrix & mtx) = default;

  void input(std::istream & in)
  {
    ::input_matrix(in, t_, m_, n_);
  }

  void output(std::ostream & out) 
  {
    ::output_matrix(out, t_, m_, n_);
  }

    ~Matrix()
  {
    ::del_matrix(t_, m_);
  }

  void getNumRows()
  {
    std::cout << "Number of rows is " << m_ << "\n";
  }

  void getNumColumns()
  {
    std::cout << "Number of columns is " << n_ << "\n";
  }

  void fillUpMatrix(int value)
  {
    ::input_matrix(value, t_, m_, n_);
  }

private:
  int ** t_;
  size_t m_, n_;
};
#endif