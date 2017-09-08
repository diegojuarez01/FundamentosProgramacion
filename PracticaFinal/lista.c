#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista.h"
#define nombrefichero "citas.txt"

void ComprobarFichero(FILE* fichero,int contadoragregadas,int contador,int contadorborradas,LISTA *lista,char *nombreficherousuario,int comprobarfichero){
            //Si el programa arranca y no hay ningun fichero por defecto el prompt sera de la siguiente manera
          /*  if(comprobarfichero == 0){
            //Añadimos a la lista los datos del fichero.
            if(nombreficherousuario != NULL)
            printf("%s[%d/%d/%d][%d]:>_",nombreficherousuario,contadoragregadas,contador,contadorborradas,lista->longitud);
            fclose(fichero);    
                }*/
            if (fichero == NULL){
            printf("[NO FILE][%d/%d/%d][%d]:> ",contadoragregadas,contador,contadorborradas,lista->longitud);
            fclose(fichero);
            }
                else{
                     if(lista->longitud == 0){
                printf("[NO FILE][%d/%d/%d][%d]:> ",contadoragregadas,contador,contadorborradas,lista->longitud);
                }else{
            //Añadimos a la lista los datos del fichero.
            printf("%s[%d/%d/%d][%d]:>_",nombreficherousuario,contadoragregadas,contador,contadorborradas,lista->longitud);
        }
            fclose(fichero);
            }
            
}

void VaciarListaCargada(LISTA *lista){  
      NODO *auxiliar; 
      auxiliar = lista->primero;
        while (auxiliar!=NULL){
      //Si el nodo a borrar es el primero  
                    if(auxiliar == lista->primero){
                            //Para borrar el ultimo nodo de la lista.
                          if(lista->longitud == 1){
                                        lista->primero = NULL;
                                        lista->longitud --;
                                        } 
                                        else{                      
                        lista->primero = lista->primero->siguiente;
                        lista->primero->anterior = NULL;      
                        lista->longitud --;
                                            }
                               auxiliar = auxiliar->siguiente;          
                                        }   
                                    }                              
}

void LiberarMemoriaNodo(char *autor,char *cita,char *clave){
   free(autor);
   free(cita);
   free(clave);
}
  


void InicializarLista(LISTA *l){
l->primero = l->ultimo = l->iterador = NULL;
l->longitud = 0;
}

void ImprimirLista(LISTA *lista){
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = lista->primero;
      int contador=1; 
      if(auxiliar==NULL){
      printf( "\nError, la lista esta vacia\n" );  
      }else{
      printf("\nMostrando la lista completa de frases:\n\n");}
      while (auxiliar){
            printf("%i. %s A%co: %s Autor: %s\n",contador,auxiliar->frase,(char)(164),auxiliar->ano,auxiliar->autor);      
            auxiliar = auxiliar->siguiente; 
            contador++;  
      } 
      printf("\n");
}

int ImprimirFrasesAutor(LISTA *lista,char *autor){
    int contador=0;
    NODO *auxiliar; /* lo usamos para recorrer la lista */
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
   while (auxiliar!=NULL){
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        //Se sumara en 1 el numero de frases de ese autor y se imprimira su valor.                
        if (strcmp(auxiliar->autor,autor) == 0){        
            if(contador == 0){
                 printf("\nFrases de %s:\n\n",autor);
                 }
            contador++;
            printf("%i. %s\n",contador,auxiliar->frase);     
            auxiliar = auxiliar->siguiente;
           }else{   
             auxiliar = auxiliar->siguiente;
                }   
                        }   
    printf("\n");    
    return contador;  
}

int LlenarClaves(LISTA *lista,CLAVE vecClaves[]){
    
    char *token[1000];
    char *ptr;      
    int j=0,a=0;   
    NODO *auxiliar; /* lo usamos para recorrer la lista */
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
    int repetido = 0;
    vecClaves[0].clave == NULL;
    char *Conjuntoclaves;
   while (auxiliar!=NULL){
    Conjuntoclaves = (char *) malloc (1000*sizeof(char));
    strcpy(Conjuntoclaves,auxiliar->claves);
//Recorremos todos los nodos y vamos hacemos lo de los tokens[] para sacar las claves de cada nodo y los introducimos en vecClaves[j] j++ cade vez que se introduzca una clave.
    int i,b,tam=0,numeroconfirmado=0;
    for(b=0; b < 50; b++){
        token[b] = 0;
    }     
    ptr = strtok(auxiliar->claves,",");
    token[0]= ptr;
    i=1;
    while(ptr != NULL){
        ptr = strtok(NULL, ",");
        token[i]=ptr;
        i=i+1;
        tam++;
     }
    for(j=0;j<tam;j++){
        repetido = 0;
            for(i=0;i<a;i++){
                if(strcmp(vecClaves[i].clave,token[j]) == 0){
                vecClaves[i].num += 1; 
                repetido = 1;       
                 }
                 else{                 
                    }
                }
      if(repetido == 1){     
            }
      else{          
      vecClaves[a].clave = token[j];
      vecClaves[a].num = 1;
      a++; 
        }
    }   
     auxiliar->claves = Conjuntoclaves;
     auxiliar = auxiliar->siguiente;   
        }     
    return a;
}

