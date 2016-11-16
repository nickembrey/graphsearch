// Nick Embrey
// November 16, 2016
// NEW BEGINNINGS Theory II
// Programming Assignment 4

#include "sgraph.h"


// init_queue
// Initializes a queue struct.
// Takes a pointer to the queue to be initialized.
// Returns void.

void init_queue(queue * new_queue) {
    new_queue->size = 0;
    return;
}

// enqueue 
// Puts a node into the queue.
// Takes a pointer to the queue being used and the node to enqueue.
// Returns void
void enqueue(queue * current_queue, node * current_node) {
    if(!current_queue->size) current_queue->tail = current_node;
    else {
        current_queue->head->prev = current_node;
        current_node->next = current_queue->head;
    }

    current_queue->size++;
    current_queue->head = current_node;

    return;
}

// dequeue
// Removes a node from the queue.
// Takes a pointer to the queue being used.
// Returns the node taken from the queue.
node * dequeue(queue * current_queue) {
    if(current_queue->size == 0) return NULL;
    node * current_node = current_queue->tail;
    current_queue->tail = current_node->prev;
    if(current_queue->size > 1) current_node->prev->next = NULL;
    current_node->prev = NULL;
    current_queue->size--;
    return current_node;
}

// read_input 
// Reads input from a well-formed input file that describes a directed graph.
// Takes a pointer to a string of characters and a pointer to a graph struct that will hold the graph being created.
// Returns void.
void read_input(char * filename, graph * current_graph) { 
    char read_string[20];
    FILE * read_file; // Points to the file being read from.
    int counter;
    int destination;
    int edge_number;
    int inner_counter;
    int node_number;
    int origin;

    read_file = fopen(filename, "r");
    if(read_file == NULL) {
        printf("\nSorry, that file could not be found.\n");
        exit(EXIT_FAILURE);
    }
    fgets(read_string, 20, read_file);
    if(strlen(read_string) > 20) {
        printf("\nSorry, the title of the graph is too long. Please restart the program and try again with a shorter graph title.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nGraph name: ");
    for(counter = 0; counter < sizeof read_string; counter++) printf("%c", read_string[counter]);

    fscanf(read_file, "%d", &node_number);
    if(node_number < 2 || node_number > 20) {
        printf("\nSorry, the file has an invalid number of vertices. Please restart the program and try again with between 2 & 20 vertices.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nNo. of vertices = %d", node_number);

    current_graph->node_number = node_number;
    current_graph->nodes = malloc(sizeof(node) * (node_number + 1));
    for(counter = 1; counter <= node_number; counter++) { // Initialize nodes.
        current_graph->nodes[counter] = malloc(sizeof(node));
        current_graph->nodes[counter]->value = counter;
        current_graph->nodes[counter]->edges = malloc(sizeof(node *) * node_number);
        for(inner_counter = 1; inner_counter <= node_number; inner_counter++) current_graph->nodes[counter]->edges[inner_counter] = NULL; // Initialize all edge pointers to NULL
        current_graph->nodes[counter]->visited = FALSE;
        current_graph->nodes[counter]->next = NULL; // Initialize next pointer to NULL.
        current_graph->nodes[counter]->prev = NULL; // Initialize prev pointer to NULL;
    }

    fscanf(read_file, "%d", &edge_number);
    if(edge_number < 0 || edge_number > node_number) {
        printf("\nSorry, the file has an invalid number of edges. Please restart the program and try again with a positive number of edges that is less than or equal to the number of vertices.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nNo. of edges = %d", edge_number);

    for(counter = 0; counter < edge_number; counter++) {
        fscanf(read_file, " (%d,%d)", &origin, &destination);
        if(origin < 0 || origin > node_number || destination < 0 || destination > node_number) {
            printf("\nSorry, the edge list in the file is invalid. Please restart the program and try again, ensuring the edge list contains exactly the number of edges given as edges and that each edge is entered in the following form (vertex1,vertex2).\n");
            exit(EXIT_FAILURE);
        }
        current_graph->nodes[origin]->edges[destination] = current_graph->nodes[destination];
    }
    
    fscanf(read_file, "%d", &current_graph->start_node);
    printf("\nStart vertex = %d", current_graph->start_node);
    return;
}

// depth_first_search. 
// Recursively performs a depth first search on a graph created by read_input. 
// Takes a pointer to the graph and a pointer to a node on that graph. 
// Returns void.
void depth_first_search(graph * current_graph, node * current_node) {
    int counter;
    
    if(current_node->visited) return;
    printf(" %d", current_node->value);
    current_node->visited = TRUE;
    for(counter = 1; counter <= current_graph->node_number; counter++) {
        if(current_node->edges[counter] != NULL) depth_first_search(current_graph, current_node->edges[counter]);
    }
    return;
}

// breadth_first_search
// Performs a breadth first search on a graph created by read_input
// Takes a pointer to the graph.
// Returns void.
void breadth_first_search(graph * current_graph) {
    node * current_node; // Points to the node that is currently being performed on.
    queue * current_queue; // Points to a queue structure for organizing the nodes.
    int counter;

    current_node = current_graph->nodes[current_graph->start_node];
    current_node->visited = TRUE;
  
    current_queue = malloc(sizeof(queue));
    init_queue(current_queue);
    printf(" %d", current_node->value);
    for(counter = 1; counter<=current_graph->node_number; counter++) {
        if(current_node->edges[counter] != NULL) {
            enqueue(current_queue, current_node->edges[counter]); 
            printf(" %d", current_node->edges[counter]->value);
            current_node->edges[counter]->visited = TRUE;
        }
    }

    while( (current_node = dequeue(current_queue)) != NULL) {
        for(counter = 1; counter <= current_graph->node_number; counter++) {
            if(current_node->edges[counter] != NULL && !current_node->edges[counter]->visited) {
                enqueue(current_queue, current_node->edges[counter]);
                printf(" %d", current_node->edges[counter]->value);
                current_node->edges[counter]->visited = TRUE;
            }
        }
    }
    
    for(counter = 1; counter <= current_graph->node_number; counter++) {
        current_graph->nodes[counter]->visited = FALSE;
    }
    // reset everything.
    return;
}
