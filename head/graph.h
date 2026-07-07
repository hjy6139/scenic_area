#ifndef GRAPH_H
#define GRAPH_H
#define MAX 10

typedef struct {
    int graph[MAX][MAX]; //邻接矩阵
    int spot,edge; //顶点，边
    char name[MAX][20]; //顶点名称
}Graph;


void create();
void show_graph();

#endif