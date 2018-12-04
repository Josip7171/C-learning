#include <iostream>
#include <iomanip>

int main()
{
	int N = 0, M = 0, counter=1;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> M;
		counter *=M;
	}
	std::cout << counter;

}