#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <vector>

struct MarketData
{
    std::string ticker;
    std::string per;
    std::string date;
    int time;
    double open;
    double high;
    double low;
    double close;
    long long volume;
    int openint;
};

std::vector<MarketData> loadMarketData(const std::string &filename);

void printMarketData(const std::vector<MarketData> &marketData);

std::vector<double> extractClosingPrices(const std::vector<MarketData> &marketData);

void trimToStartDate(std::vector<MarketData> &data, const std::string &startDate);

std::string findLatestCommonDate(std::vector<std::reference_wrapper<std::vector<MarketData>>> &datasets);

bool dataIsAligned(const std::vector<std::reference_wrapper<std::vector<MarketData>>> &datasets);

#endif