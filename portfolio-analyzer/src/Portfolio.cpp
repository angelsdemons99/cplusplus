#include "..\include\Portfolio.h"

std::vector<double> calculateDailyReturns(const std::vector<double> &prices)
{
    std::vector<double> returns;

    if (prices.size() < 2)
    {
        return returns;
    }

    for (std::size_t i = 1; i < prices.size(); ++i)
    {
        double dailyReturn = (prices[i] - prices[i - 1]) / prices[i - 1];
        returns.push_back(dailyReturn);
    }

    return returns;
}