# Prim’s Algorithm – Minimum Spanning Tree

This repository contains a C++ implementation of Prim’s algorithm to find the Minimum Spanning Tree (MST) of an undirected, weighted graph.

---

## Table of Contents

1. [Problem Statement](#problem-statement)
2. [Algorithm Overview](#algorithm-overview)
3. [Compilation & Execution](#compilation--execution)
4. [Input & Output Format](#input--output-format)
5. [Complexity Analysis](#complexity-analysis)

---

## Problem Statement

Given an undirected graph with **V** vertices and **E** edges, each edge having an associated non-negative weight, compute the sum of the weights of the edges in its Minimum Spanning Tree (MST), and output the edges that form the MST in lexicographic order.

## Algorithm Overview

> **Note:** This implementation uses the lazy version of Prim’s algorithm, pushing all adjacent edges into the priority queue and filtering out used vertices when popping, rather than updating keys eagerly.

Prim’s algorithm grows the MST one edge at a time, starting from an arbitrary root (vertex 0 in this implementation).

1. Initialize all vertices as unvisited and set the starting vertex’s distance (key) to `0`.
2. Use a priority queue (min-heap) to extract the next edge with the minimum weight that connects a visited vertex to an unvisited vertex.
3. Mark the selected vertex as visited, add the edge weight to the total cost, and record its parent.
4. Update the keys of adjacent vertices if a cheaper connection is found.
5. Repeat until all vertices are included in the MST.

## Compilation & Execution

1. **Compile**

   ```bash
   g++ -std=c++17 -O2 -o prim main.cpp
   ```

2. **Run**

   ```bash
   ./prim input.txt output.txt
   ```

   * `input.txt`: Path to the input file describing the graph
   * `output.txt`: Path to the file where the MST total cost and edges will be written

## Input & Output Format

### Input

```
V E
u1 v1 w1
u2 v2 w2
...

- V: Number of vertices (0-indexed: 0 to V-1)
- E: Number of edges
- ui, vi: Endpoints of the i-th edge
- wi: Weight of the i-th edge (non-negative integer)
```

### Output

```
<total_cost>
<V - 1>
u1 v1
u2 v2
...

- `<total_cost>`: Sum of weights of edges in MST
- Next line: Number of edges in the MST (should be V-1)
- Following lines: Edges in the MST in lexicographic order (each as `u v` where u < v)
```

## Complexity Analysis

* **Time Complexity**: O((V + E) log V), dominated by priority queue operations where each edge insertion and extraction takes O(log V).
* **Space Complexity**: O(V + E) for storing the graph and auxiliary arrays.
