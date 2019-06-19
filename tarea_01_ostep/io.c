#include <stdio.h>
#include <stdlib.h>

int main(){

   FILE * flow = fopen("archivo.txt", "rb");

      if(flow == NULL){
        perror("No se pudo acceder al archivo");
        return 1;
      }

      char letra;

     int pos;

    // pos = ftell(flow);
    pos = fseek(flow, -3, SEEK_END);

    if(pos == 0){
     printf("posicion 1\n");
    }else{
      printf("posicion----\n");
     }

   /*  while(feof(flow) == 0){

        letra = fgetc(flow);
        printf("%c", letra);
          }*/

  fclose(flow);
  printf("\nLECTURA EXITOSA");


return 0;
}