//Crear un fichero con las frases del autor introducido y con el nombrefichero introducido.
void ExportarFichero (LISTA *lista,char *autor,char *nombreficherousuario){  
            FILE *fichero;
            fichero = fopen(nombreficherousuario, "w+"); 
            int contador=0;
            NODO *auxiliar; /* lo usamos para recorrer la lista */
            auxiliar = (NODO *) malloc (sizeof(NODO*)); 
            auxiliar = lista->primero;
            while (auxiliar!=NULL){
            //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
            //Se sumara en 1 el numero de frases de ese autor y se imprimira su valor.                
            if (strcmp(auxiliar->autor,autor) == 0){  
             if(contador == 0){                       
                fputs (auxiliar->frase, fichero);
                fputs ("\nTemas: ",fichero);
                fputs (auxiliar->claves, fichero);
                fputs ("\nAño: ",fichero);
                fputs (auxiliar->ano, fichero);    
                }
                else{  
                fputs ("\n", fichero);
                fputs (auxiliar->frase, fichero);          
                fputs ("\nTemas: ",fichero); 
                fputs (auxiliar->claves, fichero);
                fputs ("\nAño: ",fichero);
                fputs (auxiliar->ano, fichero);   
                        }               
            auxiliar = auxiliar->siguiente;
            contador++;
             }else{   
             auxiliar = auxiliar->siguiente;
                }   
                    } 
            fclose(fichero);  
}

void ExportarFicheroClaves (LISTA *lista,char *claves,char *nombreficherousuario){  
            FILE *fichero;
            fichero = fopen(nombreficherousuario, "w+"); 
            int contador=0;
          char *token[1000];
    char *ptr;
    char cadena[1000];
            char *Conjuntoclaves;
            Conjuntoclaves = (char *) malloc (1000*sizeof(char*)); 
            NODO *auxiliar; /* lo usamos para recorrer la lista */
            auxiliar = (NODO *) malloc (sizeof(NODO*)); 
            auxiliar = lista->primero;
            while (auxiliar!=NULL){
                          strcpy(Conjuntoclaves,auxiliar->claves);
                                    //Limpia la cadena de la anterior ejecucion
                                    memset(cadena, 0, 1000); 
                                    int i,b,tam=0,numeroconfirmado=0;
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(Conjuntoclaves,",\0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, ",\0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     }                                                  
                                             for (i=0;i<tam;i++){
                                               if(strcmp(token[i],claves) == 0){
                                                    if(contador == 0){                       
                                                    fputs (auxiliar->frase, fichero);
                                                    fputs ("\nAutor: ",fichero);
                                                    fputs (auxiliar->autor, fichero);
                                                    fputs ("\nTemas: ",fichero);
                                                    fputs (auxiliar->claves, fichero);
                                                    fputs ("\nAño: ",fichero);
                                                    fputs (auxiliar->ano, fichero);    
                                                    }
                                                    else{
                                                    fputs ("\n", fichero);    
                                                    fputs (auxiliar->frase, fichero);
                                                    fputs ("\nAutor: ",fichero);
                                                    fputs (auxiliar->autor, fichero);
                                                    fputs ("\nTemas: ",fichero);
                                                    fputs (auxiliar->claves, fichero);
                                                    fputs ("\nAño: ",fichero);
                                                    fputs (auxiliar->ano, fichero);  
                                                    }               
                                                   contador++;
                                                    }
                                                } 
                                                auxiliar = auxiliar->siguiente;
                                                

                    } 
                    if(contador == 0){
                        printf("\nNo existe esa clave en ninguna de las frases\n");
                        }
            fclose(fichero);  
}

//Funcion para insertar nodos en la lista pasandole frase autor y clave.
void insertarNodo(char *frase,char *autor,char *clave,char *ano,LISTA *lista){                            
                          NODO *nuevo;   
                          nuevo = (NODO*)malloc(sizeof(NODO));    
                          nuevo->frase = frase; 
                          nuevo->autor = autor;   
                          nuevo->claves = clave; 
                          nuevo->ano = ano;               
                     //Primer nodo  
                      if(lista->primero==NULL){    
                          lista->primero = nuevo;
                          lista->primero->siguiente = NULL;    
                          lista->primero->anterior = NULL;       
                          lista->ultimo = lista->primero;
                          lista->longitud += 1;	
                      }
                      //Todos los demas
                      else{    
                          lista->ultimo->siguiente = nuevo;
                          nuevo->siguiente = NULL;
                          nuevo->anterior = NULL;
                          lista->ultimo = nuevo;
                          lista->longitud += 1;	           
                      }                  
}

