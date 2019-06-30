#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char*argv[]){

  int pidPadre = getpid();
  int rc = fork();

   if (rc < 0) {
     fprintf(stderr, "fork failed\n");
     exit(1);
   }
   else if (rc == 0) {
     printf("hola\n");
     kill(pidPadre, SIGCONT); //para detener el proceso de padre
   }
   else {
     printf("adios\n");
     signal(SIGCONT, sig_handler);
     pause();
  }
return 0;
}
