#include <stdio.h>
#include<math.h>

/*

Calcular las soluciones de la ecuación de segundo grado 'ax2 + bx + c = 0'. 
Recordad que la solución viene dada por la fórmula:

x=(-b+-(Raiz (b^2)-(4*A*C)))/2*A

Tened en cuenta que si el contenido de la raíz cuadrada (b2 - 4ac) es positivo, 
la ecuación tendrá dos soluciones, si es cero tendrá sólo una y si es negativo no tendrá solución.
El programa tendrá que diferenciar entre esas tres situaciones 
y en cada caso dar por pantalla una de estas tres salidas:

1) "Las soluciones de la ecuación son: valor_1 y valor_2"
2) "Hay una única solución: valor_1"
3) "No hay solución"


La función que calcula raíces cuadradas en C es 'sqrt()' 
y pertenece a la librería 'math.h' (#include<math.h>).

Ojo con los valores calculados en este ejercicio, los parámetros 'a', 'b' y 'c' son enteros, 
pero el resultado debe ser un valor real (double). Los cálculos intermedios 
y la solución final deberán guardarse el variables de tipo double.

*/
int main(int argc, char *argv[])
{
  int a,b,c;
  double valor_1,valor_2; 
  printf("Introduzca el valor de a: \n");
  scanf("%d",&a);
  printf("Introduzca el valor de b: \n");
  scanf("%d",&b);
  printf("Introduzca el valor de c: \n");
  scanf("%d",&c);
  
  
  if((b*b)-4*a*c<0)
  {
       printf("No hay solucion\n"); 
        }
        else if((b*b)-4*a*c==0)
        {
            valor_1= (b*(-1)+sqrt(b*b-4*a*c))/2*a;
            printf("Resultado de la ecuacion: %d\n",valor_1);
            }
            else
            {
                valor_1=(b*(-1)+sqrt(b*b-4*a*c))/2*a;
                 valor_2= (b*(-1)-sqrt(b*b-4*a*c))/2*a;
                printf("Resultado de la ecuacion: %d y %d\n",valor_1,valor_2);
                }
  getchar();
  system("pause");	
  return 0;

}