int anadirnodosaotralista(LISTA *lista, LISTA *listaauxiliar,int contador)
{
      NODO *nuevo; /* lo usamos para recorrer la lista */
      nuevo = (NODO *) malloc (sizeof(NODO*)); 
      nuevo = listaauxiliar->primero;

      while (nuevo!=NULL){
            lista->ultimo->siguiente = nuevo;
            lista->ultimo = nuevo;
            lista->longitud += 1;    	
            nuevo = nuevo->siguiente; 
            contador++;  
      } 
    return contador;
}

int AnadirNodoLista(LISTA *lista,FILE *fichero)
 {
      
char *cargarfrase,*frase;
char *cargarautor,*autor;
char *cargarclave,*clave;
char *cargarano,*ano;
int posicion,a,i,comprobarfichero = 3;

//Para reservar memoria exacto debo saber tamaño de la lineas.
 cargarautor = (char *) malloc (1000*sizeof(char));     
 cargarfrase = (char *) malloc (1000*sizeof(char)); 
 cargarclave = (char *) malloc (1000*sizeof(char)); 
 cargarano = (char *) malloc (1000*sizeof(char)); 
 frase = (char *) malloc (1000*sizeof(char)); 
 autor = (char *) malloc (1000*sizeof(char)); 
 clave = (char *) malloc (1000*sizeof(char)); 
 ano = (char *) malloc (1000*sizeof(char)); 

//Carga linea por linea fichero evitando espacios en blanco, saltos de linea y tabulaciones.
do{
//Si cargarfrase no empieza por frase: ni cargarautor por autor: ni cargarclave por clave dara error y no cargara. 
if (feof(fichero) != 0){
    break;
    }else{
        fgets(cargarfrase, 1000, fichero);
        } 
    }
while(cargarfrase[0] == ' ' || cargarfrase[0] == '\n' || cargarfrase[0] == '\t');
                                        //fscanf(fichero,"%[^\n]%*[\n]",cargarfrase);
do{
    fgets(cargarautor, 1000, fichero);
        }
while(cargarautor[0] == ' ' || cargarautor[0] == '\n' || cargarautor[0] == '\t'  );
do{
    fgets(cargarclave, 1000, fichero); 
        }
while(cargarclave[0] == ' ' || cargarclave[0] == '\n' || cargarclave[0] == '\t'  );                                        
do{
    fgets(cargarano, 1000, fichero); 
        }
while(cargarano[0] == ' ' || cargarano[0] == '\n' || cargarano[0] == '\t'  );                                        

//Si la ultima linea tiene un salto de linea se ignorara y se finalizara el metodo
if(cargarfrase[0] == ' ' || cargarfrase[0] == '\n' || cargarfrase[0] == '\t')
{
return ;
}
    
//Ignora los saltos de lineas finales.
cargarfrase[strlen(cargarfrase) - 1] = '\0';  
cargarautor[strlen(cargarautor) - 1] = '\0';  
cargarclave[strlen(cargarclave) - 1] = '\0';
//Para evitar perder el ultimo digito en la ultima frase.
if(cargarano[strlen(cargarano) - 1] == '\n'){  
cargarano[strlen(cargarano) - 1] = '\0';
}

posicion = strlen(cargarfrase);

if(cargarfrase[0] == 'F'  && cargarfrase[1]== 'R' && cargarfrase[2] == 'A' && cargarfrase[3] == 'S' && cargarfrase[4] == 'E' && cargarfrase[5] == ':' && cargarfrase[6] == ' ')
{
   // copiar la primera parte
	for(a = 0; a < posicion-1; a++ ){
		frase[a]=cargarfrase[a]  ;
    }
    
	// copiar la segunda parte
	for(a=0; a < posicion-1; a++ ){
		frase[a] = cargarfrase[a+7] ; // 7 es el tamaño de la parte
    }
    for (i=strlen(frase)-1;frase[i] == ' ' || frase[i] == '\t' ; i-- ){
    frase[i] = '\0';
    }
}
else{
      printf("\nError formato invalido de fichero\n\n");  
     comprobarfichero = 0;
   return comprobarfichero;       
}
if(cargarautor[0] == 'A' && cargarautor[1]== 'U' && cargarautor[2] == 'T' && cargarautor[3] == 'O' && cargarautor[4] == 'R' && cargarautor[5] == ':' && cargarautor[6] == ' '){    

posicion = strlen(cargarautor);

   // copiar la primera parte
	for(a = 0; a < posicion; a++ ){
		autor[a]=cargarautor[a]  ;
    }
    
	// copiar la segunda parte
	for(a=0; a < posicion; a++ ){
		autor[a] = cargarautor[a+7] ; // 7 es el tamaño de la parte
    }
    for (i=strlen(autor)-1;autor[i] == ' ' || autor[i] == '\t' ; i-- ){
    autor[i] = '\0';
    }
}
else{
    printf("\nError formato invalido de fichero\n\n");  
    comprobarfichero = 0;
     return comprobarfichero;   
 
}
if(cargarclave[0] == 'C' && cargarclave[1] == 'L' && cargarclave[2] == 'A' && cargarclave[3] == 'V' && cargarclave[4] == 'E' && cargarclave[5] == 'S' && cargarclave[6] == ':' && cargarclave[7] == ' '){ 
posicion = strlen(cargarclave);
   // copiar la primera parte
	for(a = 0; a < posicion; a++ ){
		clave[a]=cargarclave[a]  ;
    }
    
	// copiar la segunda parte
	for(a=0; a < posicion; a++ ){
		clave[a] = cargarclave[a+8] ; // 8 es el tamaño de la parte
    }
      for (i=strlen(clave)-1;clave[i] == ' ' || clave[i] == '\t' ; i-- ){
    clave[i] = '\0';
    }
}
else{
      printf("\nError formato invalido de fichero\n\n");  
    comprobarfichero = 0;
     return comprobarfichero;   
   
}
if(cargarano[0] == 'A' && cargarano[1] == 'Ñ' && cargarano[2] == 'O' && cargarano[3] == ':' && cargarano[4] == ' '){ 
posicion = strlen(cargarano);
   // copiar la primera parte
	for(a = 0; a < posicion; a++ ){
		ano[a]=cargarano[a]  ;
    }
    
	// copiar la segunda parte
	for(a=0; a < posicion; a++ ){
		ano[a] = cargarano[a+5] ; // 8 es el tamaño de la parte
    } 
  for (i=strlen(ano)-1;ano[i] == ' ' || ano[i] == '\t' ; i-- ){
    ano[i] = '\0';
    }
} 
else{
 printf("\nError formato invalido de fichero\n\n");  
    comprobarfichero = 0;
    return comprobarfichero;   

}
//Inserta el nodo en la lista con los datos obtenidos del fichero.
insertarNodo(frase,autor,clave,ano,lista);  
  return comprobarfichero;   
} 

