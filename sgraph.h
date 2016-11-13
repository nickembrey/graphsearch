// HEADER FILE TEMPLATE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOL int
#define TRUE (1 == 1)
#define FALSE (!TRUE)

// structs and unions here

typedef struct {
    struct node ** edges;
    int value;
} node;

// function prototypes here
//
void read_input(char * filename, node start_node);
