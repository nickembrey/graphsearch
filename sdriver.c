// MAIN FILE TEMPLATE.

// APP TITLE.
// Nick Embrey.
// LICENSE TYPE.
// Date created: DATE.
// Last modified: DATE.
// APP USE.

#include "sgraph.h"

int main(int argc, char ** argv) {
    
    char input[20];
    printf("\nPlease enter the name of the input file. ");
    scanf("%s", input);
    if(strlen(input) > 20) {
        printf("Sorry, that filename is too long. Please restart the program and try again with a shorter filename.");
        return 0;
    }

    printf("\n%s", input);

    graph * current_graph;
    current_graph = malloc(sizeof(graph));
    read_input(input, current_graph);
    depth_first_search(current_graph, current_graph->nodes[current_graph->start_node]);
    breadth_first_search(current_graph);

    return 0;
}
