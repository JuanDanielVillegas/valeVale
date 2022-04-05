#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>

#define q0 0
#define q1 1
#define q2 2

#define TAM 100

void imprimircaracteresNoVal(char caracteresNoVa[], int cantidad);
bool caracterRepetido(char caracteresNoVa[], int cantidad,  char entrada);

int main(int argc, char *argv[]){

    int i = 0;
    int estado = q0;
    int cuentaCaracteresInv = 0;

    char entrada;
    char cadena[TAM];
    char caracteresNoVal[TAM];
    char digitos [] = {'0','1','2','3','4','5','6','7','8','9'};

    bool q0_q1 = false;
    bool q1_q1 = false;
    bool valido = false;
    bool terminar = false;
    
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

                cadena[i] = entrada;
                i++;

                if(q0_q1 == true){
                    estado = q1;
                    q0_q1 = false;
                }else{
                    estado = q2;
                    caracteresNoVal[cuentaCaracteresInv] = entrada;
                    cuentaCaracteresInv++;
                }
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

                cadena[i] = entrada;
                i++;

                for(int j = 0; j<=9; j++){
                    if(entrada == digitos[j]){
                        q1_q1 = true;
                    }
                }

                if(q1_q1 == false){
                    estado = q2;
                     if(caracterRepetido(caracteresNoVal, cuentaCaracteresInv, entrada) == false){
                        caracteresNoVal[cuentaCaracteresInv] = entrada;
                        cuentaCaracteresInv++;
                    }   
                }
                q1_q1 = false;
                break;
            case q2:
                printf("\n==============================\n");
                printf("\nEstado q2\n");
                printf("Cadena No valida -> ");
                cadena[i] = '\0';
                printf("%s\n", cadena);
                printf("Lista Caracteres Invalidos: ");

                imprimircaracteresNoVal(caracteresNoVal, cuentaCaracteresInv);

                printf("\nEntrada : ");
                entrada = getchar();
                getchar();
                cadena[i] = entrada;
                i++;
 
                estado = q2;             
                
                for(int j = 0; j<=9; j++){
                    if(entrada == digitos[j]){
                        valido = true;
                        printf("%c", entrada);
                    }
                }
                if(valido != true){
                    if(caracterRepetido(caracteresNoVal, cuentaCaracteresInv, entrada) == false){
                        caracteresNoVal[cuentaCaracteresInv] = entrada;
                        cuentaCaracteresInv++;
                    }              
                }
                valido = false;             
                break;
        }
    }
    return 0;
}

void imprimircaracteresNoVal(char caracteresNoVal[], int cantidad){
    for(int j = 0; j < cantidad; j++){
        printf("%c ", caracteresNoVal[j]);
    }
}

bool caracterRepetido(char caracteresNoVa[], int cantidad, char entrada){
    bool repetido = false;
    for(int j = 0; j < cantidad; j++){
        if(entrada == caracteresNoVa[j]){
            repetido = true;
        }
    }
    return repetido;
}