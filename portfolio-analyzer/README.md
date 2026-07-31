# Portfolio Analyzer

A small C++ project for loading historical market data and exploring basic portfolio-analysis ideas.

This repository is still a work in progress, but it already includes sample stock data and early utilities for reading price history and preparing simple analyses.

## Current Focus

- Load market data from text files in the data folder
- Inspect closing-price history for multiple symbols
- Build foundational portfolio and statistics helpers

## Project Structure

- data/ — sample market data files for AAPL and MSFT
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

The program reads the sample data files from the data folder and prints a short summary of the loaded market data.

## Status

This is an early progress snapshot intended to share the current direction of the project and gather feedback.
