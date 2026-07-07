#include <stdio.h>
#include <string.h>
#include "../head/graph.h"

Graph g;

// 文字转下标
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

// 创建新的邻接矩阵
void create()
{

    // 初始化矩阵
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            g.graph[i][j] = 32767;
        }

        //对角线为0
        for (int k = 0; k < g.spot; k++)
        {
            g.graph[k][k] = 0;
        }
    }

    // 录入数据
    printf("请输入顶点数:");
    scanf("%d", &g.spot);

    printf("请输入边数:");
    scanf("%d", &g.edge);
    printf("\n");

    printf("请输入各顶点的名字:\n");
    for (int i = 1; i <= g.spot; i++)
    {
        printf("第%d个景点:", i);
        scanf("%s", g.name[i]);
    }
    printf("\n");

    char u[20], v[20];
    int w = 0;
    for (int i = 1; i <= g.edge; i++)
    {
        printf("输入第%d条边的两个顶点以及该边的权值(空格分隔):", i);
        scanf("%s %s %d", u, v, &w);
        int v1 = change(u);
        int v2 = change(v);

        // 权值
        g.graph[v1][v2] = w;
        g.graph[v2][v1] = w;
    }

    printf("\n");
    printf("景区景点图创建成功！");
}

//
void show_graph()
{
    printf("景区景点分布图（邻接矩阵）：\n");
    printf(" ");

    // 表头
    for (int i = 0; i <= g.spot; i++)
    {
        printf("%s ", g.name[i]);
    }
    printf("\n");

    // 内容
    for (int i = 1; i <= g.spot; i++)
    {
        printf("%s ", g.name[i]);
        for (int j = 1; j <= g.spot; j++)
        {
            printf("%d ", g.graph[i][j]);
        }
        printf("\n");
    }
}