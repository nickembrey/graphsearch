// FUNCTION FILE TEMPLATE.

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

    // TODO: add error handling for improper input files.
    FILE * read_file;
    read_file = fopen(filename, "r");
    char read_string[20];

    fscanf(read_file, "%s", read_string);
    if(strlen(read_string) > 20) {
        printf("Sorry, that filename is too long. Please restart the program and try again with a shorter filename.");
        return;
    }
    printf("\n%s\n", read_string);

    int node_number;
    fscanf(read_file, "%s", read_string);
    if(strlen(read_string) > 20) {
        printf("Sorry, that filename is too long. Please restart the program and try again with a shorter filename.");
        return;
    }
    node_number = atoi(read_string);
    current_graph->node_number = node_number;
    current_graph->nodes = malloc(sizeof(node) * (node_number + 1));
    int counter;
    int inner_counter;
    for(counter = 1; counter <= node_number; counter++) { // Initialize nodes.
        current_graph->nodes[counter] = malloc(sizeof(node));
        current_graph->nodes[counter]->value = counter;
        current_graph->nodes[counter]->edges = malloc(sizeof(node *) * node_number);
        for(inner_counter = 1; inner_counter <= node_number; inner_counter++) current_graph->nodes[counter]->edges[inner_counter] = NULL; // Initialize all edge pointers to NULL
        current_graph->nodes[counter]->visited = FALSE;
        current_graph->nodes[counter]->next = NULL; // Initialize next pointer to NULL.
        current_graph->nodes[counter]->prev = NULL; // Initialize prev pointer to NULL;
        printf("\nNode number %d (%d) initializing.\n", current_graph->nodes[counter]->value, counter);
    }

    printf("\n%d\n", node_number);

    int edge_number;
    fscanf(read_file, "%s", read_string);
    if(strlen(read_string) > 20) {
        printf("Sorry, that filename is too long. Please restart the program and try again with a shorter filename.");
        return;
    }
    edge_number = atoi(read_string);
    
    printf("\n%d\n", edge_number);
    int origin;
    int destination;

    printf("\n?\n");

    for(counter = 0; counter < edge_number; counter++) {
        fscanf(read_file, " (%d,%d)", &origin, &destination);
        printf("\ncurrent origin: %d\ncurrent destination: %d\n", origin, destination);
        current_graph->nodes[origin]->edges[destination] = current_graph->nodes[destination];
    }
    

    fscanf(read_file, "%d", &current_graph->start_node);
    printf("\nStart node: %d\n", current_graph->start_node);
    return;
}

// depth_first_search. 
// Recursively performs a depth first search on a graph created by read_input. 
// Takes a pointer to the graph and a pointer to a node on that graph. 
// Returns void.
void depth_first_search(graph * current_graph, node * current_node) {
    int counter;
    printf("\n^^^%d^^^\n", current_graph->start_node);
    printf("\n?\n");
    printf("\n%d\n", current_node->value);
    if(current_node->visited) return;
    printf("%d ", current_node->value);
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
    node * current_node;
    current_node = current_graph->nodes[current_graph->start_node];
    printf(" %d", current_node->value);
    current_node->visited = TRUE;
    queue * current_queue;
    current_queue = malloc(sizeof(queue));
    init_queue(current_queue);
    int counter;
    for(counter = 1; counter<=current_graph->node_number; counter++) {
        if(current_node->edges[counter] != NULL) {
            enqueue(current_queue, current_node->edges[counter]);
            current_node->edges[counter]->visited = TRUE;
        }
    }
    while( (current_node = dequeue(current_queue)) != NULL) {
        printf(" %d", current_node->value);

        for(counter = 1; counter<=current_graph->node_number; counter++) {
            if(current_node->edges[counter] != NULL) {
                enqueue(current_queue, current_node->edges[counter]);
                current_node->edges[counter]->visited = TRUE;
            }
        }
    }

    return;
}
    
