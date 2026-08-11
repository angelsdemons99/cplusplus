#include <iostream>
#include <memory>

class B;

class A {
	public:
		std::shared_ptr<B> b;

		A() {
			std::cout << "A constructed \n";
		}
		~A() {
			std::cout << "A destroyed \n";
		}
};

class B {
	public:
		std::weak_ptr<A> a;

		B() {
			std::cout << "B constructed \n";
		}
		~B() {
			std::cout << "B destroyed\n";
		}
};

int main() {
	{
		auto a = std::make_shared<A>();
		auto b = std::make_shared<B>();

		a->b = b;
		b->a = a;

		std::cout << "A owners: " << a.use_count() << "\n";
		std::cout << "B owners: " << b.use_count() << "\n";
	
		std::cout << "leaving scope\n";
	}
	std::cout << "scope left\n";
}


