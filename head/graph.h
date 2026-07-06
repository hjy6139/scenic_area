#ifndef GRAPH_H
#define GRAPH_H
#define MAX 10

typedef struct {
    int graph[MAX][MAX];
    int spot,edge;
    char name[MAX][20];
}Graph;


void create();

#endif