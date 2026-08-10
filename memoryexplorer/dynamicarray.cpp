#include <iostream>

int main() {
	int size;
	std::cin >> size;
	int* numbers = new int[size];
	for (int i = 0; i < size; i++) {
		numbers[i] = i + 1;
	}
	delete[] numbers;
	numbers = nullptr;
	return 0;
}

