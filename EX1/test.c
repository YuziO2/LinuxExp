#include <stdio.h>

int main()
{
  int stack[100][2];
  int size = 0;
  FILE *fp = fopen("1.dat", "r");
  while (!feof(fp))
  {
    fscanf(fp, "%d %d", &stack[size][0], &stack[size][1]);
    // sem_post(&sem);
    ++size;
  }
  fclose(fp);
}