# GraphUsingOperators

This repository implements basic graph operations like union, intersection, and complement using operator overloading in C++. The graph is represented using an adjacency matrix, and operations such as adding/removing edges, checking reachability, and performing set operations are supported. The unique aspect of this implementation is the use of C++ operator overloading (`+`, `-`, `!`, `>>`, `<<`) to perform graph manipulations.

## Features:
- **Graph Representation:** Uses an adjacency matrix to represent the graph.
- **Operator Overloading:**
  - `+` (Union): Combines two graphs by adding edges from one graph to another.
  - `-` (Intersection): Performs the intersection of two graphs, keeping only the common edges.
  - `!` (Complement): Computes the complement of a graph by flipping the adjacency matrix.
  - `>>` (Input stream operator): Reads graph edges from input.
  - `<<` (Output stream operator): Prints the graph in a readable format.
- **Additional Operations:**
  - Add/remove edges between vertices.
  - Check if a path exists between two vertices (`isReachable`).
  - Resize the graph dynamically when the number of vertices changes.

## Example Operations:
- `add_edge u v`: Adds an edge between vertex `u` and vertex `v`.
- `remove_edge u v`: Removes the edge between vertex `u` and vertex `v`.
- `isReachable u v`: Checks if there is a path from vertex `u` to vertex `v`.
- `complement`: Computes the complement of the current graph.
- `union`: Performs a union of the current graph with another graph.
- `intersect`: Performs an intersection of the current graph with another graph.
- `printGraph`: Prints the current graph.

