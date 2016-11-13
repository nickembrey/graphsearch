// FUNCTION FILE TEMPLATE.

#include "sgraph.h"

void read_input(char * filename, node start_node) {
    FILE * read_file;
    read_file = fopen(filename, "r");
    char read_string[20];

    fscanf(read_file, "%s", read_string);
    printf("\n%s\n", read_string);
    return;
}

// FUNCTION NAME.
// FUNCTION DESCRIPTION.
// FUNCTION ARGUMENTS, DESCRIPTION.
// Returns FUNCTION RETURN TYPE, DESCRIPTION.
