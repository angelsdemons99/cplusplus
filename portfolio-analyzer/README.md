# Portfolio Analyzer

A small C++ project for loading historical market data and exploring basic portfolio-analysis ideas.

This repository is still a work in progress, but it already includes sample stock data and utilities for reading price history, aligning multiple symbols, and calculating portfolio returns.

## Current Focus

- Load market data from text files in the data folder
- Inspect closing-price history for multiple symbols
- Align datasets to a common start date
- Calculate daily returns and portfolio-level statistics

## Project Structure

- data/ — sample market data files for AAPL, MSFT, and NVDA
- include/ — header files for market data, portfolio logic, and statistics helpers
- src/ — implementation files for the main program and supporting modules

## Build

From the repository root, build the project with:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Iportfolio-analyzer/include -o portfolio-analyzer/portfolio-analyzer.exe portfolio-analyzer/src/main.cpp portfolio-analyzer/src/MarketData.cpp portfolio-analyzer/src/Portfolio.cpp portfolio-analyzer/src/Statistics.cpp
```

## Run

```powershell
./portfolio-analyzer/portfolio-analyzer.exe
```

The program reads the sample data files from the data folder, aligns the price histories to their latest common start date, computes daily returns for AAPL, MSFT, and NVDA, and prints a portfolio summary. It also prompts for an investment amount and computes the cumulative portfolio value over the return series.

## Status

This is an early progress snapshot intended to share the current direction of the project and gather feedback. The current implementation now includes NVDA sample data and a weighted portfolio-return calculation for hard-coded positions.
