#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../head/graph.h"

Graph g;
SeqList sl;

//顺序表初始化
void InitSeaList(SeqList* sl,int initCap){
    sl->data = (int*)malloc(sizeof(int) * initCap);
    sl->length = 0;
    sl->capacity = initCap;
}

//尾插法存表
void AddData(SeqList* sl, int x){

       // 判断是否满了，满了扩容
    if (sl->length >= sl->capacity) {
        sl->capacity *= 2;
        sl->data = (int*)realloc(sl->data, sizeof(int) * sl->capacity);
    }

    // 存入数据，长度+1
    sl->data[sl->length] = x;
    sl->length++;
}

//递归法DFS
int DFS(int son,int parent,int visited[],SeqList* sl){

    visited[son]=1;
    AddData(sl,son);

    for (int i=1;i<=g.spot;i++){

        if(g.graph[son][i]!=INF){

             //邻顶点未访问
            if(!visited[i]){
                if (DFS(i,son,visited,sl)){    
                    return 1;
                }
            }

            //邻顶点已访问
             else if(son!=parent){
                return 1;
            }
        }
    }
    return 0;
}

 
void show_DFS(){
    
    InitSeaList(&sl,MAX);

    printf("请输入起点：");
    char Jd[20];
    scanf("%s",Jd);
    int jd=change(Jd);
    
    printf("导游路线为：");
  
    for (int i=0;i<sl.length;i++){

        //下标转字符串
           char *name[MAX]=rechang(sl.data[i]);

        if (i==0){
              printf("%s",Jd);
        }
        else{
            printf("-%s",name[i]);
        }
   
    }

}

//DFS遍历法判断是否有回路
void show_cycle(){
    printf("请输入起点:");
    char Begin[MAX];
    scanf("%s",Begin);
    int begin=change(Begin);

    int* visited = (int*)calloc(g.spot + 1, sizeof(int));
    int road=DFS(begin,-1,visited,&sl);

    if (road){
        printf("图中有回路,回路为:");
        for (int i=0;i<sl.length;i++){
            char Begin[MAX]=rechange(begin);
            if (i == 0){
                pintf("%s", Begin);
                 }
            else{
                printf("→%s", Begin);
                }
            }
        }
                
    else{
         printf("该图中无回路");
    }
       
}