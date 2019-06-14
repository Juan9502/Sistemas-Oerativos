#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
este programa debe imprimir lo siguiente:

soy el hijo y mi identificador es 34567
soy el hijo y mi identificador es 34566 y el de mi hijo es 34567

hacer uso de la función getpid()
*/

int main(int argc, char** argv){
  pid_t pid;

  printf("Hola\n");
  pid = fork();

  if(pid == 0){
  
  printf("Hola soy el hijo y mi id es: %d\n", (int) getpid());

  }
  else{
  int status;
  wait(&status);
 // int rc_wait = wait(NULL);
  printf("Hola soy el padre y mi id es: %d y el de mi hijo es: %d\n", (int) getpid(), pid);

  }

}
