#include <stdio.h>
/*

Hacer un programa que pida que el usuario introduzca un valor entero, 
si el valor es impar el programa dibujara un tri�ngulo como este:

   *
  ***
 *****
*******

Este ejemplo es para el caso de que el usuario haya introducido el valor 7, 
notar que hay siete asteriscos en la base del tri�ngulo.
Si el n�mero introducido por el usuario fuera par el programa 
responder� con el mensaje "No se puede dibujar el tri�ngulo" y 
terminar� sin dibujar nada. Para saber si un valor 'n' es par bastar� con verificar esta condici�n:

// Si esta expresi�n devuelve 'verdadero', n es par
if ((n%2)==0)



*/
int main(int argc, char *argv[])
{
  int n;
  int fila,col;
  int c=1;
    printf("Introduzca el numero maximo de filas de su triangulo: \n");
    scanf("%d",&n);
  //Si es par:
  if ((n%2)==0)
  {
        printf("No se puede dibujar el triangulo\n\n");
       system("pause");
       return 0;
        }
        //Si es impar:
        else
        {
            
        for(fila=1;fila<=n;fila++)
        { 
/* Espacios en blanco*/ 
for(col=1;col<=n-fila;col++){ 
printf(" " ) ; 
} 
for(col=1;col<=2*fila-1;col++){ 
printf("*" ) ; 
} 
printf("\n" ) ; 
} 
} 
        
  getchar();
  system("pause");	
  return 0;
}
