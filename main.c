#include <stdio.h>
#include "head/menu.h"
#include "head/graph.h"

int main()
{
    int op;

    while (1)
    {
        main_menu();
        if (scanf("%d", &op) != 1)
        {
            printf("输入错误，请重新输入！\n");
            while (getchar() != '\n')
            {
            }
            continue;
        }

        switch (op)
        {
        case 1:
            create();
            break;
        case 2:
            show_graph();
            break;
        case 3:
            show_DFS();
            break;
        case 4:
            show_cycle();
            break;
        case 5:
            show_Dijkstra();
            break;
        case 0:
            return 0;
        default:
            printf("输入错误，请重新输入！\n");
            break;
        }
    }

    return 0;
}
