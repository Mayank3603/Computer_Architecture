#Assignment 1

# Cache Simulation and Analysis with MiBench Benchmark Suite

This repository contains a configuration script to simulate a system architecture with a processor, two cache levels, and main memory. The simulation runs the "qsort_small" benchmark application from the MiBench benchmark suite in system emulation mode. Additionally, it explores the effect of varying L2 cache configurations on cache miss rates.

## System Configuration

The base system configuration is as follows:

- **L1 Data Cache**: 16kB, 2-way associative, latency = 2 cycles
- **L1 Instruction Cache**: 16kB, 2-way associative, latency = 2 cycles
- **L2 Cache**: 256kB, 4-way associative, latency = 10 cycles

The memory hierarchies are connected by buses, and the processor first looks for data in the L1 cache, then in the L2 cache if the L1 cache misses, and finally in main memory if the L2 cache misses.

## Benchmark

We use the "qsort_small" benchmark from the MiBench suite to evaluate the performance of the system. The benchmark can be found at [MiBench automotive/qsort](https://github.com/embecosm/mibench/tree/master/automotive/qsort).

## Experimental Simulations

To understand the impact of L2 cache configurations on cache miss rates, we performed simulations with various L2 cache sizes and associativities. The configurations are listed in Table 1 below, and the results are depicted in Figure 2.

### L2 Cache Configurations

| Size_Associativity | Size_Associativity |
|--------------------|--------------------|
| 64kB_2             | 1024kB_8           |
| 64kB_4             | 1024kB_2           |
| 256kB_2            | 32kB_4             |
| 256kB_4            | 64kB_8             |

### Observations

1. **Cache Size and Miss Rate**: As the L2 cache size increases, the cache miss rate decreases. This is because a larger cache can store more data, increasing the likelihood that the required data is found in the cache. Thus, the cache miss rate is inversely proportional to the L2 cache size.
   
2. **Associativity and Conflict Misses**: 
   - For small cache sizes and low associativity (1 or 2), conflict misses are a significant source of cache misses. With fewer cache sets, the chances of different memory blocks mapping to the same set are high.
   - Increasing associativity to 4 or 8 reduces conflict misses as more cache lines per set can accommodate more memory blocks without evictions. This reduction in miss rates is evident from the simulations.
   - Each increase in associativity yields diminishing returns in conflict miss reduction because the cache already efficiently accommodates diverse memory blocks with existing associativity levels.