int ContarFrasesDelMismoAutor(LISTA *lista,char *autor){
    
    int contador=0;
    NODO *auxiliar; /* lo usamos para recorrer la lista */
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
    while (auxiliar!=NULL){
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        //Se sumara en 1 el numero de frases de ese autor.                
        if (strcmp(auxiliar->autor,autor) == 0){        
            contador++;
            auxiliar = auxiliar->siguiente;
        } 
        else{   
           auxiliar = auxiliar->siguiente;
           }   
    }       
    return contador;
}

void limpiar(LISTA *lista,char *reiniciarnombreficherousuario){
    
    int contadoragregadas,contador,contadorborradas;
    int comprobarfichero =1;
    FILE* fichero = NULL;
            NODO *auxiliar; /* lo usamos para recorrer la lista */
            while (lista->primero!=NULL){
            auxiliar = lista->primero;
            lista->primero = lista->primero->siguiente;
            free(auxiliar);
        }
        reiniciarnombreficherousuario == "[NO FILE]";
        lista->longitud = 0;
        contadoragregadas = 0;
        contador = 0;
        contadorborradas = 0;
       
    }

void MostrarCita(LISTA *lista,char *autor,int numero){
    
    int contador=1;
    NODO *auxiliar; /* lo usamos para recorrer la lista */
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
    while (auxiliar!=NULL){
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        if(numero == contador){   
        //Se sumara en 1 el numero de frases de ese autor.
        if (strcmp(auxiliar->autor,autor) == 0){        
            printf("\nLa frase seleccionada es la siguiente: ' %s '\n",auxiliar->frase);
            break;
        } 
        else{ 
            auxiliar = auxiliar->siguiente;
           } 
                               }
        else{
        if (strcmp(auxiliar->autor,autor) == 0){       
        contador++;
        auxiliar = auxiliar->siguiente;
                        } 
        else{
        auxiliar = auxiliar->siguiente;
                } 
            }   
    }       
}
void MostrarCitaClaves(LISTA *lista,char *autor,int numero){
    
    int contador=1;
    NODO *auxiliar; /* lo usamos para recorrer la lista */
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
    while (auxiliar!=NULL){
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        if(numero == contador){   
        //Se sumara en 1 el numero de frases de ese autor.
        if (strcmp(auxiliar->autor,autor) == 0){        
            printf("\nLa frase seleccionada es la siguiente: ' %s '\n",auxiliar->frase);
            //Si clave esta vacia se indicara que el conjunto esta vacio.
            if(strcmp(auxiliar->claves,"\0") == 0){
                printf("\nEl conjunto de claves para esta frase esta vacio.\n\n");
                }
                else{
                printf("\nConjunto de claves: %s \n\n",auxiliar->claves);
              }
            break;
        } 
        else{ 
            auxiliar = auxiliar->siguiente;
           } 
                               }
        else{
        if (strcmp(auxiliar->autor,autor) == 0){       
        contador++;
        auxiliar = auxiliar->siguiente;
        } 
        else{
        auxiliar = auxiliar->siguiente;
                } 
            }   
    }       
}

