#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{ 
  int count = 0;

  pid_t pid = fork();
  int status = -1;
  
  if(pid<0)
  {
    printf("fork error for %m\n",errno );
  }
  else if(pid>0)
  {
    printf("this is parent ,pid = %d\n",getpid() );
    wait(&status);
  }
  else
  {
    printf("this is child , pid = %d , ppid = %d\n",getpid(),getppid() );
    int i;
    
    for (i = 0; i < 10; i++) {
      count++;
      sleep(1);
      printf("count = %d\n", count);
    }
    exit(5);
  }
  printf("child exit status is %d\n", WEXITSTATUS(status));
  printf("end of program from pid = %d\n",getpid()); 
}