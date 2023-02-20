#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  int pid = fork();
  if (pid > 0)
  {
    printf("这是父亲，儿子进程id是：%d\n", pid);
  }
  else
  {
    printf("这是儿子\n");
    execl("/bin/ls", "ls", "-a", "/", NULL);
  }
}