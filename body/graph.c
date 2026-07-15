#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../head/graph.h"

Graph g;

static void clearAdjList(void)
{
    for (int i = 0; i < MAX; i++)
    {
        ArcNode *p = g.adjlist[i];
        while (p)
        {
            ArcNode *q = p->next;
            free(p);
            p = q;
        }
        g.adjlist[i] = NULL;
    }
}

static void addEdge(int u, int v, int w)
{
    g.graph[u][v] = w;
    g.graph[v][u] = w;

    ArcNode *node1 = (ArcNode *)malloc(sizeof(ArcNode));
    node1->adjvex = v;
    node1->weight = w;
    node1->next = g.adjlist[u];
    g.adjlist[u] = node1;

    ArcNode *node2 = (ArcNode *)malloc(sizeof(ArcNode));
    node2->adjvex = u;
    node2->weight = w;
    node2->next = g.adjlist[v];
    g.adjlist[v] = node2;
}

int change(char x[])
{
    for (int i = 0; i < g.spot; i++)
    {
        if (strcmp(g.name[i], x) == 0)
        {
            return i;
        }
    }
    return -1;
}

char *rechange(int x)
{
    if (x >= 0 && x < g.spot)
    {
        return g.name[x];
    }
    return NULL;
}

void create()
{
    clearAdjList();

    printf("请输入顶点数和边数：");
    scanf("%d %d", &g.spot, &g.edge);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            g.graph[i][j] = INF;
        }
    }

    for (int k = 0; k < g.spot; k++)
    {
        g.graph[k][k] = 0;
    }

    printf("请输入各顶点的名字：\n");
    for (int i = 0; i < g.spot; i++)
    {
        printf("第 %d 个景点：", i + 1);
        scanf("%s", g.name[i]);
    }

    char u[20], v[20];
    int w = 0;
    for (int i = 1; i <= g.edge; i++)
    {
        printf("输入第 %d 条边的两个顶点以及该边的权值：", i);
        scanf("%s %s %d", u, v, &w);
        int v1 = change(u);
        int v2 = change(v);

        if (v1 == -1 || v2 == -1)
        {
            printf("输入顶点不存在！本条边无效\n");
            continue;
        }
        addEdge(v1, v2, w);
    }

    printf("景区景点图创建成功！\n");
}

void show_graph()
{
    if (g.spot == 0)
    {
        printf("请先创建景区景点图！\n");
        return;
    }

    printf("景区景点分布图（邻接矩阵）：\n");
    printf(" ");
    for (int i = 0; i < g.spot; i++)
    {
        printf("%s ", g.name[i]);
    }
    printf("\n");

    for (int i = 0; i < g.spot; i++)
    {
        printf("%s ", g.name[i]);
        for (int j = 0; j < g.spot; j++)
        {
            printf("%d ", g.graph[i][j]);
        }
        printf("\n");
    }
}
