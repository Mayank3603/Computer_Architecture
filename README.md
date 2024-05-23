# Assignment 1

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

# Assignment 2

# VectorOperations SimObject in gem5

This repository contains the implementation of a custom `VectorOperations` SimObject in gem5, designed to perform vector operations with specified latencies. The implementation involves creating a Python class for the SimObject, defining its parameters, and implementing the SimObject in C++. The steps to build and use this SimObject are outlined below.

## Steps to Create and Use the VectorOperations SimObject

### Step 1: Create Python Class for SimObject

To create a SimObject, first, create a Python class. This class should be placed in the `src` folder of the gem5 directory.

**VectorOperations.py:** This file will contain the Python class for the SimObject. The class includes parameters that can take input from the user, such as the two vectors (3x1) and the wait times for each event. Key attributes to define include:
- `type`: The type is the C++ class wrapped with this Python SimObject.
- `cxx_header`: The header file containing the declaration of the class used as the type parameter.
- `cxx_class`: Specifies that the newly created SimObject is declared within the gem5 namespace.

### Step 2: Implement the SimObject in C++

**vector_operations.hh:** This file contains all the declarations. It includes necessary headers to use the debug flags declared in `SConscript` and wraps all header files in `#ifndef /#endif` to prevent circular includes. The SimObject should be declared within the gem5 namespace.

Declare all private variables for the SimObject. For `VectorOperations`, the parameter type's name is `VectorOperationsParams`. All event declarations with event wrappers and cycle variables should be declared in the private section of the class. In the public section, declare the `startup()` function to schedule the events.

**vector_operations.cc:** This file contains the body of the events and all computations, along with `DPRINTF` statements used to output results with corresponding flags. The `startup()` function is where SimObjects schedule internal events based on user input. Events such as `VectorCrossProduct`, `NormalizeVector`, and `VectorSubtraction` are defined here, each using `DPRINTF` statements for debugging.

### Step 3: Register the SimObject and C++ File

Create a `SConscript` file to register the SimObject and the C++ file. This file includes functions to declare the SimObject and the `.cc` file. It also mentions the debug flags created for the assignment.

### Step 4: (Re)-build gem5

To compile and link the new files, recompile gem5 with the following command:
`scons build/X86/gem5.opt`

### Step 5: Step 5: Create the Configuration Script

Create a configuration script to use the new SimObject. This script should instantiate the SimObject and run the simulation. All gem5 instances require a Root object. The script also takes user input to run the SimObject with specified inputs, calls instantiate on the m5 module, and runs the simulation.

### Running the Simulation
To run the simulation, use the following command:
`build/X86/gem5.opt --debug-flags=NORMALIZE,RESULTCROSS,RESULTSUB,VECTOR configs/assignment2/run.py`
