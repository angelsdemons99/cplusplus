# C++ Practice Projects

A collection of C++ projects and experiments focused on core language skills, data processing, quantitative-finance foundations, and low-level systems concepts.

## Projects

- `statsengine/` — command-line statistics calculator for mean, min/max, median, variance, standard deviation, range, and mode.
- `market-data-reader/` — CSV market data loader and pricing statistics demo.
- `portfolio-analyzer/` — project for loading stock data (AAPL, MSFT, NVDA), aligning price histories, calculating portfolio returns, and estimating cumulative portfolio value.
- `memoryexplorer/` — hands-on C++/GDB project for understanding how objects, pointers, stack frames, dynamic allocations, object lifetimes, and ownership behave in memory.

---

## Memory Explorer

Memory Explorer is a low-level learning project built with C++ and GDB on Windows/MSYS2.

The goal is to connect C++ source code to its actual runtime representation: addresses, raw bytes, stack frames, heap allocations, object lifetimes, resource ownership, and eventually virtual memory and CPU behavior.

### Phase 1 — Memory & Pointers ✅

Concepts explored:

- Values vs. memory addresses
- Address-of (`&`) and dereference (`*`)
- Difference between `ptr`, `&ptr`, and `*ptr`
- Hexadecimal representation
- Inspecting raw memory with GDB
- Little-endian byte ordering
- Least and most significant bytes
- Interpreting raw bytes
- Arrays as contiguous memory
- Pointer arithmetic
- `*(ptr + n)`
- `sizeof` and type-sized pointer movement

Example memory inspection:

```text
0x5ffe9c:  0x0a 0x00 0x00 0x00
0x5ffea0:  0x14 0x00 0x00 0x00
0x5ffea4:  0x1e 0x00 0x00 0x00
```

Three adjacent 32-bit integers stored in little-endian order.

### Phase 2 — Stack & Function Calls ✅

Used GDB to inspect actual stack frames and connect C++ code to generated machine instructions.

Concepts explored:

- Local-variable placement on the stack
- Stack frames
- `backtrace`
- `info frame`
- `RIP`, `RSP`, and `RBP`
- Saved return addresses
- Stack growth
- Stack alignment and compiler padding
- Function prologues and epilogues
- Assembly offsets such as `-0x4(%rbp)`
- Disassembling C++ functions

Example:

```asm
push   %rbp
mov    %rsp,%rbp
sub    $0x10,%rsp
movl   $0xa,-0x4(%rbp)
movl   $0x14,-0x8(%rbp)
```

This helped connect local C++ variables directly to their locations inside a real stack frame.

### Phase 3 — Dynamic Memory ✅

Explored manually managed heap memory and the failure modes that come with it.

Concepts explored:

- Stack vs. dynamically allocated storage
- Automatic vs. dynamic object lifetime
- `new` and `delete`
- `new[]` and `delete[]`
- Dynamic arrays
- Object lifetime
- Constructors and destructors
- Dangling pointers
- Use-after-free
- Double deletion
- Undefined behavior
- `nullptr`
- Memory leaks
- Lost ownership
- Allocator reuse of recently freed addresses

Example:

```cpp
int* ptr = new int(42);

delete ptr;
ptr = nullptr;
```

Also inspected dynamic arrays in GDB and confirmed that their elements remain contiguous in memory just like ordinary arrays.

### Phase 4 — RAII & Smart Pointers ✅

Explored modern C++ resource ownership and how RAII can connect resource lifetime to object lifetime.

First implemented RAII manually by creating an owning class whose destructor releases a dynamically allocated object.

Then moved to the standard smart-pointer types.

#### Manual RAII

Created an owning class containing a raw pointer:

```cpp
class Owner {
private:
    Tracker* ptr;

public:
    Owner() {
        ptr = new Tracker();
    }

    ~Owner() {
        delete ptr;
    }
};
```

This demonstrated the core RAII idea:

```text
Owner constructed
      ↓
resource acquired
      ↓
Owner leaves scope
      ↓
Owner destructor runs
      ↓
resource released
```

The resource cleanup becomes tied to the lifetime of the owning object.

#### `std::unique_ptr`

Concepts explored:

- Exclusive ownership
- `std::make_unique`
- Automatic destruction
- Deleted copy operations
- Ownership transfer with `std::move`
- Moved-from smart pointers
- Inspecting ownership transfers in GDB
- `get()`
- `release()`
- `reset()`
- Difference between ownership and raw observation

Observed an ownership transfer directly in GDB:

```text
Before move:

ptr1.get() = 0x10c450

After move:

ptr1.get() = 0x0
ptr2.get() = 0x10c450
```

The `Tracker` object did not move in memory. Ownership of the same allocation moved from `ptr1` to `ptr2`.

Also explored the difference between:

```cpp
Tracker* raw = ptr.get();
```

