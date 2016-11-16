// Nick Embrey
// November 16, 2016
// NEW BEGINNINGS Theory II
// Programming Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE (1 == 1)
#define FALSE (!TRUE)

// structs and unions here

typedef struct node {
    struct node ** edges;
    struct node * next;
    struct node * prev;
    int value;
    BOOL visited;
} node;

typedef struct graph {
    struct node ** nodes;
    int node_number;
    int start_node;
} graph;

typedef struct queue {
    node * head;
    node * tail;
    int size;
} queue;

// function prototypes here
//
void read_input(char * filename, graph * current_graph);

void depth_first_search(graph * current_graph, node * start_node);

void breadth_first_search(graph * current_graph);

void enqueue(queue * current_queue, node * current_node);

node * dequeue(queue * current_queue);
