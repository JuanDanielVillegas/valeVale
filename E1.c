#include<stdlib.h>
#include<stdio.h>

int main(){
    
    int arreglo[] = {10, 5, 1}; 
    int *arreglo_dos;
    
    arreglo_dos = (int *)&arreglo;
    
    printf("Elemento A1: %d\n", *(arreglo+2));
    printf("Elemento A2: %d\n", arreglo_dos[1]);
    
    return 0;
}