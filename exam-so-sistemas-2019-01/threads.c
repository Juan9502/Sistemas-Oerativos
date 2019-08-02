#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <time.h>

volatile int counter = 100;
puerta door;
int loops;
double seg; //variable para guardar el tiempo de ejecucion
void *worker(void *arg) {
    int i;
    cerrar_puerta(door);//cierra la puerta
    for (i = 0; i < loops; i++) {
        cerrar_puerta(door);//cierra la puerta antes de incrementar la variable
	counter++;
    }
    abrir_puerta(door);//abre la puerta
    return NULL;
}

int main(int argc, char *argv[]) {
    //para medir el tiempo
    clock_t t_ini, t_fin;

    t_ini = clock();
    if (argc != 2) { 
	fprintf(stderr, "usage: threads <loops>\n"); 
	exit(1); 
    }


    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    abrir_puerta(door);
    printf("Final value   : %d\n", counter);
    destruir_puerta(door);
    t_fin = clock();

    seg = (double) (t_fin - t_ini) / CLOCKS_PER_SEC; //calcula el tiempo
   // printf("tiempo: \n", seg);
    return 0;
}
