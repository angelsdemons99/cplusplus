#include <iostream>

int main(){
	int stackValue = 10;
	int* heapPtr = new int(42);
	std::cout << "break here\n";
	delete heapPtr;
	int* heapPtrTwo = new int(24);
	std::cout << "break here\n";
	return 0;
}

