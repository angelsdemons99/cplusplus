#include <iostream>
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
std::vector<double> calculatePortfolioReturns(const std::vector<Position> &positions)
{
    std::vector<double> returns;
    if (!positions.empty())
    {
        auto size = positions[0].dailyReturns.size();
        for (const auto &pos : positions)
        {
            if (pos.dailyReturns.size() == size)
            {
                continue;
            }
            else
            {
                std::cout << "Daily returns not aligned." << std::endl;
                return returns;
            }
        }
        double weight = 0;
        for (const auto &pos : positions)
        {
            weight += pos.weight;
        }
        if (weight == 1.0)
        {
            for (size_t i = 0; i < positions[0].dailyReturns.size(); i++)
            {
                double portfolioReturn = 0;
                for (size_t j = 0; j < positions.size(); j++)
                {
                    portfolioReturn += positions[j].dailyReturns[i] * positions[j].weight;
                }
                returns.push_back(portfolioReturn);
            }
        }
        else
        {
            std::cout << "weights misaligned." << std::endl;
        }
    }
    return returns;
}