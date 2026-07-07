#include <stdio.h>
#include "head/menu.h"
#include "head/graph.h"


int main (){
    main_menu();

    int op;
    while(1){
    scanf("%d",&op);
        switch (op)
        {
        //1.创建景区景点图
        case 1:
            create();
            break;

        //2.景区景点分布图
        case 2:
            show_graph();
            break;

        //3.导游线路
        case 3:
            //DFS();
            break;

        //4.导游线路中的回路
        case 4:
            //cycle();
            break;

        //5.两个景点间的最短路径和距离
        case 5:
            //Dijkstra();
            break;

        //0.退出系统
        case 0:
            return 0;
        
        //输入不合法
        default:
            printf("输入错误，请重新输入！");
            break;
        }
    }
    
    return 0;
}