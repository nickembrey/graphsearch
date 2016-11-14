// HEADER FILE TEMPLATE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE (1 == 1)
#define FALSE (!TRUE)

// structs and unions here

typedef struct node {
    struct node ** edges;
    int value;
} node;

typedef struct graph {
    struct node ** nodes;
    int node_number;
    int start_node;
} graph;

// function prototypes here
//
void read_input(char * filename, graph * current_graph);
