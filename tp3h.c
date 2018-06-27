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

void initColors(int n)
{
    for(int i = 0; i < n; i++)
    {
        colors[i] = 0;
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

int isSafe(int v, int n, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v-1][i] && c == colors[i])
        {
            return 0;
        }
    }
    return 1;
}

int greedyColoring(int n, int v)
{
    if(v > n)
    {
        return 1;
    }

    for(int c = 1; ; c++)
    {
        if(isSafe(v, n, c))
        {
            colors[v-1] = c;
            if(greedyColoring(n, v+1))
            {
                return 1;
            }
        }
    }
}


int minRounds(int *array, int size)
{
    int max = array[0];

    for(int i = 1; i < size; i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}

int main()
{
    FILE *rodada, *alocacao;
    rodada = fopen("rodada.txt", "w+");
    alocacao = fopen("alocacao.txt", "w+");
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    initGraph(n);
    setEdges(m);

    colors = malloc(sizeof(int)*n);
    initColors(n);

    greedyColoring(n, 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", i+1, colors[i]);
        fprintf(alocacao,"%d %d\n", i+1, colors[i]);
    }
    printf("%d\n", minRounds(colors, n));
    fprintf(rodada,"%d\n", minRounds(colors, n));

    fclose(rodada);
    fclose(alocacao);

    return 0;
}
