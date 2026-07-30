#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <vector>

struct MarketData
{
    std::string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
};

std::vector<MarketData> loadMarketData(const std::string &filename);

void printMarketData(const std::vector<MarketData> &marketData);

std::vector<double> extractClosingPrices(
    const std::vector<MarketData> &marketData);

#endif