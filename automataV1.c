#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

#define q0 0
#define q1 1
#define q2 2


int main(){

    int estado = q0;
    int longitud = 0;
    int i = 0;

    char cadena[100];
    char entrada;

    bool fin = false;
    

    while(fin == false){
        switch(estado){
            case q0:
                printf("Estado q0\n");
                printf("Entrada: ");
                entrada = getchar();
                getchar();
                if(entrada == 'a'){
                    estado = q2;
                    cadena[i] = entrada;
                    i++;
                }
                break;
            case q1:
                printf("Estado q1\n");
                printf("Cadena Aceptada: ");
                cadena[i] = '\0';
                printf("%s\n", cadena);
                
                printf("Entrada: ");
                entrada = getchar();
                getchar();
                if(entrada == 'c'){
                    estado = q0;
                    cadena[i] = entrada;
                    i++;
                }
                break;
            case q2:
                printf("Estado q2\n");
                printf("Entrada : ");
                entrada = getchar();
                getchar();
                if(entrada == 'b'){
                    estado = q1;
                    cadena[i] = entrada;
                    i++;
                }
                break;
        }

    }
    return 0;
}