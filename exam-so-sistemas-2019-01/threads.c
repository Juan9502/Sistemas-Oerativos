#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int counter = 100;
puerta door;
int loops;

void *worker(void *arg) {
    int i;
    cerrar_puerta(door);
    for (i = 0; i < loops; i++) {
	counter++;
    }
    abrir_puerta(door);
    return NULL;
}

int main(int argc, char *argv[]) {
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
    return 0;
}
