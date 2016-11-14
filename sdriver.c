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
    printf("\n%s", input);

    graph * current_graph;
    current_graph = malloc(sizeof(graph));
    read_input(input, current_graph);

    return 0;
}
