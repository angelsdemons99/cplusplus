#include <iostream>


void inspectStack(){
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;
}

int main()
{
	int numbers[3] = {10,20,30};
	int* ptr = numbers;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	inspectStack();	
	return 0;	
}
