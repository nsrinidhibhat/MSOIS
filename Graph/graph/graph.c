#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "graph.h"

Graph graph_new(uint32_t size){
    grpah g;
    g.size = size;
    g.neighbours = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0;i<size;++i){
        g.neighbours[i] = NULL;
    }
    return g;
}
static Node* _make_node_(int32_t data){

    Node* node = (Node*)malloc(sizeof(Node));
    node->node_id = data;
    node->cost = 0;
    node->next = NULL;

    return node;
}
static int32_t _get_neighbour_id_(int32_t node){
    int32_t neighbour_id;
    printf("Enter neighbour %d, No neighbour enetr 9999\n", node);
    scanf("%d",&neighbour_id);

    return neighbour_id;
}

Graph* graph_adjacency_list(Graph *g) {

    int32_t i, neighbour_id;
    uint32_t edge_cost;
    Node *vertex, *lastNode;

    for (i = 0;i<g->size;++i){
        g->neighbours[i] = _make_node_(i);
        neighbour_id = _get_neighbour_id_(i);

        while (neighbour_id != 9999){
                vertex = _make_node_(neighbour_id);
                //edge_cost = _get_neighbour_cost_(neighbour_id);
                //vertex->cost = edge_cost;

                if (g->neighbours[i]->next == NULL){
                    g->neighbours[i]->next == vertex;
                }
                else{
                    lastNode->next = vertex;
                }
                lastNode = vertex;
                neighbour_id = _get_neighbour_id_(i);
        }
    }
    return g;
}
