#include <stdio.h>

/*
Hacer un programa que te pregunte la edad, y despu�s te salude con alguno de estos mensajes seg�n la edad:
*/
int main(int argc, char *argv[])
{
  int numero1,numero2,resultado;
  
  printf("Introduzca un numero: \n");
  scanf("%d",&numero1);
  printf("Introduzca otro numero: \n");
  scanf("%d",&numero2);
  
  resultado = numero1*numero2;
  
   printf("Resultado: %d \n",resultado);
   
  getchar();
  system("pause");	
  return 0;

}
