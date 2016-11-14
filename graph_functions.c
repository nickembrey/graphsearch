// FUNCTION FILE TEMPLATE.

#include "sgraph.h"

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
    for(counter = 1; counter <= node_number; counter++) {
        current_graph->nodes[counter] = malloc(sizeof(node));
        current_graph->nodes[counter]->value = counter;
        current_graph->nodes[counter]->edges = malloc(sizeof(node *) * node_number);
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
    
    printf("!!!!");
    printf("\n***%d***\n", current_graph->nodes[1]->edges[4]->value);

    return;
}

// FUNCTION NAME.
// FUNCTION DESCRIPTION.
// FUNCTION ARGUMENTS, DESCRIPTION.
// Returns FUNCTION RETURN TYPE, DESCRIPTION.
