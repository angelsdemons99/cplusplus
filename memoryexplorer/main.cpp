#include <iostream>

int main()
{
	int numbers[3] = {10,20,30};
	int* ptr = numbers;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	return 0;
}
