#include <stdio.h>
#include <stdlib.h>

int main(){

   FILE * flow = fopen("archivo.txt", "rb");

      if(flow == NULL){
        perror("No se pudo acceder al archivo");
        return 1;
      }

      char letra;

     while(feof(flow) == 0){

        letra = fgetc(flow);
        printf("%c", letra);
          } 

  fclose(flow);
  printf("\nLECTURA EXITOSA");
  

return 0;
}
