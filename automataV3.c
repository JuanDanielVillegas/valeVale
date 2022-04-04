#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>
#include<windows.h>

#define q0 0
#define q1 1
#define q2 2

#define TAM 100

void imprimirRuta(int ruta[], int tam);

int main(){

    int estado = q0;
    int i = 0;

    char cadena[TAM];
    char cadenaNoValida[TAM];
    int ruta[TAM];
    char cadenaAceptada[TAM];
    char entrada;

    bool terminar = false;

    bool q0_q1 = false;
    bool q1_q1 = false;
    
    char digitos [] = {'0','1','2','3','4','5','6','7','8','9'};

    system("cls");

    while(terminar == false){
        switch(estado){
            case q0:
                printf("==============================\n");
                printf("Estado q0\n");
                printf("Entrada: ");
                entrada = getchar();
                getchar();

                for(int j = 1; j<=9; j++){
                    if(entrada == digitos[j]){
                        q0_q1 = true;
                    }
                }

                if(q0_q1 == true){
                    estado = q1;
                    q0_q1 = false;
                }else{
                    estado = q2;
                }
                cadena[i] = entrada;
                ruta[i] = 0;
                i++;
                
                break;
            case q1:
                printf("\n==============================\n");
                printf("Estado q1\n");
                printf("Cadena Aceptada -> ");
                cadena[i] = '\0';
                printf("%s\n", cadena);
                
                printf("Entrada: ");
                entrada = getchar();
                getchar();

                for(int j = 0; j<=9; j++){
                    if(entrada == digitos[j]){
                        q1_q1 = true;
                    }
                }

                if(q1_q1 == false){
                    estado = q2;
                }
                q1_q1 = false;
                ruta[i] = 1;
                cadena[i] = entrada;
                i++;
                break;
            case q2:
                printf("\n==============================\n");
                printf("\nEstado q2\n");
                printf("Cadena No valida -> ");
                cadena[i] = '\0';
                printf("%s\n", cadena);
                printf("Ruta: ");

                imprimirRuta(ruta, i);

                printf("\nEntrada : ");
                entrada = getchar();
                getchar();
                
                estado = q2;
                ruta[i] = 2;
                cadena[i] = entrada;
                i++;
                break;
        }
    }
    return 0;
}

void imprimirRuta(int ruta[], int tam){
    for(int j = 0; j < tam; j++){
        printf("q%d -> ", ruta[j]);
    }
    printf("q2");
}