#include <stdio.h>
#include <stdlib.h>
#include "../head/graph.h"

static SeqList sl;

void InitSeaList(SeqList *sl, int initCap)
{
    if (sl->data)
    {
        free(sl->data);
    }
    sl->data = (int *)malloc(sizeof(int) * initCap);
    sl->length = 0;
    sl->capacity = initCap;
}

void AddData(SeqList *sl, int x)
{
    if (sl->length >= sl->capacity)
    {
        sl->capacity *= 2;
        sl->data = (int *)realloc(sl->data, sizeof(int) * sl->capacity);
    }
    sl->data[sl->length] = x;
    sl->length++;
}

static void appendVertex(SeqList *path, int v)
{
    if (path->length > 0 && path->data[path->length - 1] == v)
    {
        return;
    }
    AddData(path, v);
}

static int hasUnvisitedRemaining(int visited[])
{
    for (int i = 0; i < g.spot; i++)
    {
        if (!visited[i])
        {
            return 1;
        }
    }
    return 0;
}

static int isAncestor(int anc, int v, int treeParent[])
{
    int p = treeParent[v];
    while (p != -1)
    {
        if (p == anc)
        {
            return 1;
        }
        p = treeParent[p];
    }
    return 0;
}

void generateGuideRoute(SeqList *path)
{
    path->length = 0;
    InitSeaList(path, MAX);

    int visited[MAX] = {0};
    int treeParent[MAX];
    for (int i = 0; i < MAX; i++)
    {
        treeParent[i] = -1;
    }

    int current = 0;
    visited[0] = 1;
    appendVertex(path, 0);

    int guard = 0;
    while (guard++ < g.spot * g.spot * 2)
    {
        int next = -1;
        for (ArcNode *p = g.adjlist[current]; p != NULL; p = p->next)
        {
            if (!visited[p->adjvex])
            {
                next = p->adjvex;
                treeParent[next] = current;
                visited[next] = 1;
                appendVertex(path, next);
                current = next;
                break;
            }
        }
        if (next != -1)
        {
            continue;
        }

        if (!hasUnvisitedRemaining(visited))
        {
            break;
        }

        int shortcut = -1;
        int allVisitedNeighbors = 1;
        for (ArcNode *p = g.adjlist[current]; p != NULL; p = p->next)
        {
            if (!visited[p->adjvex])
            {
                allVisitedNeighbors = 0;
            }
            else if (p->adjvex != treeParent[current] && shortcut == -1)
            {
                shortcut = p->adjvex;
            }
        }

        if (allVisitedNeighbors && shortcut != -1 &&
            isAncestor(shortcut, current, treeParent))
        {
            appendVertex(path, shortcut);
            current = shortcut;
            continue;
        }

        int back = treeParent[current];
        while (back != -1)
        {
            appendVertex(path, back);
            for (ArcNode *p = g.adjlist[back]; p != NULL; p = p->next)
            {
                if (!visited[p->adjvex])
                {
                    treeParent[p->adjvex] = back;
                    visited[p->adjvex] = 1;
                    appendVertex(path, p->adjvex);
                    current = p->adjvex;
                    goto continueLoop;
                }
            }
            back = treeParent[back];
        }
        break;

    continueLoop:
        continue;
    }
}

static void printRoute(SeqList *path)
{
    for (int i = 0; i < path->length; i++)
    {
        if (i == 0)
        {
            printf("%s", rechange(path->data[i]));
        }
        else
        {
            printf("-%s", rechange(path->data[i]));
        }
    }
    printf("-\n");
}

static int extractCycle(SeqList *path, int cycle[], int *cycleLen)
{
    int firstPos[MAX];
    for (int i = 0; i < g.spot; i++)
    {
        firstPos[i] = -1;
    }

    for (int i = 0; i < path->length; i++)
    {
        int v = path->data[i];
        if (firstPos[v] != -1)
        {
            *cycleLen = 0;
            for (int j = firstPos[v]; j <= i; j++)
            {
                cycle[(*cycleLen)++] = path->data[j];
            }
            return 1;
        }
        firstPos[v] = i;
    }
    return 0;
}

void show_DFS()
{
    if (g.spot == 0)
    {
        printf("??????????????????\n");
        return;
    }

    generateGuideRoute(&sl);
    printf("???????????\n");
    printRoute(&sl);
}

void show_cycle()
{
    if (g.spot == 0)
    {
        printf("??????????????????\n");
        return;
    }

    generateGuideRoute(&sl);

    int cycle[MAX];
    int cycleLen = 0;
    if (extractCycle(&sl, cycle, &cycleLen))
    {
        printf("??????????????????");
        for (int i = 0; i < cycleLen; i++)
        {
            if (i == 0)
            {
                printf("%s", rechange(cycle[i]));
            }
            else
            {
                printf("-%s", rechange(cycle[i]));
            }
        }
        printf("\n");
    }
    else
    {
        printf("??????????\n");
    }
}
