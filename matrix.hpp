#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

int ** create_matrix(size_t m, size_t n);
void del_matrix(int ** t, size_t m);
void input_matrix(std::istream & in, int ** t, size_t m, size_t n);
void input_matrix(int value, int ** t, size_t m, size_t n);
void output_matrix(std::ostream & out, const int * const * t, size_t m, size_t n);

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

  void input(std::istream & in);
  void output(std::ostream & out) const;
  void getNumRows() const;
  void getNumColumns() const;
  void fillUpMatrix(int value);
  void change_size(Matrix & mtx, size_t m_new, size_t n_new);

  ~Matrix()
  {
    ::del_matrix(t_, m_);
  }

private:
  size_t m_, n_;
  int ** t_;
};
#endif
