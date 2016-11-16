// Nick Embrey
// November 16, 2016
// NEW BEGINNINGS Theory II
// Programming Assignment 4

// graphsearch
// Nick Embrey.
// No license.
// Date created: November 16, 2016.
// Reads an input file selected by the user and performs a demo depth first and breadth first search on the graph described by the file.

#include "sgraph.h"

// Main reads in the name of the input file and calls the appropriate functions.

int main(int argc, char ** argv) {    
    char input[20];
    graph * current_graph; // Points to the graph being used to store the input file.

    printf("\nPlease enter the name of the input file. ");
    scanf("%s", input);
    if(strlen(input) > 20) {
        printf("\nSorry, that filename is too long. Please restart the program and try again with a shorter filename.\n");
        return 0;
    }

    current_graph = malloc(sizeof(graph));
    read_input(input, current_graph);
    printf("\nBFS: ");
    breadth_first_search(current_graph);
    printf("\nDFS: ");
    depth_first_search(current_graph, current_graph->nodes[current_graph->start_node]);
    printf("\n\n");
    return 0;
}
