#include <iostream>
#include "matrix.hpp"
void input_matrix(int ** t, size_t m, size_t n) {
	for (size_t i = 0; i < M; ++i) {
		for (size_t j = 0; j < N; ++i) {
			std::cin >> t[i][j];
		}
	}
}
void output_matrix(const int * const * t, size_t m, size_t n) {
	for (size_t i = 0; i < M; ++i) {
		std::cout << t[i][0];
		for (size_t j = 0; j < m; ++i) {
			std::cout << " " << t[i][j];
			std::cout << "\n";
		}
	}
}
void del_matrix(int ** t, size_t m) {
	for (size_t i = 0; i < M; ++i) {
		delete[] t[i];
	}
	delete[] t;
}