//Funcion para borrar una frase de un autor.
void BorrarFrase(LISTA *lista, char *Autor,int numero){
      int frasesautor,contador=1;
      //Numero de frases del mismo autor.
      frasesautor = ContarFrasesDelMismoAutor(lista,Autor);
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      NODO *anterior;
      anterior = (NODO*) malloc (sizeof(NODO*));
      anterior == NULL;    
      auxiliar = lista->primero;
        while (auxiliar!=NULL){
//Si ademas numero introducido es  == contador de frases de autor borrariamos ese nodo de la lista, sino pasamos al siguiente nodo de ese autor.     
        if(numero == contador){        
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        //Se sumara en 1 el numero de frases de ese autor.          
        if(strcmp(auxiliar->autor,Autor) == 0){   
                    //Si el nodo a borrar es el primero  
                    if(auxiliar == lista->primero){
                            //Para borrar el ultimo nodo de la lista.
                          if(lista->longitud == 1){
                                        lista->primero = NULL;
                                        lista->longitud --;
                                        } 
                                        else{                      
                        lista->primero = lista->primero->siguiente;
                        lista->primero->anterior = NULL;      
                        lista->longitud --;
                                            }           
                        break;
                    }
                    //Si el nodo a borrar es el ultimo
                    else if(auxiliar == lista->ultimo){
                              anterior->siguiente = NULL;
                              lista->ultimo = anterior;
                              lista->longitud --;    
                              break;
                        }
                        //Si el nodo a borrar no es primero ni ultimo.
                        else{ 
                                anterior->siguiente = auxiliar->siguiente;
                                auxiliar->siguiente->anterior = anterior;
                                lista->longitud --;
                                break;
                        }        
                             }           
                else{
                    anterior = auxiliar;
                    auxiliar = auxiliar->siguiente;
                    }  
                                    } 
            else{                  
                        if(strcmp(auxiliar->autor,Autor) == 0) {    
                            contador++;
                            anterior = auxiliar;
                            auxiliar = auxiliar->siguiente;
                        } 
                        else{
                         anterior = auxiliar;
                         auxiliar = auxiliar->siguiente;
                        }   
                    } 
                }            
}

//MostraraFrases que contengan ese texto.
void MostrarFrasesConTexto(char *cadena,LISTA *lista)
{
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      auxiliar = lista->primero;    
      char *token[1000];
      char *ptr;  
      char *ConjuntoFrases;
      ConjuntoFrases = (char*) malloc (1000*sizeof(char)); 
      char *ConjuntoCadena;
      ConjuntoCadena = (char*) malloc (1000*sizeof(char)); 
      char *tokencadena[1000]; 
                 while (auxiliar!=NULL){ 
                                    strcpy(ConjuntoFrases,auxiliar->frase);
                                    int i,b,tam=0,tamcadena=0,numeroconfirmado=0;
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoFrases," .,\0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, " .,\0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     }        
                                    strcpy(ConjuntoCadena,cadena);
                                    for(b=0; b < 50; b++){
                                        tokencadena[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoCadena," \0");
                                    tokencadena[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, " \0");
                                        tokencadena[i]=ptr;
                                        i=i+1;
                                        tamcadena++;
                                     } 
                                if(tamcadena == 1){            
             for(i=0;i<tam;i++){                     
        if (strcmp(token[i],cadena) == 0){
            printf("Frase: %s\n\n",auxiliar->frase);  
            break;
                    }
            }
        }   
        else{
            if(strstr(auxiliar->frase,cadena) != NULL)
            {
                printf("Frase: %s\n\n",auxiliar->frase);
                }
            }
            auxiliar =  auxiliar->siguiente;
        }    
}

//MostraraFrases que contengan ese texto.
void MostrarAutorConTexto(char *cadena,LISTA *lista)
{
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      auxiliar = lista->primero;    
      char *token[1000];
      char *ptr;
      char *tokencadena[1000];  
      char *ConjuntoAutor;
      ConjuntoAutor = (char*) malloc (1000*sizeof(char)); 
      char *ConjuntoCadena;
      ConjuntoCadena = (char*) malloc (1000*sizeof(char)); 
      
                 while (auxiliar!=NULL){ 
                                    strcpy(ConjuntoAutor,auxiliar->autor);
                                  
                                    int i,b,tam=0,tamcadena=0,numeroconfirmado=0;
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoAutor," \0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, " \0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     } 
                                    strcpy(ConjuntoCadena,cadena);
                                    
                                    for(b=0; b < 50; b++){
                                        tokencadena[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoCadena," \0");
                                    tokencadena[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, " \0");
                                        tokencadena[i]=ptr;
                                        i=i+1;
                                        tamcadena++;
                                     }  
              if(tamcadena==1){                                    
             for(i=0;i<tam;i++){                     
        if (strcmp(token[i],cadena) == 0){
            printf("Frase: %s\n\n",auxiliar->frase);  
            break;
                    }
            }
        }  
        else{
            if(strstr(auxiliar->autor,cadena) != NULL)
            {
                printf("Frase: %s\n\n",auxiliar->frase);
                }
            }
            auxiliar =  auxiliar->siguiente; 
    } 
}

