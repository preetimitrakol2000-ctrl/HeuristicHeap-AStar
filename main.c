#include <stdio.h>
#include "heap.h"

int main() {
    printf("🚀 Starting HeuristicHeap-AStar Target Router Engine...\n\n");

    MinHeap* priority_queue = create_heap(10);

    RouteNode target_a = {101, 14.5};
    RouteNode target_b = {102, 8.2};
    RouteNode target_c = {103, 22.1};

    insert_heap(priority_queue, target_a);
    insert_heap(priority_queue, target_b);
    insert_heap(priority_queue, target_c);

    printf("📥 Injected Pipeline Nodes: ID 101 (Cost 14.5), ID 102 (Cost 8.2), ID 103 (Cost 22.1)\n");

    RouteNode optimal = extract_min(priority_queue);
    printf("\n🔮 Algorithmic Minimum Cost Element Extracted Successfully:\n");
    printf("   👉 Node Target ID Identification: %d | Computed Path Cost Fscore: %.2f\n", optimal.node_id, optimal.f_score);

    free_heap(priority_queue);
    return 0;
}
