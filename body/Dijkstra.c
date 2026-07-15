#include <stdio.h>
#include "../head/graph.h"

void Dijkstra(int start, int end, int n, int dist[], int pre[], int visited[])
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = g.graph[start][i];
        visited[i] = 0;
        pre[i] = start;
    }
    visited[start] = 1;
    pre[start] = -1;

    for (int j = 0; j < n - 1; j++)
    {
        int u = -1;
        int wu = INF;
        for (int k = 0; k < n; k++)
        {
            if (!visited[k] && dist[k] < wu)
            {
                wu = dist[k];
                u = k;
            }
        }

        if (u == -1)
        {
            break;
        }
        visited[u] = 1;
        if (u == end)
        {
            break;
        }

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && g.graph[u][v] != INF && dist[u] + g.graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + g.graph[u][v];
                pre[v] = u;
            }
        }
    }
}

static void Print(int cur, int st, int pre[])
{
    if (cur == st)
    {
        printf("%s", rechange(cur));
        return;
    }
    Print(pre[cur], st, pre);
    printf(" → %s", rechange(cur));
}

void show_Dijkstra()
{
    if (g.spot == 0)
    {
        printf("请先创建景区景点图！\n");
        return;
    }

    int dist[MAX];
    int pre[MAX];
    int n = g.spot;
    int visited[MAX];
    char Start[20];
    char End[20];

    printf("请输入起点景点名称：");
    scanf("%s", Start);
    int start = change(Start);
    printf("请输入终点景点名称：");
    scanf("%s", End);
    int end = change(End);

    if (start == -1 || end == -1)
    {
        printf("输入的景点名称不存在！\n");
        return;
    }

    Dijkstra(start, end, n, dist, pre, visited);

    if (dist[end] == INF)
    {
        printf("从【%s】到【%s】无可达路径！\n", Start, End);
        return;
    }

    printf("从【%s】到【%s】的最短路径为：\n", Start, End);
    Print(end, start, pre);
    printf("\n最短距离为：%d\n", dist[end]);
}
