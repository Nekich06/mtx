#include <iostream>

int ** create_matrix(size_t m, size_t n);
void del_matrix(int ** t, size_t m, size_t n);

int main()
{
	size_t M = 0, N = 0;
	std::cin >> M >> N;
	std::cout << M << " " << N << "\n";
	int ** t = create_matrix(M, N);
	del_matrix(t, M, N);
}

