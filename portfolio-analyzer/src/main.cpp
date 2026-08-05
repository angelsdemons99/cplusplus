#include <iostream>
#include <vector>
#include "..\\include\\Portfolio.h"
#include "..\\include\\MarketData.h"
#include "..\\include\\Statistics.h"

int main()
{
    std::vector<MarketData> aapl_data = loadMarketData("data\\aapl.us.txt");
    std::vector<MarketData> msft_data = loadMarketData("data\\msft.us.txt");
    std::vector<MarketData> nvda_data = loadMarketData("data\\nvda.us.txt");
    std::vector<double> aaplClosingPrices;
    std::vector<double> msftClosingPrices;
    std::vector<double> nvdaClosingPrices;

    std::vector<std::reference_wrapper<std::vector<MarketData>>> datasets{
        std::ref(aapl_data),
        std::ref(msft_data),
        std::ref(nvda_data)};
    std::string latestDate = findLatestCommonDate(datasets);

    for (auto &datasetReference : datasets)
    {
        trimToStartDate(datasetReference.get(), latestDate);
    }
    for (const MarketData &price : aapl_data)
    {
        aaplClosingPrices.push_back(price.close);
    }
    for (const MarketData &price : msft_data)
    {
        msftClosingPrices.push_back(price.close);
    }
    for (const MarketData &price : nvda_data)
    {
        nvdaClosingPrices.push_back(price.close);
    }

    bool aligned = dataIsAligned(datasets);

    std::cout << "AAPL # of records: " << aapl_data.size() << std::endl;
    std::cout << "NVDA # of records: " << nvda_data.size() << std::endl;
    std::cout << "MSFT # of records: " << msft_data.size() << std::endl;
    std::cout << "Latest Date = " << latestDate << std::endl;
    std::cout << "AAPL Start Date  (* TRIMMED *)= " << aapl_data[0].date << std::endl;
    std::cout << "NVDA Start Date  (* TRIMMED *)= " << nvda_data[0].date << std::endl;
    std::cout << "MSFT Start Date  (* TRIMMED *)= " << msft_data[0].date << std::endl;
    std::cout << "Data is aligned? " << aligned << std::endl;
    std::vector<double> aaplDailyReturns = calculateDailyReturns(aaplClosingPrices);
    std::vector<double> msftDailyReturns = calculateDailyReturns(msftClosingPrices);
    std::vector<double> nvdaDailyReturns = calculateDailyReturns(nvdaClosingPrices);
    std::cout << "AAPL # of returns: " << aaplDailyReturns.size() << std::endl;
    std::cout << "MSFT # of returns: " << msftDailyReturns.size() << std::endl;
    std::cout << "NVDA # of returns: " << nvdaDailyReturns.size() << std::endl;
    Position aaplPosition = {"AAPL", 0.50, aaplDailyReturns};
    Position msftPosition = {"MSFT", 0.30, msftDailyReturns};
    Position nvdaPosition = {"NVDA", 0.20, nvdaDailyReturns};
    std::vector<Position> positions = {aaplPosition, msftPosition, nvdaPosition};
    auto returns = calculatePortfolioReturns(positions);
    std::cout << "Portfolio Summary" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Mean Daily Return : " << mean(returns) << std::endl;
    std::cout << "Standard Deviation : " << standardDeviation(returns) << std::endl;
    std::cout << "Minumum Daily Return : " << minimum(returns) << std::endl;
    std::cout << "Maximum Daily Return : " << maximum(returns) << std::endl;
    std::cout << "Number of Trading Days : " << aaplClosingPrices.size() << std::endl;
    std::cout << "How much are you investing?" << std::endl;
    double principal;
    std::cin >> principal;
    std::cout << "Cumulative Return over this time-series : $" << portfolioValue(principal, returns) << std::endl;

    return 0;
}