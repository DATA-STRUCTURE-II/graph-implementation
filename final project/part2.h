#ifndef PART2_H_INCLUDED
#define PART2_H_INCLUDED
#include "part1.h"

int solution=0;

int Avaliable(int N,int **maze, int **visited, int i, int j)
{
    if (maze[i][j] == 0 && visited[i][j]==0 && i < N && j < N && i >= 0 && j >= 0)
        return 1;
    return 0;
}

int checkSol(int f)
{
    if (f==1)
        return 1;
    return 0;
}

void  solve_maze(int N,int **maze, int **visited,struct queue* valueI,struct queue* valueJ, int i, int j,int x, int y)
{
    if (maze[0][0]==1||maze[N-1][N-1]==1)
    {
        return ;
    }

    if (i == x && j == y)
    {
        solution=1;
        enqueue(valueI,i);
        enqueue(valueJ,j);
        return ;
    }

    visited[i][j] = 1;

    if (Avaliable(N,maze, visited, i, j + 1))
    {
        enqueue(valueI,i);
        enqueue(valueJ,j);
        solve_maze(N,maze, visited,valueI,valueJ,i, j + 1, x, y);
        if (checkSol(solution))
            return ;
    }

    if ( Avaliable(N,maze, visited, i + 1, j))
    {
        enqueue(valueI,i);
        enqueue(valueJ,j);
        solve_maze(N,maze, visited,valueI,valueJ,i + 1, j, x, y);
        if (checkSol(solution))
            return ;
    }


    if ( Avaliable(N,maze, visited, i - 1, j))
    {
        enqueue(valueI,i);
        enqueue(valueJ,j);
        solve_maze(N,maze, visited,valueI,valueJ,i - 1, j, x, y);
        if (checkSol(solution))
            return ;
    }

    if (Avaliable(N,maze, visited, i, j - 1))
    {
        enqueue(valueI,i);
        enqueue(valueJ,j);
        solve_maze(N,maze, visited,valueI,valueJ,i, j - 1, x, y);
        if (checkSol(solution))
            return ;
    }

    visited[i][j] = 0;

}

#endif // PART2_H_INCLUDED
