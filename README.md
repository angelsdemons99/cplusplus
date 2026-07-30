# C++ Practice Projects

A curated collection of beginner-friendly C++ exercises demonstrating console I/O, simple algorithms, and file-based data processing.

## Projects

- `helloworld/` — prints `Hello World` to the console.
- `statsengine/` — command-line statistics calculator for mean, min/max, median, variance, standard deviation, range, and mode.
- `swap/` — integer swapping example.
- `market-data-reader/` — CSV market data loader and pricing statistics demo.

## Build

Build each project with a C++17-compatible compiler. Example commands:

```powershell
cd c:\Users\dyao0\Desktop\c++
g++ -std=c++17 -O2 -Wall -Wextra -o helloworld\helloworld.exe helloworld\helloworld.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o statsengine\statsengine.exe statsengine\statsengine.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o swap\swap.exe swap\swap.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o market-data-reader\market-data-reader.exe market-data-reader\main.cpp market-data-reader\MarketData.cpp market-data-reader\Statistics.cpp
```

## Run

From the repository root, run the compiled executables like this:

```powershell
.\helloworld\helloworld.exe
.\statsengine\statsengine.exe
.\swap\swap.exe
.\market-data-reader\market-data-reader.exe
```

The market data reader expects `market-data-reader\market_data.csv` in its working directory.
