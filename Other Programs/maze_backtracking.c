//Solving a given maze using backtracking(Rat in maze problem)
#include <stdio.h>
#include <stdbool.h>

#define size 5
struct stack_type
{
    int i_ind;
    int j_ind;
};
struct todel
{
    int i;
    int j;
};
int top = -1;
char maze[size][size] = {{'X', 'S', 'X', 'X','X'}, {'X', ' ', 'X', 'X','X'}, {'X', ' ', ' ', ' ',' '}, {' ', ' ', 'X', 'X','D'},{'X',' ','X','X','X'}};
int starti = 0, startj = 1, endi = 3, endj = 4;
struct stack_type stack[size * size];
struct todel del[size*size];
int deltop=0;


void show()
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("%c", maze[i][j]);
        printf("\n");
    }
}

void push(int i, int j)
{
    stack[++top].i_ind = i;
    stack[top].j_ind = j;
    if (maze[i][j] != 'D')
        maze[i][j] = 'V';
}


void pop()
{
    int i=stack[top].i_ind,j=stack[top].j_ind;
    del[deltop].i=i;
    del[deltop].j=j;
    deltop++;
    top--;
}

int solve()
{
    int i = starti, j = startj;

    while (maze[i][j] != 'D')
    {
        bool moved = false;

        if (i + 1 < size && maze[i + 1][j] != 'X' && maze[i + 1][j] != 'V')
        {
            push(i + 1, j);
            i += 1;
            moved = true;
        }
        else if (j + 1 < size && maze[i][j + 1] != 'X' && maze[i][j + 1] != 'V')
        {
            push(i, j + 1);
            j += 1;
            moved = true;
        }
        else if (i - 1 >= 0 && maze[i - 1][j] != 'X' && maze[i - 1][j] != 'V')
        {
            push(i - 1, j);
            i -= 1;
            moved = true;
        }
        else if (j - 1 >= 0 && maze[i][j - 1] != 'X' && maze[i][j - 1] != 'V')
        {
            push(i, j - 1);
            j -= 1;
            moved = true;
        }

        if (!moved)
        {
            // Dead end, backtrack
            pop();
            if (top == -1)
            {
                printf("No path found.\n");
                return 0;
            }
            i = stack[top].i_ind;
            j = stack[top].j_ind;
        }
    }
    
    return 1;
}
void modify()
{
    for(int i=0;i<deltop;i++)
        maze[del[i].i][del[i].j]=' ';
}

int main()
{
    show();
    printf("\n");
    if (solve())
    {
        printf("\nPath found:\n");
        modify();
        show();
    }

    printf("End\n");
    return 0;
}
