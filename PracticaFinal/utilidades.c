#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define nombrefichero "citas.txt"
#include "utilidades.h"


void datospersonales()
{
    
  printf("Alumno : Diego Juarez Romero\n");
    printf("DNI/NIE: 48559187T\n");
      printf("E-mail : diego.juarez01@alu.umh.es\n\n");
        printf("Ejercicio 1: HECHO\n\n");
            printf("Ejercicio 2: HECHO\n\n");
                printf("Ejercicio 3: HECHO\n\n");
                    printf("Ejercicio 4: HECHO\n\n");
}

//Funcion para confirmar si se introdujo un numero en el comando frase -
int  confirmarNumero(char *token,int *cadenanumerica){             
                    int longitud=0,i,numeroconfirmado;   
                    longitud = strlen(token);
                    //Guardamos el valor ascii en cadenanumerica para recorrerla luego.
                     for(i=0;i<longitud;i++){
                     cadenanumerica[i] = (int)(token[i]-48);
                    }
                //Recorre la cadena introducida por el usuario, 
                //seguira ejecutandose hasta que se introduzca una letra.
                        for(i=0;i<longitud;i++){
                            //Si es un numero ascii (48 a 57 del 0 al 9)
                    if ((cadenanumerica[i] >= 0 && cadenanumerica[i] <= 9 )){
                        numeroconfirmado = 1;
                        }
                       else{                   
                            numeroconfirmado = 0;
                            break;
                            }                    
                                                }
                    if(longitud==2){
                    for (i=0;i<1;i++){
                    cadenanumerica[0] = cadenanumerica[0]*10 + cadenanumerica[1];
                                     }
                                   }
                    else if(longitud==3){
                    for (i=0;i<1;i++){
                    cadenanumerica[0] = cadenanumerica[0]*100 + cadenanumerica[1]*10 + cadenanumerica[2];
                                     }     
                                         }
                    else if(longitud==4){
                    for (i=0;i<1;i++){
                    cadenanumerica[0] = cadenanumerica[0]*1000 + cadenanumerica[1]*100 + cadenanumerica[2]*10 + cadenanumerica[3];
                                     }     
                                         }       
                     else if(longitud>4){
                            numeroconfirmado = 0;
                            }                                                   
                     return numeroconfirmado;   
                }
