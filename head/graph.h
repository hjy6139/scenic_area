#ifndef GRAPH_H
#define GRAPH_H
#define MAX 10
#define INF 32767

typedef struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode *next;
} ArcNode;

typedef struct {
    int graph[MAX][MAX];
    int spot, edge;
    char name[MAX][20];
    ArcNode *adjlist[MAX];
} Graph;

typedef struct {
    int *data;
    int length;
    int capacity;
} SeqList;

extern Graph g;

void create();
void show_graph();
void show_DFS();
void show_cycle();
void show_Dijkstra();

int change(char x[]);
char *rechange(int x);

void InitSeaList(SeqList *sl, int initCap);
void AddData(SeqList *sl, int x);
void generateGuideRoute(SeqList *sl);
void Dijkstra(int start, int end, int n, int dist[], int pre[], int visited[]);

#endif