//MostraraFrases que contengan ese texto.
void MostrarClavesConTexto(char *cadena,LISTA *lista)
{
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      auxiliar = lista->primero;    
      char *token[1000];
      char *ptr;
      char *tokencadena[1000];  
      char *ConjuntoClaves;
      ConjuntoClaves = (char*) malloc (1000*sizeof(char)); 
      char *ConjuntoCadena;
      ConjuntoCadena = (char*) malloc (1000*sizeof(char)); 
      
                 while (auxiliar!=NULL){ 
                                    strcpy(ConjuntoClaves,auxiliar->claves);
                                  
                                    int i,b,tam=0,tamcadena=0,numeroconfirmado=0;
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoClaves,",\0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, ",\0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     } 
                                    strcpy(ConjuntoCadena,cadena);
                                    
                                    for(b=0; b < 50; b++){
                                        tokencadena[b] = 0;
                                    }     
                                    ptr = strtok(ConjuntoCadena," \0");
                                    tokencadena[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, " \0");
                                        tokencadena[i]=ptr;
                                        i=i+1;
                                        tamcadena++;
                                     }  
                                             
             for(i=0;i<tam;i++){                     
        if (strcmp(token[i],cadena) == 0){
            printf("Frase: %s\n\n",auxiliar->frase);  
            break;
                    }
            }
        
        
            auxiliar =  auxiliar->siguiente; 
    } 
}

       
//Funcion para modificar una frase de un autor.
int ModificarFrase(LISTA *lista,int contadormod, char *Autor,int numero,char *frase,char *ano,char *autorcambiado){
      int contador=1;
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      auxiliar = lista->primero;          
      while (auxiliar!=NULL){
//Si ademas numero introducido es  == contador de frases de autor borrariamos ese nodo de la lista, sino pasamos al siguiente nodo de ese autor.     
             if(numero == contador){        
        //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        //Se sumara en 1 el numero de frases de ese autor.
          if (strcmp(auxiliar->autor,Autor) == 0){       
                    if(strcmp(frase,"\0") == 0){            
                        }else{
                    contadormod++;        
                    auxiliar->frase=frase;}
                    if(strcmp(autorcambiado,"\0") == 0){
                        }else{
                            contadormod++;
                    auxiliar->autor=autorcambiado;
                    }
                    if(strcmp(ano,"\0") == 0){ 
                    }else{    
                    contadormod++;
                    auxiliar->ano=ano;
                    }
                    break;
                }           
                else{
                    auxiliar = auxiliar->siguiente;
                    }  
                        } 
            else{
                      if (strcmp(auxiliar->autor,Autor) == 0){       
                        contador++;
                        auxiliar = auxiliar->siguiente;
                        } 
                        else{
                    auxiliar = auxiliar->siguiente;
                        }   
                    } 
                        }  
                        return contadormod;
}

int AnadirClave(LISTA *lista,char *Autor,int numero, char *clave,int cambio){      
 
      int contador=1;
      char *Conjuntoclaves;
      Conjuntoclaves = (char *) malloc (1000*sizeof(char*)); 
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = (NODO *) malloc (sizeof(NODO*)); 
      auxiliar = lista->primero;
      char *separador = ",";
      char *token[1000];
      char *ptr;
      int duplicadas = 1;
      int i,b,tam=0,numeroconfirmado=0;
      while (auxiliar!=NULL){
             if(numero == contador){          
    //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
        //Se sumara en 1 el numero de frases de ese autor.
        if (strcmp(auxiliar->autor,Autor) == 0){         
                  strcpy(Conjuntoclaves,auxiliar->claves);            
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(auxiliar->claves,",\0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                       ptr = strtok(NULL, ",\0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     }                          
                    //Hacer tokens que recorra cada clave, si una es igual a "clave" estan duplicadas.                      
                        for (i=0;i<tam;i++){
                            if (strcmp(token[i],clave) == 0){
                                 duplicadas = 0;
                                 auxiliar->claves = Conjuntoclaves;  
                                 printf("\nLa clave ya estaba, introduzca otra clave para esa frase\n\n");
                                 return cambio;
                                 break;                      
                                }
                             }                                 
                      if (duplicadas == 1){
                    //Si CLAVES esta vacio, le añadiremos solamente sino lo uniremos a lo que tenia separando con ","       
                                 if(strcmp(auxiliar->claves,"\0") == 0){                                           
                                strcat (auxiliar->claves,clave);                                             
                                 }       
                                  else{         
                                    strcat (Conjuntoclaves,","); 
                                    strcat (Conjuntoclaves,clave);    
                     auxiliar->claves = Conjuntoclaves;  
                                }
                    cambio++;
                    break;
                        } 
            }
                else{
                    auxiliar = auxiliar->siguiente;
                    }  
                        } 
                   else{
                   if (strcmp(auxiliar->autor,Autor) == 0){       
                        contador++;
                        auxiliar = auxiliar->siguiente;
                        } 
                        else{
                    auxiliar = auxiliar->siguiente;
                        }   
                    }  
                }     
                return cambio;        
    }
    
