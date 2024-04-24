#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max_num 100
#define inifinity max(int)
typedef struct node
{
    int to_vertex;
    float weight;
    struct node* neighbour;
}node_type;
typedef struct 
{
    int num_vertex;
    node_type* list[max_num];
}graph;
