// AIM: TO IMPLEMENT ALL PAIR SHORTEST PATH ALGORITHM.
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int c[100][100], p[100][100];  //c-cost matrix, p-path matrix(to store the path)
int inf = 1000, v;     //Assume Infinity as 1000
//int min(int x, int y);
void show();
void path(int, int);

int main()
{
  int i, j, k, x;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &v);

  /*
   for(i=1;i<=v;i++)
    for(j=1;j<=v;j++)
     if(i==j)
      c[i][j]=0;
     else
     {
      printf("Is %d connected to %d?",i,j);
      printf("If yes, enter weight, else enter %d: ",inf);
      scanf("%d", &c[i][j]);
     }
  */

  printf("\nEnter adjacency matrix:\n");
  printf("(Enter 1000 if there is no path)\n");
  for (i = 1;i <= v;i++)
    for (j = 1;j <= v;j++)
    {
      scanf("%d", &c[i][j]);
      p[i][j] = -1;
    }

  printf("\n");

  for (k = 1;k <= v;k++)
  {
    for (i = 1;i <= v;i++)
    {
      for (j = 1;j <= v;j++)
      {
        if (i == j)
          c[i][j] = 0;
        else
        {
          x = c[i][k] + c[k][j];
          if (c[i][j] > x)
          {
            c[i][j] = x;
            p[i][j] = k;
          }
        }
      }
    }
    show();
    printf("\n");
  }

  printf("From\tTo\tPath\t\tTotal Min. Cost\n");
  for (i = 1;i <= v;i++)
  {
    for (j = 1;j <= v;j++)
    {
      if (i != j)
      {
        printf("%d\t", i);
        printf("%d\t", j);

        //    printf("Path from %d to %d is: ",i,j);
        printf("%d", i);
        path(i, j);
        printf("%d", j);

        printf("\t\t%d", c[i][j]);
        printf("\n");
      }
    }
  }
  getch();
  return 0;
}

//-------TO SHOW THE PASSES-------
void show()
{
  int i, j;
  for (i = 1;i <= v;i++)
  {
    for (j = 1;j <= v;j++)
      if (c[i][j] == 1000)
        printf("INF\t");
      else
        printf("%d\t", c[i][j]);
    printf("\n");
  }
}

//-------TO SHOW THE PATH-------
void path(int i, int j)
{
  int k;

  k = p[i][j];
  if (k == -1)
  {
    printf("->");
    return;
  }
  path(i, k);
  printf("%d", k);
  path(k, j);
}

/* OUTPUT

Enter the number of vertices in the graph: 3

Enter adjacency matrix:
(Enter 1000 if there is no path)
0 8 5
3 0 1000
1000 2 0

0       8       5
3       0       8
INF     2       0

0       8       5
3       0       8
5       2       0

0       7       5
3       0       8
5       2       0

From    To      Path            Total Min. Cost
1       2       1->3->2         7
1       3       1->3            5
2       1       2->1            3
2       3       2->1->3         8
3       1       3->2->1         5
3       2       3->2            2 */