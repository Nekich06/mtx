#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

int ** create_matrix(size_t m, size_t n);
void del_matrix(int ** t, size_t m);
void input_matrix(std::istream & in, int ** t, size_t m, size_t n);
void output_matrix(std::ostream & out, const int * const * t, size_t m, size_t n);
#endif
