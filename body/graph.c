#include <stdio.h>
#include "../head/graph.h"

Graph graph;

//创建邻接矩阵
void create(){

    //初始化矩阵
    for (int i=0;i<MAX;i++){
        for (int j=0;j<MAX;j++){
            graph.graph[i][j]=0;
        }
    }

    printf("请输入顶点数:");
    scanf("%d",&graph.spot);
    printf("\n");

    printf("请输入边数:");
    scanf("%d",&graph.edge);
    printf("\n");

    printf("请输入各顶点的名字:\n");
    for (int i=1;i<=graph.spot;i++){
        printf("第%d个景点:",i);
        scanf("%s",&graph.name[i]);
        printf("\n");
    }
    printf("\n");

     char u,v;
     int w;
     for (int i=1;i<=&graph.edge;i++){
        printf("输入第%d条边的两个顶点以及该边的权值:\n",i);
        scanf("%s %s %d",&u,&v);
        printf("\n");
    }
}

void Dijkstra(){

}

void DFS(){

}