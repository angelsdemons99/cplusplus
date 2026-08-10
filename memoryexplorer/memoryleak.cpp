#include <iostream>

int main() {
	int* ptr = new int(42);
	std::cout << ptr << std::endl;
	ptr = nullptr;
	std::cout << "after nullptr : ptr is " << ptr << std::endl;
	return 0;
}

