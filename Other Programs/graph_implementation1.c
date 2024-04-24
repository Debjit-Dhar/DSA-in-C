#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define max_num 100
#define infinity INT_MAX

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

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

void rec_dfs(Graph g, int v, int *visited) {//Depth First Search(using stack)
    printf("%d\n", v);
    visited[v] = 1;
    for (int i = 0; i < g.num_vertices; i++) {
        if (!visited[i] && g.M[v][i] != 0) {
            rec_dfs(g, i, visited);
        }
    }
}
void bfs(Graph g,int v,int*visited){//Breadth First Search(using queue)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int i=v;
    printf("%d\n", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(g.M[node][j] ==1 && visited[j] == 0){
                printf("%d\n", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

}

struct edge_list
{
    int start_vertex;
    int end_vertex;
    float weight;
};

// Comparison function for qsort (based on edge weights in ascending order)
int compareEdges(const void *a, const void *b) {
    struct edge_list *edgeA = (struct edge_list *)a;
    struct edge_list *edgeB = (struct edge_list *)b;
    return (edgeA->weight - edgeB->weight);
}

void mcst_kruskal(Graph g) {
    // sort edges in non-decreasing order
    struct edge_list elist[g.num_vertices]; // Assuming num_edges represents the number of edges
    int k = 0;

    if (!g.is_directed) {
        for (int i = 0; i < g.num_vertices; i++) {
            for (int j = 0; j < g.num_vertices; j++) {
                if (g.M[i][j] != infinity && i != j) {
                    elist[k].start_vertex = i;
                    elist[k].end_vertex = j;
                    elist[k].weight = g.M[i][j];
                    k++;
                }
            }
        }
    }

    // Sort the elist array using qsort
    qsort(elist, k, sizeof(struct edge_list), compareEdges);
}

struct label
{
    int vertex;
    float dist;
    int mark;//0 for temporary 1 for permanent
};
int min_label(struct label labels[],int n)
{
    int min=infinity,label;
    for(int i=0;i<n;i++)
        if(min>labels[i].dist && labels[i].mark!=1)
        {
            min=labels[i].dist;
            label=i;
        }
    if(min==infinity)
        return -1;
    return label;
}
void dijkstra(Graph g,int v)
{
    struct label labels[g.num_vertices];
    int count=1,w=v;;
    for(int i=0;i<g.num_vertices;i++)
    {
        labels[i].vertex=i;
        labels[i].dist=(i==v?0:infinity);
        labels[i].mark=(i==v?1:0);
    }
    
    while(count<g.num_vertices)
    {
        for(int i=0;i<g.num_vertices;i++)
        {
            if(labels[i].mark!=1)
                labels[i].dist=fmin(g.M[v][i]+labels[v].dist,labels[i].dist);
        }
        v=min_label(labels,g.num_vertices);
        if(v==-1)
            break;
        labels[v].mark=1;
        count++;
    } 
    for(int i=0;i<g.num_vertices;i++)
        if(labels[i].dist!=infinity)
            printf("Shortest distance from %d to %d=%.2f\n",w,i,labels[i].dist);   
        else
            printf("Shortest ditance from %d to %d is None.\n",w,i);
}

int main() {
    Graph* myGraph = create();
    myGraph->num_vertices = 3;
    myGraph->is_weighted = 1; // Set to 1 if weighted, 0 if unweighted
    myGraph->is_directed = 1; // Set to 1 if directed, 0 if undirected

    /*
      0(20)--->1(10)---->2
      |(40)_____________|^
      */
    insert_vertices(myGraph);
    insert_edge(myGraph, 0, 1, 20);
    insert_edge(myGraph, 1, 2, 10);
    insert_edge(myGraph, 0, 2, 40);
    
    printf("Depth First Search.\n");
    int visited[myGraph->num_vertices];
    for (int i = 0; i < myGraph->num_vertices; i++)
        visited[i] = 0;
    rec_dfs(*myGraph, 0, visited);

    printf("Breadth First Search.\n");
    for (int i = 0; i < myGraph->num_vertices; i++)
        visited[i] = 0;
    bfs(*myGraph,0,visited);

    printf("Initial Graph:\n");
    display_graph(myGraph);

    printf("Shortest paths from 0.\n");
    dijkstra(*myGraph,0);

    delete_vertex(myGraph, 2);

    printf("\nGraph after deleting vertex 2:\n");
    display_graph(myGraph);

    delete_edge(myGraph, 0, 1);

    printf("\nGraph after deleting edge between 0 and 1:\n");
    display_graph(myGraph);

   

    delete(myGraph); // Free memory allocated for myGraph
    return 0;
}