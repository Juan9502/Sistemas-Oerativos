#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (){

   printf("hello world (pid:%d)\n", (int) getpid());
   int rc = fork();
   int num = 10;

   if(rc < 0){
     fprintf(stderr, "fork failed\n");
     exit(1);
   }
   else if(rc == 0){
    num = num + 1;
    printf("hello, I'm the child (pid:%d)\n", (int) getpid());
   }
   else{
    int rc_wait = wait(NULL);
    num = num + 1;
    printf("hello, I'm the father of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
   }

return 0;
}
