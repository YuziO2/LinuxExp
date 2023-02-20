#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define MAXSTACK 100
int stack[MAXSTACK][2];
int size = 0;
sem_t sem;
/* 从文件1.dat读取数据，每读一次，信号量加一*/
void ReadData1(void)
{
  FILE *fp = fopen("1.dat", "r");
  while (!feof(fp))
  {
    fscanf(fp, "%d %d", &stack[size][0], &stack[size][1]);
    sem_post(&sem);
    ++size;
  }
  fclose(fp);
}
/*从文件2.dat读取数据*/
void ReadData2(void)
{
  FILE *fp = fopen("2.dat", "r");
  while (!feof(fp))
  {
    fscanf(fp, "%d %d", &stack[size][0], &stack[size][1]);
    sem_post(&sem);
    ++size;
  }
  fclose(fp);
}
/*阻塞等待缓冲区有数据，读取数据后，释放空间，继续等待*/
void HandleData1(void)
{
  while (1)
  {
    sem_wait(&sem);
    printf("Plus:%d+%d=%d\n", stack[size][0], stack[size][1],
           stack[size][0] + stack[size][1]);
    --size;
  }
}

void HandleData2(void)
{
  while (1)
  {
    sem_wait(&sem);
    printf("Multiply:%d*%d=%d\n", stack[size][0], stack[size][1],
           stack[size][0] * stack[size][1]);
    --size;
  }
}
int main(void)
{
  pthread_t t1, t2, t3, t4;
  sem_init(&sem, 0, 0);
  pthread_create(&t1, NULL, (void *)HandleData1, NULL);
  pthread_create(&t2, NULL, (void *)HandleData2, NULL);
  pthread_create(&t3, NULL, (void *)ReadData1, NULL);
  pthread_create(&t4, NULL, (void *)ReadData2, NULL);
  /* 防止程序过早退出，让它在此无限期等待*/
  pthread_join(t1, NULL);
}
