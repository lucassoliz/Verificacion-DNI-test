#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void limpiarBuffer(){
    while (getchar() != '\n'); //limpiamos el buffer de entrada
}

/* Verificamos que tenga 8 digitos si o si, y que compruebe que todos
sean digitos numericos */

bool validarFormatoDNI(char dni[]){
    int longitud = strlen(dni); //obtenemos la longitud del dni
    if(longitud !=8){
        printf("DNI no valido, debe tener exactamente 8 digitos");
        return false;
    }
    for (int i = 0; i < 8; i++){
        if (dni[i] < '0' || dni[i] > '9') 
        {
            printf("el dni contiene caracteres que no son numericos");
            return false;
        }
    }
    return true;
}

//funcion para validar el formato de un dni
bool validarDigitoVerificador(char dni[]){
    int digitos[8];
    int suma = 0;
    int digitoVerificador = 0;
    for(int i=0; i<8; i++){
        digitos[i]= dni[i] - '0';
    }
    for(int i=0; i<7; i++){
        suma += digitos[i]*(i+2);
    }
    digitoVerificador = suma % 11;
    if(digitoVerificador == 10){
        digitoVerificador = 1;
    }
    return digitoVerificador == digitos[7];
}

int main(){
    char dni[9];
    char opcion;
    
    do {
        printf("ingrese el dni: ");
        scanf("%8s", dni);
        limpiarBuffer();
        
        if(validarFormatoDNI(dni)){
            if(validarDigitoVerificador(dni)){
                printf("DNI valido\n");
            }else{
                printf("DNI no valido\n");
            }
        }
        
        printf("Desea validar otro DNI? (S/N): ");
        opcion = getchar();
        limpiarBuffer();
        
    } while(opcion == 'S' || opcion == 's');
    
    return 0;
}