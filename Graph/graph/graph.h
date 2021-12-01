#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

typedef struct _node_ Node;

struct _node_ {
    int32_t node_id;
    uint32_t cost;
    Node *next;
};

typedef struct _graph_ Graph;

struct _graph_ {
    uint32_t size;
    Node **neighbours;

};

Graph graph_new(uint32_t size);
Graph* graph_adjacency_list(Graph *g);

#endif // GRAPH_H_INCLUDED
