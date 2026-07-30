#include "MarketData.h"
#include "Statistics.h"

#include <iostream>
#include <vector>

int main()
{
    std::vector<MarketData> marketData = loadMarketData("market_data.csv");

    if (marketData.empty())
    {
        std::cout << "No market data loaded." << std::endl;
        return 1;
    }

    std::vector<double> closingPrices = extractClosingPrices(marketData);
    std::cout << "Closing-price statistics" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Minimum: " << minimum(closingPrices) << '\n';
    std::cout << "Maximum: " << maximum(closingPrices) << '\n';
    std::cout << "Mean: " << mean(closingPrices) << '\n';
    std::cout << "Median: " << median(closingPrices) << '\n';
    std::cout << "Variance: " << variance(closingPrices) << '\n';
    std::cout << "Standard deviation: " << standardDeviation(closingPrices) << '\n';
    std::cout << "Range: " << dataRange(closingPrices) << '\n';
}