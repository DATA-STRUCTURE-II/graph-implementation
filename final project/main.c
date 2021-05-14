#include <stdio.h>
#include <stdlib.h>
#include "part1.h"
#include "part2.h"
#include "part3.h"

void clear()
{
    system("PAUSE"); // press any key to continue..
    system("CLS"); // clear the screen
}

int main()
{
    int NV,NE,u,v,source,k,counter,N;
    int M,time,cost,destination;
    int **Maze_matrix,**visited;
    int **time_matrix,**cost_matrix;
    int *distance;
    struct graph* graph;
    struct queue*  valueI;
    struct queue*  valueJ;
    char selection[41];
    int choice;
    while(1)
    {
        printf("\n\t\t\t****Graph****\t\t\t\n");
        printf("    \n1. Part 1 \n");
        printf("    \n2. Part 2\n");
        printf("    \n3. Part 3\n");
        printf("    \n4. Exit \n");
        printf("\nEnter your choice : ");

        do
        {
            gets(selection);
            choice = atoi(selection);
        }
        while (choice < 1 || choice > 5);
        system("CLS");
        switch(choice)
        {
        case 1:
            printf("\t**********Part 1**********\n");
            printf("\nplease Enter number of vertices:\n ");
            scanf("%d",&NV);
            graph = Newgraph(NV);
            printf("please Enter number of edges:\n ");
            scanf("%d",&NE);
            printf("please enter edges in the form (u v):\n");
            for(int i=1; i<=NE; i++)
            {
                scanf("%d %d",&u,&v);
                creategraph(graph,u,v);
            }
            printf("please enter starting vertex : \n");
            scanf("%d",&source);
            printf("please enter value k : \n");
            scanf("%d",&k);
            distance=bfs(graph,source,NV);
            counter=count(k,distance,NV);
            if (counter==-1)
            {
                printf("No connection only %d\n",source);
            }
            else
            {

                printf("\nThere are %d people with %d connections away starting from %d \n",counter,k,source);
            }
            printf("\n");
            clear();
            break;

        case 2:
            printf("\t**********Part 2**********\n");
            printf("\nPlease enter N :\n");
            scanf("%d",&N);
            Maze_matrix=(int **)calloc(N, sizeof(int *));
            visited=(int **)calloc(N, sizeof(int *));
            for (int i=0; i<=N; i++)
            {
                Maze_matrix[i] = (int *)calloc(N,sizeof(int));
            }
            for (int i=0; i<=N; i++)
            {
                visited[i] = (int *)calloc(N,sizeof(int));
            }
            valueI=  createQueue(2*N);
            valueJ = createQueue(2*N);
            printf("please enter values for maze:\n");
            for(int i=0; i<N; i++)
            {
                printf("\n");
                for(int j=0; j<N; j++)
                {
                    scanf("%d",&Maze_matrix[i][j]);
                }
            }
            solve_maze(N,Maze_matrix,visited,valueI,valueJ,0, 0, N-1, N-1);
            if (solution == 1)
            {
                printf("\n\nsolution:\n");
                while(!isEmpty(valueI)&&!isEmpty(valueJ))
                {
                    printf("(%d,%d) ",dequeue(valueI),dequeue(valueJ));
                }
                printf("\n");
            }
            else
            {
                printf("no path found \n");
            }
            printf("\n");
            clear();
            break;

        case 3:
            printf("\t**********Part 3**********\n");
            printf("\nplease enter amount M:\n");
            scanf("%d",&M);
            printf("please enter number of cities:\n");
            scanf("%d",&NV);
            printf("please enter number of routes:\n");
            scanf("%d",&NE);
            time_matrix = (int **)calloc(NV, sizeof(int *));
            for (int i=1; i<=NV; i++)
            {
                time_matrix[i] = (int *)calloc(NV, sizeof(int));
            }
            cost_matrix = (int **)calloc(NV, sizeof(int *));
            for (int i=1; i<=NV; i++)
            {
                cost_matrix[i] = (int *)calloc(NV, sizeof(int));
            }
            printf("please enter source , destination time and cost for each route: \n");
            for (int i=1; i<=NE; i++)
            {
                scanf("%d %d %d %d",&u,&v,&time,&cost);
                time_matrix[u][v]=time_matrix[v][u]=time;
                cost_matrix[u][v]=cost_matrix[v][u]=cost;
            }
            printf("please enter source city:\n");
            scanf("%d",&source);
            printf("please enter destination city:\n");
            scanf("%d",&destination);
            dijkstra(cost_matrix,time_matrix,NV,source,destination,M);
            printf("\n");
            clear();
            break;

        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}
