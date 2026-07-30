# Market Data Reader

A small C++ console application that loads CSV market price data, parses daily fields, and prints each record.

## Contents

- `main.cpp` – program entry point and user output
- `MarketData.h` / `MarketData.cpp` – data structures and CSV loading
- `Statistics.h` / `Statistics.cpp` – statistical utilities for numeric data
- `market_data.csv` – sample dataset used by the application

## Build

From the `market-data-reader` folder, compile with a C++17-compatible compiler:

```powershell
cd c:\Users\dyao0\Desktop\c++\market-data-reader
g++ -std=c++17 -O2 -Wall -Wextra -o market_reader.exe main.cpp MarketData.cpp Statistics.cpp
```

## Run

```powershell
.\market_reader.exe
```

The program loads `market_data.csv` from the current folder and prints the parsed market data records.

## Notes

- Ensure `market_data.csv` is present in the same directory as the executable.
- If the file cannot be opened, the program will print an error message and exit.
