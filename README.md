# fastiobench

This set of microbenchmarks adheres to the C++ standard and is designed to execute common benchmarks within the fast_io library. We believe these benchmarks represent typical scenarios and offer a relatively precise measure of performance of your environment.


# Description
This benchmark includes 10 standard benchmarks:

1.10mint: print/scan 10 million integers

2.leb128: print/scan 10 million integers with leb128

3.concatstr: concat std::string

4.gengraph: generate a graph for dijkstra and dijkstra unchecked

5.dijkstra

6.dijkstra_unchecked

7.list sort

8.sha512

9.vec_push_back:vector push_back

10.randpass

# Tests Explainations

## 1.10mint
This benchmark generates 10 million integers and writes them to a file, then reads them back. It is designed to evaluate the performance of formatted input/output operations, crucial for tasks such as logging, serializing text (e.g., JSON), or handling vast amounts of text input/output in ACM/ICPC or Computing Olympiad competitions.

## 2.leb128

This benchmark generates 10 million integers, writes them to a file using the integers' LEB128 encoding, and then reads them back. It focuses on evaluating the performance of binary serialization.

## 3.concatstr

This benchmark assesses the performance of concatenating ```std::string``` objects, a common operation in C++ code where string concatenation using ```std::string``` is ubiquitous and performance is critical. It primarily evaluates the performance of heap allocation.

## 4.gengraph

It produces a directed graph test intended for consumption by the 5.dijkstra and 6.dijkstra_unchecked algorithms. The benchmark evaluates the input/output and random number generation performance on your system.

## 5.dijkstra

Dijkstra is a widely used algorithm for finding the shortest path. However, it employs various data structures and algorithms. It can serve as a benchmark for evaluating the performance of data structures and the efficiency of random access on contiguous ranges, such as vectors.

## 6.dijkstra_unchecked

This version is the unchecked variant of 5.dijkstra. While 5.dijkstra always verifies bounds to uphold memory safety, this one does not. Its purpose is to assess whether bounds checking leads to a performance decline on your system by comparing its results with those of 5.dijkstra.

## 7.list sort

This benchmark evaluates the performance of sorting a doubly-linked list, specifically focusing on the efficiency of pointer chasing, where cache misses are prevalent.

## 8.sha512

SHA512 is a widely used cryptographic hash algorithm known for its utility and security. This benchmark assesses the performance of a typical cryptographic algorithm.

## 9.vec_push_Back

vector.push_back is a frequently used operation in C++ due to the widespread adoption of the vector container as the default choice. The efficiency of push_back becomes paramount as it is executed frequently. This benchmark evaluates the performance of vector growth and the allocator's efficiency.

## 10.randpass

This generates 1 million passwords using the system's cryptographically secure random number generator. It assesses the performance of the random number generator, a task commonly encountered in various applications.

# How to run this benchmark?


To start, clone the 'next' branch of fast_io:

```
git clone -b next https://github.com/cppfastio/fast_io
```

Then execute the following commands:

```
cd fast_io
mkdir build
cd build
cmake -GNinja .. -DCMAKE_BUILD_TYPE=Release
ninja
ctest --verbose
```

This sequence of commands clones the 'next' branch of the fast_io repository, creates a build directory, configures the build with CMake, compiles the project using Ninja, and runs the tests with verbose output.

## Emulate the Benchmark
To run the benchmark in an emulator, such as QEMU, Wine, or WebAssembly virtual machines, you can create a Bash script file and include your command within it using the following option: -DCMAKE_CROSSCOMPILING_EMULATOR=yourscriptfile.