int BorrarClave(LISTA *lista,char *Autor,int numero, char *clave,int contadorborradas){
    
    char *token[1000];
    char *ptr;
    char cadena[1000];
    int contador=1,a,j;
    NODO *auxiliar; // lo usamos para recorrer la lista 
    auxiliar = (NODO *) malloc (sizeof(NODO*)); 
    auxiliar = lista->primero;
    char *Conjuntoclaves;
    Conjuntoclaves = (char*) malloc (1000*sizeof(char));
    char *ClavesRepetidas;
    ClavesRepetidas = (char*) malloc (1000*sizeof(char));
    int claves = 0;
                        
      while (auxiliar!=NULL){
             if(numero == contador){          
            //Si autor y el contenido del nodo auxiliar del autor en ese momento son iguales
                //Se sumara en 1 el numero de frases de ese autor.
                if (strcmp(auxiliar->autor,Autor) == 0){
                    
                                    strcpy(Conjuntoclaves,auxiliar->claves);
                                    strcpy(ClavesRepetidas,Conjuntoclaves);
                                    //Limpia la cadena de la anterior ejecucion
                                    memset(cadena, 0, 1000); 
                                    int i,b,tam=0,numeroconfirmado=0;
                                    for(b=0; b < 50; b++){
                                        token[b] = 0;
                                    }     
                                    ptr = strtok(Conjuntoclaves,",\0");
                                    token[0]= ptr;
                                    i=1;
                                    while(ptr != NULL){
                                        ptr = strtok(NULL, ",\0");
                                        token[i]=ptr;
                                        i=i+1;
                                        tam++;
                                     }  
                                                                                     
                                             for (i=0;i<tam;i++){
                                               if(strcmp(token[i],clave) == 0){ 
                                                       for (j=0;j<tam;j++){
                                                        //Cuando hay que borrar la primera                                          
                                                            if(i==0){
                                                              for (j=0;j<tam;j++){ 
                                                            if(j+1==tam){                                       
                                                             }else if (j<tam-2){
                                                             strcat (cadena,token[j+1]);                        
                                                             strcat (cadena,",");  
                                                                }else{
                                                                strcat (cadena,token[j+1]); 
                                                                    }                                                                               
                                                            } 
                                                                auxiliar->claves = cadena;
                                                                break;
                                                                return contadorborradas;   
                                                            }   
                                                                //No se borra nada. 
                                                           else if(i==j){                        
                                                                }else{
                                                                   //Cuando se borra el ultimo token[i] es donde se encuentra la clave a borrar     
                                                                        if(i==tam-1){
                                                                             for(j=0;j<tam-1;j++){
                                                                                    //La ultima clave se añadira sin separador.
                                                                                    if(j==tam-2){
                                                                             strcat (cadena,token[j]);
                                                                             }else{
                                                                             strcat (cadena,token[j]);
                                                                             strcat (cadena,",");
                                                                             }
                                                                             auxiliar->claves = cadena; 
                                                                                                  }          
                                                                             }
                                                                        //Cuando hay que borrar cualquiera que no sea la primera o la ultima              
                                                                       else{                                                      
                                                                          if(j<tam-1){
                                                                              strcat (cadena,token[j]);
                                                                              strcat (cadena,",");       
                                                                            } else{
                                                                                strcat (cadena,token[j]);
                                                                        }
                                                                         auxiliar->claves = cadena;                                                            
                                                                              } 
                                                                          } 
                                                                     }              
                                                                  }
                                                                  else{
                                                                        claves++;
                                                                         if(claves == tam ){
                                                                         printf("\nClave introducida a borrar incorrecta.\n\n");
                                                                         auxiliar->claves = ClavesRepetidas;                                                                
                                                                         return contadorborradas;
                                                                         break;
                                                                        }                                  
                                                                    }
                                                              }
                                                            printf("\nClave borrada con exito.\n\n");  
                                                            contadorborradas++;
                                                            printf("Auxiliarclaves: ",auxiliar->claves);
                                                            return contadorborradas;
                                                            break;
                                                        }
                                                    
                else{
                    auxiliar = auxiliar->siguiente;
                    }  
                        } 
                   else{
                   if (strcmp(auxiliar->autor,Autor) == 0){       
                        contador++;
                        auxiliar = auxiliar->siguiente;
                        } 
                        else{
                    auxiliar = auxiliar->siguiente;
                        }   
                    }  
                } 
                 return contadorborradas;           
    }

