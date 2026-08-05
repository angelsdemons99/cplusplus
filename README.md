# C++ Practice Projects

A curated collection of beginner-friendly C++ exercises demonstrating console I/O, simple algorithms, file-based data processing, and early portfolio-analysis experiments.

## Projects

- `statsengine/` — command-line statistics calculator for mean, min/max, median, variance, standard deviation, range, and mode.
- `market-data-reader/` — CSV market data loader and pricing statistics demo.
- `portfolio-analyzer/` — early project for loading stock data (AAPL, MSFT, NVDA), aligning price histories, calculating portfolio returns, and estimating cumulative portfolio value.

## Build

Build each project with a C++17-compatible compiler. Example commands:

```powershell
cd c:\Users\dyao0\Desktop\c++
g++ -std=c++17 -O2 -Wall -Wextra -o statsengine\statsengine.exe statsengine\statsengine.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o market-data-reader\market-data-reader.exe market-data-reader\main.cpp market-data-reader\MarketData.cpp market-data-reader\Statistics.cpp
g++ -std=c++17 -O2 -Wall -Wextra -Iportfolio-analyzer\include -o portfolio-analyzer\portfolio-analyzer.exe portfolio-analyzer\src\main.cpp portfolio-analyzer\src\MarketData.cpp portfolio-analyzer\src\Portfolio.cpp portfolio-analyzer\src\Statistics.cpp
```

## Run

From the repository root, run the compiled executables like this:

```powershell
.\statsengine\statsengine.exe
.\market-data-reader\market-data-reader.exe
.\portfolio-analyzer\portfolio-analyzer.exe
```

The market data reader expects `market-data-reader\market_data.csv` in its working directory.
The portfolio analyzer reads sample data files from `portfolio-analyzer\data`.
