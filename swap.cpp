#include <iostream>
using namespace std;

int main(void)
{
    int x, y;
    std::cout << "Enter an integer : ";
    std::cin >> x;
    std::cout << "Enter a larger integer : ";
    std::cin >> y;
    if (y > x)
    {
        int temp = x;
        x = y;
        y = temp;
    } // temp dies here
    std::cout << "The smaller value is " << y << std::endl;
    std::cout << "The larger value is " << x << std::endl;

} // x and y die here