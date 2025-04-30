# In-Memory Key-Value Database with Transaction Support

## This project implements an in-memory key-value database that supports transactions. It allows for all-or-nothing updates to ensure data consistency.
Features

    In-memory storage of string keys with integer values
    Transaction support (begin, commit, rollback)
    ACID-compliant operations
    Detailed error handling

## How to Run
Prerequisites

    C++ compiler with C++17 support (for std::optional)
    Standard build tools (make, cmake, etc.)

## Compilation

To compile the application, follow these steps:
```bash

# Clone the repository
git clone https://github.com/yourusername/inmemorydb.git
cd inmemorydb

# Compile using g++
g++ -std=c++17 main.cpp -o inmemorydb

# Run the application
./inmemorydb
```