void CrearFicheroDefecto(LISTA *lista,FILE *fichero){
      NODO *auxiliar; /* lo usamos para recorrer la lista */
      auxiliar = lista->primero;
      auxiliar = (NODO *) malloc (sizeof(NODO)); 
      if(auxiliar==NULL){
      printf( "\nLa lista esta vacia!!\n\n" );
      }
       if(auxiliar = lista->primero){
                fputs ("FRASE: ", fichero);
                fputs (auxiliar->frase, fichero);
                fputs ("\nAUTOR: ", fichero);
                fputs (auxiliar->autor, fichero);
                fputs ("\nCLAVES: ",fichero);
                fputs (auxiliar->claves, fichero);
                fputs ("\nAÑO: ",fichero);
                fputs (auxiliar->ano, fichero);
                auxiliar = auxiliar->siguiente;      
        }
      while (auxiliar){
                fputs ("\nFRASE: ", fichero);
                fputs (auxiliar->frase, fichero);
                fputs ("\nAUTOR: ", fichero);
                fputs (auxiliar->autor, fichero);
                fputs ("\nCLAVES: ",fichero); 
                fputs (auxiliar->claves, fichero);
                fputs ("\nAÑO: ",fichero);
                fputs (auxiliar->ano, fichero);
                auxiliar = auxiliar->siguiente;    
                }    
             
}
    
//Pasamos toda la cadena a mayuscula.
void MinusculasMayuscula(char *cadena){
	int i=0;
	int desp='a'-'A';
	for (i=0; cadena[i]!='\0'; i++){
		if(cadena[i] >= 'a' && cadena[i] <= 'z'){
			cadena[i] = cadena[i] - desp;
		}
	}
}

//Pasamos toda la cadena a minuscula menos la primera letra.
void MayusculasMinuscula(char *cadena){
	int i=0;
	int desp = 'a'-'A';
	for (i=1; cadena[i]!='\0'; i++){
		if(cadena[i] >= 'A' && cadena[i] <= 'Z'){
			cadena[i] = cadena[i] + desp;
		}
	}
}    

void OrdenarLista(LISTA *lista){
    //Primero ordenamos por autores.
    NODO *A;
    NODO *auxiliar;
    char *aux;
    A = (NODO*) malloc (sizeof(NODO));
    A = lista->primero;
    auxiliar = (NODO*) malloc (sizeof(NODO));
    auxiliar = lista->primero->siguiente;
    aux = (char*) malloc (sizeof(char));        
      //Primero ordenamos por autor.
     //Mientras primero sea distinto de null.   
        while(auxiliar != NULL){
    //Mientras el auxiliar distinto de null
    while(auxiliar != NULL){    
        MinusculasMayuscula(A->autor);
          MinusculasMayuscula(auxiliar->autor);
       if(strcmp(A->autor,auxiliar->autor)>0){
            aux = A->autor;
            A->autor = auxiliar->autor;
            auxiliar->autor = aux;
            aux = A->frase;
            A->frase = auxiliar->frase;
            auxiliar->frase = aux;
            aux = A->claves;
            A->claves = auxiliar->claves;
            auxiliar->claves = aux;
            aux = A->ano;
            A->ano = auxiliar->ano;
            auxiliar->ano = aux;  
            }
            else if (strcmp(A->autor,auxiliar->autor) == 0){
                 MinusculasMayuscula(A->frase);
                    MinusculasMayuscula(auxiliar->frase);
                    if(strcmp(A->frase,auxiliar->frase)>0){
                        aux = A->autor;
                        A->autor = auxiliar->autor;
                        auxiliar->autor = aux;
                        aux = A->frase;
                        A->frase = auxiliar->frase;
                        auxiliar->frase = aux;
                        aux = A->claves;
                        A->claves = auxiliar->claves;
                        auxiliar->claves = aux;
                        aux = A->ano;
                        A->ano = auxiliar->ano;
                        auxiliar->ano = aux;
                         }
                        MayusculasMinuscula(A->frase);
           MayusculasMinuscula (auxiliar->frase); 
                }
            MayusculasMinuscula(A->autor);
           MayusculasMinuscula (auxiliar->autor);               
           auxiliar = auxiliar->siguiente;
                            }
                            A = A->siguiente;
                          auxiliar = A->siguiente;
                    }       
    } 
    
void OrdenarClaves(CLAVE vecClaves[],int numeroclaves){
    
    char *aux;
    int auxnum;
    int i,j;
     //Pasamos todas las cadenas a mayusculas
     for(i=0;i<numeroclaves;i++){
     MinusculasMayuscula(vecClaves[i].clave);
     }
    //Recorremos el vector para cada posicion comparando si es mayor se ordena.   
     for(i=0;i<numeroclaves;i++){
        for(j=0;j<numeroclaves;j++){
      if(strcmp(vecClaves[i].clave,vecClaves[j].clave)<0)
      {
            aux = vecClaves[i].clave;
            vecClaves[i].clave = vecClaves[j].clave;
            vecClaves[j].clave = aux;
            auxnum = vecClaves[i].num;
            vecClaves[i].num = vecClaves[j].num;
            vecClaves[j].num = auxnum;     
        }
            }
}    
  //Volvemos a pasar las cadenas a minuscula
    for(i=0;i<numeroclaves;i++){
     MayusculasMinuscula(vecClaves[i].clave);   
     }  

}
    
         
