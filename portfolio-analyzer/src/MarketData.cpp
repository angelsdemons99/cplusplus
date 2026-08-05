#include "../include/MarketData.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

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

        std::string ticker;
        std::string per;
        std::string date;
        std::string time;
        std::string open;
        std::string high;
        std::string low;
        std::string close;
        std::string volume;
        std::string openint;

        std::getline(ss, ticker, ',');
        std::getline(ss, per, ',');
        std::getline(ss, date, ',');
        std::getline(ss, time, ',');
        std::getline(ss, open, ',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, close, ',');
        std::getline(ss, volume, ',');
        std::getline(ss, openint, ',');

        MarketData row = {
            ticker,
            per,
            date,
            std::stoi(time),
            std::stod(open),
            std::stod(high),
            std::stod(low),
            std::stod(close),
            std::stoll(volume),
            std::stoi(openint)};

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

void trimToStartDate(std::vector<MarketData> &data, const std::string &startDate)
{
    auto it = std::find_if(data.begin(), data.end(), [startDate](const MarketData &row)
                           { return row.date == startDate; });
    if (it != data.end())
    {
        data.erase(data.begin(), it);
    }
    else
    {
        std::cout << "Could not find date." << std::endl;
    }
}

std::string findLatestCommonDate(std::vector<std::reference_wrapper<std::vector<MarketData>>> &datasets)
{
    std::vector<std::string> dates;
    for (auto &data : datasets)
    {
        if (!data.get().empty())
        {
            dates.push_back(data.get().front().date);
        }
    }
    std::string latestDate = dates[0];
    for (int i = 1; i < dates.size(); i++)
    {
        if (dates[i] > latestDate)
        {
            latestDate = dates[i];
        }
    }
    return latestDate;
}

bool dataIsAligned(const std::vector<std::reference_wrapper<std::vector<MarketData>>> &datasets)
{
    if (datasets.empty())
    {
        return false;
    }
    auto reference = datasets[0];
    for (size_t i = 1; i < datasets.size(); i++)
    {
        if (datasets[i].get().size() != reference.get().size())
        {
            return false;
        }
    }
    for (size_t i = 0; i < datasets.size(); i++)
    {
        for (size_t j = 0; j < reference.get().size(); j++)
        {
            if (datasets[i].get()[j].date != reference.get()[j].date)
            {
                return false;
            }
        }
    }

    return true;
}