#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
int ** create_matrix(size_t m, size_t n);
void del_matrix(int ** t, size_t m, size_t n);
void input_matrix(int ** t, size_t m, size_t n);
void output_matrix(const int * const * t, size_t m, size_t n);
#endif
