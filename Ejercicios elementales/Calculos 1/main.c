#include <stdio.h>
/*
Realizar un programa que sume los primeros 5 números naturales y muestre el resultado por pantalla
 hacerlo usando un bucle 'for' y después usando un bucle 'while'.
*/
int main(int argc, char *argv[])
{
  int resultado=0,resultado2=0;
  int i;
  int a=1;
  char hola;
  for (i=1;i<6;i++)
  {
        resultado=resultado+i;
        printf("%d. Suma: %d \n\n",i,resultado);
    }      
    
    printf("-----------------------------------------------\n\n");
    do 
    { 
        resultado2=resultado2+a;
        printf("%d. Suma: %d \n\n",a,resultado2);
        a++;
        }
        while(a<6);
       
  getchar();	
  system("pause");
  return 0;

}
