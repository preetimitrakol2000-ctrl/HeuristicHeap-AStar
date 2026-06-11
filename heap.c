#include <stdlib.h>
#include "heap.h"

MinHeap* create_heap(int capacity) {
    MinHeap* hp = (MinHeap*)malloc(sizeof(MinHeap));
    hp->size = 0;
    hp->capacity = capacity;
    hp->data = (RouteNode*)malloc(capacity * sizeof(RouteNode));
    return hp;
}

void swap_nodes(RouteNode* a, RouteNode* b) {
    RouteNode temp = *a; *a = *b; *b = temp;
}

void insert_heap(MinHeap* hp, RouteNode node) {
    if (hp->size >= hp->capacity) return;
    hp->data[hp->size] = node;
    int i = hp->size;
    hp->size++;

    // Shift-Up loop logic to maintain min-heap attributes
    while (i != 0 && hp->data[(i - 1) / 2].f_score > hp->data[i].f_score) {
        swap_nodes(&hp->data[i], &hp->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

RouteNode extract_min(MinHeap* hp) {
    if (hp->size <= 0) { RouteNode empty = {-1, 0.0}; return empty; }
    if (hp->size == 1) { hp->size--; return hp->data[0]; }

    RouteNode root = hp->data[0];
    hp->data[0] = hp->data[hp->size - 1];
    hp->size--;

    // Shift-Down traversal logic
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < hp->size && hp->data[right].f_score < hp->data[left].f_score) {
            smallest = right;
        }
        if (hp->data[i].f_score <= hp->data[smallest].f_score) break;
        swap_nodes(&hp->data[i], &hp->data[smallest]);
        i = smallest;
    }
    return root;
}

void free_heap(MinHeap* hp) {
    free(hp->data); free(hp);
}
