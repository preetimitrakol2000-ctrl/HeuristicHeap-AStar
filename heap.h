#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int node_id;
    double f_score; // Heuristic evaluation metric: f(n) = g(n) + h(n)
} RouteNode;

typedef struct {
    RouteNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* create_heap(int capacity);
void insert_heap(MinHeap* hp, RouteNode node);
RouteNode extract_min(MinHeap* hp);
void free_heap(MinHeap* hp);

#endif
