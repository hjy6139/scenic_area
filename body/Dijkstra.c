#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../head/graph.h"

Graph g;


void Dijkstra(int start, int end, int n, int dist[], int pre[], int visited[])
{
    //初始化
    for (int i = 1; i <= n; i++)
    {
        dist[i] = g.graph[start][i];
        visited[i] = 0;
        pre[i] = start;
    }
    visited[start] = 1;

    for (int j = 1; j <= n - 1; j++)
    {
        int u = -1;
        int wu = INF; //无通路
        for (int k = 1; k <= n; k++)
        {
            if (!visited[k] && dist[k] < wu)
            {
                wu = dist[k];
                u = k;
            }
        }

        //u最短路径
        if (u == -1) break;
        visited[u] = 1;
        if (u == end) break;

        //以u为基准
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v] && g.graph[u][v] != INF && dist[u] + g.graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + g.graph[u][v];
                pre[v] = u;
            }
        }
    }
}

//打印路线
void Print(int cur, int st)
    {
        int pre[MAX];
        if(cur == st)
        {
            printf("%s", rechang(cur));
            return;
        }
        Print(pre[cur], st);
        printf("→ %s", rechang(cur));
    }

void show_Dijkstra(){
    int dist[MAX];
    int pre[MAX];
    int n=g.spot;
    int visited[n+1];
    char Start[20];
    char End[20];

    printf("请输入起点景点名称:");
    scanf("%s",Start);
    int start=change(Start);
    printf("请输入终点景点名称:");
    scanf("%s",End);
    int end=change(End);

    Dijkstra(start, end, n, dist, pre, visited);

    if (dist[end] == INF)
    {
        printf("从【%s】到【%s】无可达路径!\n", Start, End);
        return;
    }

    printf("从【%s】到【%s】的最短路径为:\n", Start, End);

    
    Print(end, start);

    printf("\n最短距离为:%d\n", dist[end]);
}