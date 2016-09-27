# Benchmarking
This is a small test suite to benchmark certain properties of the Linux Kernel using only userspace code

## Pre-requisites
In order to get results that are consistent, we need to run the test suite on only one processor and keep the processor speed constant. This can be done using a combination of cpufrequtils and taskset.

## Usage
1. Clone the repo.
2. make
3. sudo nice --20 taskset -c 0 ./benchmark <listSize> <listStride>

To run the script for testing all values for memory latency, run
sudo nice --20 taskset -c 0 ./testScript.h (The value ranges can be changed inside the script file)


