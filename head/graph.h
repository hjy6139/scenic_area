#ifndef GRAPH_H
#define GRAPH_H
#define MAX 10
#define INF 32767

//邻接矩阵
typedef struct {
    int graph[MAX][MAX]; //邻接矩阵
    int spot,edge; //顶点，边
    char name[MAX][20]; //顶点名称
}Graph;

//顺序表输出DFS结果
typedef struct {
    int *data; //动态储存数组
    int length; // 当前存了多少元素
    int capacity; // 总容量
}SeqList;

void create();
void show_graph();
void show_DFS();
void show_cycle();
void show_Dijkstra();

//辅助
void InitSeaList(SeqList* sl,int initCap);
void AddData(SeqList* sl, int x);
void Dijkstra(int start, int end, int n, int dist[], int pre[], int visited[]);

#endif