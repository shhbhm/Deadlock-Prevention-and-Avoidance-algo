# Deadlock prevention and avoidance algorithms

this repository features two essential algorithms implemented in c++ to understand and prevent deadlocks in operating systems: the resource allocation graph and the banker's algorithm. these programs serve as educational tools to explore how resources can be managed in a multi-process environment to avoid deadlocks.

## contents

- **resource-allocation-graph-program**: a c++ program that simulates a resource allocation graph, identifying potential deadlock scenarios and counting occurrences based on user input.
- **banker's-algorithm**: a c++ implementation of the banker's algorithm, a well-known method used in operating systems to avoid deadlocks by maintaining a safe state during resource allocation.

## resource-allocation-graph-program

### overview

this program simulates a simplified resource allocation graph, where resources are assigned to processes. users can input resources and processes, and the program will identify if a deadlock occurs based on resource competition.

### features

- predefined matrix structure (4x3) for resource allocation.
- detects and counts deadlocks based on user input.
- highlights the location [row][column] of the resource that causes a deadlock.

### usage

1. compile and run the program.
2. input the number of processes and resources as prompted.
3. enter the resource you want to check for potential deadlock.
4. view the output, which will indicate if a deadlock occurred and where it is located.

### example output

- process and resource mapping.
- deadlock detection with counts and matrix location.

## banker's-algorithm

### overview

the banker's algorithm is a classical deadlock avoidance method used in operating systems. this program allows users to input the number of processes and resources, and then calculates if the system can remain in a safe state or if a deadlock may occur.

### features

- user input for processes, current allocation, and maximum resource needs.
- checks for system safety and potential deadlock situations.
- allows modifications to initial resources, allocated resources, and maximum resource needs.

### usage

1. compile and run the program.
2. input the number of processes and resources, and provide the current allocation and maximum needs.
3. view the output to determine if the system is in a safe state or if there is a risk of deadlock.

### example output

- detailed process execution sequence.
- insights into system safety and potential deadlock risks.

## how to contribute

this repository is open to contributions. if you have suggestions for improvements, feel free to open an issue or submit a pull request. let's collaborate to enhance this educational tool!

## license

this project is licensed under the mit license. see the [license](license) file for details.
