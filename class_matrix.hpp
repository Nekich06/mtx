#ifndef CLASS_MATRIX_HPP 
#define CLASS_MATRIX_HPP
#include <iostream>
#include "matrix.hpp"

struct Matrix 
{
public:
  Matrix(size_t m, size_t n): t_(::create_matrix(m, n)), m_(m), n_(n)
  {}
  Matrix(const Matrix & mtx): m_(mtx.m_), n_(mtx.n_)
  {
    t_ = ::create_matrix(m_, n_);
    for (size_t i = 0; i < m_; i++)
    {
      for (size_t j = 0; j < n_; j++)
      {
        t_[i][j] = mtx.t_[i][j];
      }
    }
  }
  void change_size(Matrix & mtx, size_t m_new, size_t n_new)
  {
    Matrix temp_mtx(mtx);
    ::del_matrix(mtx.t_, mtx.m_);
    mtx.m_ = m_new;
    mtx.n_ = n_new;
    mtx.t_ = ::create_matrix(m_new, n_new);
    mtx.fillUpMatrix(0);
    for (size_t i = 0; i < temp_mtx.m_; i++)
    {
      for (size_t j = 0; j < temp_mtx.n_; j++)
      {
        mtx.t_[i][j] = temp_mtx.t_[i][j];
      }
    }
  }

  void input(std::istream & in)
  {
    ::input_matrix(in, t_, m_, n_);
  }
  void output(std::ostream & out) const
  {
    ::output_matrix(out, t_, m_, n_);
  }
  void getNumRows() const
  {
    std::cout << "Number of rows is " << m_ << "\n";
  }
  void getNumColumns() const
  {
    std::cout << "Number of columns is " << n_ << "\n";
  }
  void fillUpMatrix(int value)
  {
    ::input_matrix(value, t_, m_, n_);
  }

  ~Matrix()
  {
    ::del_matrix(t_, m_);
  }

private:
  size_t m_, n_;
  int ** t_;
};

#endif