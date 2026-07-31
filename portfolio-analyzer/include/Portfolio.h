#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <vector>

struct Position
{
    std::string symbol;
    double weight;
    std::vector<double> closingPrices;
};

std::vector<double> calculateDailyReturns(const std::vector<double> &prices);
std::vector<double> calculatePortfolioReturns(const std::vector<Position> &positions);

#endif