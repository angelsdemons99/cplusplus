#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

double minimum(const std::vector<double> &numbers);
double maximum(const std::vector<double> &numbers);
double mean(const std::vector<double> &numbers);
double median(std::vector<double> numbers);
double variance(const std::vector<double> &numbers);
double standardDeviation(const std::vector<double> &numbers);
double dataRange(const std::vector<double> &numbers);
double mode(const std::vector<double> &numbers);

#endif