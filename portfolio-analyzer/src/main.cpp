#include <iostream>
#include <vector>
#include "..\\include\\Portfolio.h"
#include "..\\include\\MarketData.h"
#include "..\\include\\Statistics.h"

int main()
{
    std::vector<MarketData> aapl_data = loadMarketData("data\\aapl.us.txt");
    std::vector<MarketData> msft_data = loadMarketData("data\\msft.us.txt");
    std::vector<double> aaplClosingPrices;
    std::vector<double> msftClosingPrices;
    for (const MarketData &price : aapl_data)
    {
        aaplClosingPrices.push_back(price.close);
    }
    for (const MarketData &price : msft_data)
    {
        msftClosingPrices.push_back(price.close);
    }
    std::cout << "AAPL # of records : " << aaplClosingPrices.size() << std::endl;
    std::cout << "MSFT # of records : " << msftClosingPrices.size() << std::endl;
    std::cout << "AAPL Start date : " << aapl_data[0].date << std::endl;
    std::cout << "AAPL End date : " << aapl_data[aapl_data.size() - 1].date << std::endl;
    std::cout << "MSFT Start date : " << msft_data[0].date << std::endl;
    std::cout << "MSFT End date : " << msft_data[msft_data.size() - 1].date << std::endl;
    std::cout << ("19860313" < "20260730") << std::endl;
}