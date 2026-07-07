#include <stdio.h>
#include <string.h>
#include "../head/graph.h"

Graph g;


//创建新的邻接矩阵
void create(){

    //初始化矩阵
    for (int i=0;i<MAX;i++){
        for (int j=0;j<MAX;j++){
            g.graph[i][j]=0;
        }
    }

    //录入数据
    printf("请输入顶点数:");
    scanf("%d",&g.spot);

    printf("请输入边数:");
    scanf("%d",&g.edge);
    printf("\n");

    printf("请输入各顶点的名字:\n");
    for (int i=1;i<=g.spot;i++){
        printf("第%d个景点:",i);
        scanf("%s",&g.name[i]);
    }
    printf("\n");

     char u[20],v[20];
     int w;
     for (int i=1;i<=g.edge;i++){
       printf("输入第%d条边的两个顶点以及该边的权值:\n",i); 
       scanf("%s %s %d",u,v,&w);
        //文字转下标
        for (int j=0;j<g.spot;j++){
        if (strcmp(g.graph[j],u)==0){
                return j;
         }
        return -1;
        if (strcmp(g.graph[j],v)==0){
                return j;
         }
        return -1;  

        
        //权值
        g.edge[u][v]=w;
        g.edge[v][u]=w;
        }
    }
     printf("\n");
    printf("景区景点图创建成功！");
}

void show_graph(){
    printf("景区景点分布图（邻接矩阵）：");
    printf(" ");
    
    //表头
    for (int i=0;i<g.spot;i++){
        printf("%s",g.name[i]);
    }

    //内容
    for (int i=0;i<g.spot;i++){
        printf("%s",g.name[i]);
        for (int j=0;j<g.spot;j++){
            printf("%d",g.graph[i][j]);
        }
    }
}