#include <stdio.h>
#include <stdlib.h>

int **graph, *colors;

void initGraph(int size)
{
    int i;

    graph = malloc(sizeof(int*)*size);
    for(i=0; i < size; i++)
    {
        graph[i] = malloc(sizeof(int)*size);
    }
    for(int i=0; i < size; i++)
    {
        for(int j=0; j < size; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void setEdges(int m)
{
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }
}

void setColor(int v)
{
    colors[v-1] = 1;
    for(int i = 0; i < v-1; i++)
    {
        if(graph[i][v-1] && colors[i] == colors[v-1])
        {
            colors[v-1] = colors[i] + 1;
        }
    }
}

int minRounds(int *colors, int size)
{
    int max = colors[0];

    for(int i = 1; i < size; i++)
    {
        if(max < colors[i])
        {
            max = colors [i];
        }
    }

    return max;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    initGraph(n);
    colors = malloc(sizeof(int)*n);
    setEdges(m);

    for(int i=0; i < n; i++)
    {
        for(int j=0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++)
    {
        setColor(i);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", i+1, colors[i]);
    }
    printf("MIN RODADAS: %d", minRounds(colors, n));

    return 0;
}
