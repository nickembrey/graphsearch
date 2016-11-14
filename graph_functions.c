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

    printf("\n%d\n", node_number);

    int edge_number;
    fscanf(read_file, "%s", read_string);
    edge_number = atoi(read_string);
    
    printf("\n%d\n", edge_number);
    
    int counter;
    for(counter = 0; counter < edge_number; counter++) {
        fscanf(read_file, "%s", read_string);

    }

    return;
}

// FUNCTION NAME.
// FUNCTION DESCRIPTION.
// FUNCTION ARGUMENTS, DESCRIPTION.
// Returns FUNCTION RETURN TYPE, DESCRIPTION.
