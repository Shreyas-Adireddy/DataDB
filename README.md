# In-Memory Key-Value Database with Transaction Support

This project implements an in-memory key-value database that supports transactions. It allows for all-or-nothing updates to ensure data consistency.

## How to Run
Prerequisites

    C++ compiler with C++17 support (for std::optional)
    Standard build tools (make, cmake, etc.)

## Compilation

To compile the application, follow these steps:
```bash

# Clone the repository
git clone https://github.com/Shreyas-Adireddy/DataDB.git

# Compile using g++
g++ -std=c++17 db.cpp -o db

# Run the application
./db
```

## Improvements
For future iterations of this assignment, I suggest the following improvements:

Nested Transactions: Add support for nested transactions to make the database more realistic and useful.

Thread Safety: Introduce multi-threading concepts to make operations thread-safe, which would better simulate real-world databases.

Persistence Options: Add an optional requirement to implement some form of persistence to disk.

Performance Metrics: Include requirements to analyze and report on performance characteristics like access time or memory usage.

Clear Return Type Specifications: Be more specific about return types for non-existent keys (null, exception, or special value).
