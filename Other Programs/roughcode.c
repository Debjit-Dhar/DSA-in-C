#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max_num 100
#define infinity INT_MAX

typedef struct {
    int num_vertices;
    int is_weighted;
    int is_directed;
    float M[max_num][max_num];
} Graph;

Graph* create() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (!g) {
        perror("Malloc Error");
        exit(EXIT_FAILURE);
    }
    return g;
}
void delete(Graph *g)
{
    free(g);
}

void insert_vertices(Graph *g) {
    if (!g->is_weighted) {
        for (int i = 0; i < g->num_vertices; i++)
            for (int j = 0; j < g->num_vertices; j++)
                g->M[i][j] = 0;
    } else {
        for (int i = 0; i < g->num_vertices; i++)
            for (int j = 0; j < g->num_vertices; j++)
                g->M[i][j] = infinity;
    }
}

void insert_edge(Graph *g, int v1, int v2, float weight) {
    g->M[v1][v2] = weight;
    if (!g->is_directed)
        g->M[v2][v1] = weight;
}

void delete_vertex(Graph *g, int v) {
    if (!g->is_weighted) {
        for (int i = 0; i < g->num_vertices; i++)
            g->M[v][i] = 0;
        if (!g->is_directed)
            for (int i = 0; i < g->num_vertices; i++)
                g->M[i][v] = 0;
    } else {
        for (int i = 0; i < g->num_vertices; i++)
            g->M[v][i] = infinity;
        if (!g->is_directed)
            for (int i = 0; i < g->num_vertices; i++)
                g->M[i][v] = infinity;
    }
}

void delete_edge(Graph *g, int v1, int v2) {
    if (!g->is_weighted) {
        g->M[v1][v2] = 0;
        if (!g->is_directed)
            g->M[v2][v1] = 0;
    } else {
        g->M[v1][v2] = infinity;
        if (!g->is_directed)
            g->M[v2][v1] = infinity;
    }
}

void display_graph(Graph *g) {
    printf("\t");
    for (int i = 0; i < g->num_vertices; i++)
        printf("%d\t", i);
    printf("\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d\t", i);
        for (int j = 0; j < g->num_vertices; j++)
            printf("%.2f\t", g->M[i][j]);
        printf("\n");
    }
}

void rec_dfs(Graph g, int v, int *visited) {
    printf("%d\n", v);
    visited[v] = 1;
    for (int i = 0; i < g.num_vertices; i++) {
        if (!visited[i] && g.M[v][i] != 0) {
            rec_dfs(g, i, visited);
        }
    }
}

int main() {
    Graph* myGraph = create();
    myGraph->num_vertices = 5;
    myGraph->is_weighted = 0; // Set to 1 if weighted, 0 if unweighted
    myGraph->is_directed = 1; // Set to 1 if directed, 0 if undirected

    insert_vertices(myGraph);
    insert_edge(myGraph, 0, 1, 1);
    insert_edge(myGraph, 0, 2, 1);
    insert_edge(myGraph, 1, 3, 1);
    insert_edge(myGraph, 2, 4, 1);
    insert_edge(myGraph, 3, 4, 1);
     int visited[myGraph->num_vertices];
    for (int i = 0; i < myGraph->num_vertices; i++)
        visited[i] = 0;
    rec_dfs(*myGraph, 0, visited);
    printf("Initial Graph:\n");
    display_graph(myGraph);

    delete_vertex(myGraph, 2);

    printf("\nGraph after deleting vertex 2:\n");
    display_graph(myGraph);

    delete_edge(myGraph, 0, 1);

    printf("\nGraph after deleting edge between 0 and 1:\n");
    display_graph(myGraph);

   

    delete(myGraph); // Free memory allocated for myGraph
    return 0;
}
