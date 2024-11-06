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

void input_matrix(std::istream & in, int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      std::cin >> t[i][j];
    }
  }
}

void input_matrix(int value, int ** t, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      t[i][j] = value;
    }
  }
}

void output_matrix(std::ostream & out, const int * const * t, size_t m, size_t n)
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

void Matrix::input(std::istream & in)
{
  ::input_matrix(in, t_, m_, n_);
}

void Matrix::output(std::ostream & out) const
{
  ::output_matrix(out, t_, m_, n_);
}

void Matrix::getNumRows() const
{
  std::cout << "Number of rows is " << m_ << "\n";
}

void Matrix::getNumColumns() const
{
  std::cout << "Number of columns is " << n_ << "\n";
}

void Matrix::fillUpMatrix(int value)
{
  ::input_matrix(value, t_, m_, n_);
}

void Matrix::change_size(Matrix & mtx, size_t m_new, size_t n_new)
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