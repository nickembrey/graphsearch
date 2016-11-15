// FUNCTION FILE TEMPLATE.

#include "sgraph.h"

void init_queue(queue * new_queue) {
    new_queue->size = 0;
    return;
}

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

node * dequeue(queue * current_queue) {
    node * current_node = current_queue->tail;
    current_queue->tail = current_node->prev;
    current_node->prev->next = NULL;
    current_node->prev = NULL;
    return current_node;
}

void read_input(char * filename, graph * current_graph) {

    // TODO: add error handling for improper input files.
    FILE * read_file;
    read_file = fopen(filename, "r");
    char read_string[20];

    fscanf(read_file, "%s", read_string);
    printf("\n%s\n", read_string);

    int node_number;
    fscanf(read_file, "%s", read_string);
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
    
    printf("\n***%d***\n", current_graph->nodes[1]->edges[4]->value);

    fscanf(read_file, "%d", &current_graph->start_node);
    printf("\nStart node: %d\n", current_graph->start_node);
    return;
}

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

void breadth_first_search(graph * current_graph, node * current_node) {

    return;
}
    
// FUNCTION NAME.
// FUNCTION DESCRIPTION.
// FUNCTION ARGUMENTS, DESCRIPTION.
// Returns FUNCTION RETURN TYPE, DESCRIPTION.
