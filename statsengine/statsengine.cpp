#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

double minimum(const std::vector<double> &num_list)
{
    double min = num_list[0];
    for (int i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] < min)
        {
            min = num_list[i];
        }
    }
    return min;
}
double maximum(const std::vector<double> &num_list)
{
    double max = num_list[0];
    for (int i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] > max)
        {
            max = num_list[i];
        }
    }
    return max;
}

double mean(const std::vector<double> &num_list)
{
    double result = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        result += num_list[i];
    }
    result /= num_list.size();
    return result;
}
double variance(const std::vector<double> &num_list)
{
    double average = mean(num_list);
    double sum = 0;
    for (int i = 0; i < num_list.size(); i++)
    {
        sum += (average - num_list[i]) * (average - num_list[i]);
    }
    sum /= num_list.size();
    return sum;
}
double standardDeviation(const std::vector<double> &num_list)
{
    return sqrt(variance(num_list));
}
double median(std::vector<double> num_list)
{

    std::sort(num_list.begin(), num_list.end());

    double median;
    if (num_list.size() % 2 == 0)
    {
        median = (num_list[num_list.size() / 2 - 1] + num_list[num_list.size() / 2]) / 2;
    }
    else if (num_list.size() % 2 != 0)
    {
        median = num_list[num_list.size() / 2];
    }
    return median;
}
double dataRange(const std::vector<double> &num_list)
{
    return maximum(num_list) - minimum(num_list);
}

double mode(const std::vector<double> &num_list)
{
    std::unordered_map<double, int> freqMap;
    double mostFreq = num_list[0];
    double maxCount = 0;

    for (int num : num_list)
    {
        freqMap[num]++;
        if (freqMap[num] > maxCount)
        {
            maxCount = freqMap[num];
            mostFreq = num;
        }
    }

    return mostFreq;
}

int main()
{

    int size;

    std::cout << "How many numbers? " << std::endl;
    std::cin >> size;
    if (size <= 0)
    {
        std::cout << "Please enter at least one number." << std::endl;
        return 1;
    }
    std::cout << "Enter numbers : " << std::endl;
    std::vector<double> numbers(size);
    for (double i = 0; i < size; i++)
    {
        std::cin >> numbers[i];
    }

    std::cout << "Mean = " << mean(numbers) << std::endl;
    std::cout << "Minimum = " << minimum(numbers) << std::endl;
    std::cout << "Maximum = " << maximum(numbers) << std::endl;
    std::cout << "Median = " << median(numbers) << std::endl;
    std::cout << "Variance = " << variance(numbers) << std::endl;
    std::cout << "Standard deviation = " << standardDeviation(numbers) << std::endl;
    std::cout << "Range = " << dataRange(numbers) << std::endl;
    std::cout << "Mode = " << mode(numbers) << std::endl;

    return 0;
}