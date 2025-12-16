# Algorithm Complexity Reference

This repository contains a **quick reference table** of commonly used algorithms, their **best case**, **worst case**, **time complexity**, **space complexity**, and **notes / use cases**.

## Algorithm Complexity Table

```text
| Name                     | Best Case                       | Worst Case                    | Time Complexity                 | Space Complexity               | Notes / Use Case                                  |
|--------------------------|---------------------------------|-------------------------------|---------------------------------|--------------------------------|---------------------------------------------------|
| Selection Sort           | O(n²)                           | O(n²)                         | O(n²)                           | O(1)                           | Simple, in-place sort; not efficient for large n  |
| Huffman Coding (Encoding)| O(n log n)                      | O(n log n)                    | O(n log n)                      | O(n)                           | Greedy algorithm for lossless data compression    |
| Fractional Knapsack      | O(n log n)                      | O(n log n)                    | O(n log n)                      | O(n)                           | Greedy approach; allows fractions of items        |
| BFS                      | O(V + E)                        | O(V + E)                      | O(V + E)                        | O(V + E)                       | Level-order graph traversal                       |
| DFS                      | O(V + E)                        | O(V + E)                      | O(V + E)                        | O(V + E)                       | Deep traversal; cycle detection, components       |
| Adjacency Matrix         | O(1) per edge check             | O(V²)                         | O(V²)                           | O(V²)                          | Dense graphs; easy edge lookup                    |
| Adjacency List           | O(degree(v)) per edge check     | O(degree(v)) per edge check   | O(V + E)                        | O(V + E)                       | Sparse graphs; efficient neighbor traversal       |
| Dijkstra                 | O(V + E log V)                  | O((V + E) log V)              | O((V + E) log V)                | O(V + E) + O(V) for distances  | Single-source shortest path; non-negative weights |
| Floyd-Warshall           | O(V³)                           | O(V³)                         | O(V³)                           | O(V²)                          | All-pairs shortest path; handles negative edges   |
| Number Theory Operations | Prime check O(√n)               | Prime check O(√n)             | Depends on operation            | O(1)                           | Includes primes, modular arithmetic, factorization|
| GCD (Euclidean Algorithm)| O(log min(a,b))                 | O(log min(a,b))               | O(log min(a,b))                 | O(1) (iterative)               | Efficient computation of greatest common divisor  |
| Prime Factorization      | O(√n)                           | O(√n)                         | O(√n)                           | O(log n)                       | Break number into prime factors                   |
| Graham Scan (Convex Hull)| O(n log n)                      | O(n log n)                    | O(n log n)                      | O(n)                           | Compute convex hull of points in 2D               |
|--------------------------|---------------------------------|-------------------------------|---------------------------------|--------------------------------|---------------------------------------------------|
| Modular Arithmetic       | Addition/Sub/Mul: O(1) <br> Division: O(log mod) | Addition/Sub/Mul: O(1) <br> Division: O(log mod) | Addition/Sub/Mul: O(1) <br> Division: O(log mod) | O(1) | Basic operations under modulo; division requires inverse |

```
````sex````

- [Click me](https://ideone.com/LUBmh4)
- [Video](https://notebooklm.google.com/notebook/ad0c665b-f847-4582-a84f-0dd36ddc4c0a?artifactId=f08c90e0-9242-4acb-a7da-404596046641)
