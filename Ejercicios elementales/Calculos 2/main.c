#include <stdio.h>

/*

Repetir el ejercicio anterior ampliándolo de forma que sea el usuario el que determine 
cuántos números hay que sumar introduciendo el dato por teclado.

*/
int main(int argc, char *argv[])
{
  
  int resultado=0;
  int i;
  int n;
  printf("Introduzca cuantos numeros quiere sumar consecutivamente: ");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
        resultado=resultado+i;
        printf("%d. Suma: %d \n\n",i,resultado);
    }     
  getchar();	
  system("pause");
  return 0;

}
