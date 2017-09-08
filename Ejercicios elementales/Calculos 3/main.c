#include <stdio.h>
/*

Hacer un programa que los sume todos y muestre el resultado en pantalla. 
Probar a modificar alguno de los valores del vector y/o a modificar su tamaño
añadiendo o quitando elementos) y repetir la ejecución del programa para ver otros resultados.

*/
int main(int argc, char *argv[])
{
//vector de 10 elementos
int vector[11]={2,6,12,76,33,59,83,6,131,65,0};
int resultado=0;
int i;
for(i=0;i<10;i++)
{
    
 resultado=resultado +vector[i];
 int suma=vector[i+1];    
 printf("%d. Suma: %d + %d\n\n",i,resultado,suma);
}

printf("Suma de los numeros del vector: %d",resultado);

  getchar();
  system("pause");	
  return 0;

}