and:

```cpp
Tracker* raw = ptr.release();
```

`get()` exposes the address while the `unique_ptr` retains ownership.

`release()` gives up ownership entirely, meaning the caller becomes responsible for eventually releasing the object.

#### `std::shared_ptr`

Concepts explored:

- Shared ownership
- Reference counting
- `std::make_shared`
- `use_count()`
- Copying shared ownership
- Releasing one owner with `reset()`
- Difference between `shared_ptr::get()` and creating another owner
- Object destruction when the final owner disappears

Example observed behavior:

```text
owners before reset: 3
owners after reset:  2
```

The managed object remains alive while at least one `shared_ptr` still owns it.

#### `std::weak_ptr`

Concepts explored:

- Non-owning observation
- Difference between a raw observer pointer and `weak_ptr`
- `expired()`
- `lock()`
- Temporarily acquiring shared ownership
- Detecting when the managed object has been destroyed

Observed:

```text
owners:                  1
owners after lock():     2
owners after temp reset: 1

Tracker destroyed

weak.expired():          true
```

Unlike a raw pointer, a `weak_ptr` participates in the smart-pointer lifetime system and can determine whether the object it previously observed still exists.

#### Circular Ownership

Finished the phase by exploring one of the major failure modes of reference-counted ownership.

Two objects were created that owned each other using `shared_ptr`:

```text
A ─── owns ───→ B
↑               │
└──── owns ─────┘
```

Each object had two owners initially:

```text
A owners: 2
B owners: 2
```

When the local `shared_ptr` objects left scope, each reference count only dropped from `2` to `1`.

Because A continued owning B and B continued owning A, neither reference count could reach zero.

As a result:

```text
A destroyed
B destroyed
```

were never printed.

The objects had created a reference cycle and leaked despite using smart pointers.

The cycle was then broken by changing one side of the relationship to `weak_ptr`:

```text
A ─── owns ───→ B
↑               │
└── observes ───┘
```

Because the `weak_ptr` does not contribute to the reference count, the objects could now be destroyed normally when their actual owners disappeared.

This demonstrated an important limitation:

> Smart pointers help enforce ownership rules, but they cannot automatically fix incorrect ownership design.

The larger lesson from Phase 4 is that modern C++ pointer types communicate different lifetime relationships:

```text
unique_ptr  → exclusive ownership
shared_ptr  → shared ownership
weak_ptr    → tracked non-ownership
T*          → address with no ownership semantics encoded
```

### Memory Explorer Progress

```text
Phase 1  Memory & Pointers          ✅ Complete
Phase 2  Stack & Function Calls     ✅ Complete
Phase 3  Dynamic Memory             ✅ Complete
Phase 4  RAII & Smart Pointers      ✅ Complete
Phase 5  Process / Virtual Memory   🚧 In Progress
Phase 6  CPU / Assembly             ⏳ Planned
Phase 7  Memory Performance         ⏳ Planned
Phase 8  Threads & Shared Memory    ⏳ Planned
Phase 9  Final Integration          ⏳ Planned
```

### Phase 5 — Process / Virtual Memory 🚧

Currently beginning to explore how the memory addresses observed throughout the previous phases relate to the operating system and physical hardware.

Initial concepts:

- CPU registers vs. memory
- Stack and heap as regions of process memory
- Virtual addresses vs. physical addresses
- Process virtual address spaces
- Introduction to virtual memory
- Introduction to the MMU
- Automatic vs. dynamic storage lifetime

The next goal is to understand the path from:

```text
C++ pointer
    ↓
virtual address
    ↓
memory page
    ↓
page-table translation
    ↓
physical memory
```

---

## Build

Build each project with a C++17-compatible compiler.

Example commands:

```powershell
cd c:\Users\dyao0\Desktop\c++

g++ -std=c++17 -O2 -Wall -Wextra -o statsengine\statsengine.exe statsengine\statsengine.cpp

g++ -std=c++17 -O2 -Wall -Wextra -o market-data-reader\market-data-reader.exe market-data-reader\main.cpp market-data-reader\MarketData.cpp market-data-reader\Statistics.cpp

g++ -std=c++17 -O2 -Wall -Wextra -Iportfolio-analyzer\include -o portfolio-analyzer\portfolio-analyzer.exe portfolio-analyzer\src\main.cpp portfolio-analyzer\src\MarketData.cpp portfolio-analyzer\src\Portfolio.cpp portfolio-analyzer\src\Statistics.cpp
```

## Run

From the repository root:

```powershell
.\statsengine\statsengine.exe
.\market-data-reader\market-data-reader.exe
.\portfolio-analyzer\portfolio-analyzer.exe
```

The market data reader expects `market-data-reader\market_data.csv` in its working directory.

The portfolio analyzer reads sample data files from `portfolio-analyzer\data`.
