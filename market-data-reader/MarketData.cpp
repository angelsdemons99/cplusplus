#include "MarketData.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<MarketData> loadMarketData(const std::string &filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Could not open file: " << filename << '\n';
        return {};
    }

    std::vector<MarketData> marketData;
    std::string line;

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string open;
        std::string high;
        std::string low;
        std::string close;
        std::string volume;

        std::getline(ss, date, ',');
        std::getline(ss, open, ',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, close, ',');
        std::getline(ss, volume, ',');

        MarketData row = {
            date,
            std::stod(open),
            std::stod(high),
            std::stod(low),
            std::stod(close),
            std::stoi(volume)};

        marketData.push_back(row);
    }

    return marketData;
}

void printMarketData(const std::vector<MarketData> &marketData)
{
    for (const MarketData &row : marketData)
    {
        std::cout << "----------------\n";
        std::cout << "Date: " << row.date << '\n';
        std::cout << "Open: " << row.open << '\n';
        std::cout << "High: " << row.high << '\n';
        std::cout << "Low: " << row.low << '\n';
        std::cout << "Close: " << row.close << '\n';
        std::cout << "Volume: " << row.volume << '\n';
    }
}

std::vector<double> extractClosingPrices(
    const std::vector<MarketData> &marketData)
{
    std::vector<double> closingPrices;

    for (const MarketData &row : marketData)
    {
        closingPrices.push_back(row.close);
    }

    return closingPrices;
}