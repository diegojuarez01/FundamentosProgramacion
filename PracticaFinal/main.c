#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#include "lista.h"
#include "utilidades.c"
#define nombrefichero "citas.txt"
#define N 1000


int main(int argc, char *argv[])
{ 
    char cadena[N],citasmemoria[N],s1[N],contadorstring[N],anomemoria[N],autormemoria[N];
    FILE* fichero = NULL;
    char *confirmar;
    confirmar = (char*) malloc (sizeof(char));
    char *autor,*clave,*cita,*ano;
    //Inicializado a 0 para indicar que no se a modificado el archivo citas.txt aun.
    int contadorborradas=0,contadoragregadas=0,contador=0;
    int cambio=0,longitud,i=0,j=0,contadordefrases;
    LISTA *lista;
    lista = (LISTA *) malloc (sizeof(LISTA));
    int comprobarfichero = 1;
    int *cadenanumerica;
    cadenanumerica = (int*) malloc(sizeof(int*)); 
    int *cadenanumerica2;
    cadenanumerica2 = (int*) malloc(sizeof(int));         
    char *nombreficherousuario;
    nombreficherousuario = (char*) malloc (sizeof(char));
    char *reiniciarnombreficherousuario;
    reiniciarnombreficherousuario = (char*) malloc (sizeof(char));
    datospersonales();
    InicializarLista(lista);
    CLAVE vecClaves[N];
    
    do{ 
        
            if(fichero==NULL){
                if (nombreficherousuario != ""){
                   ComprobarFichero(fichero,contadoragregadas,contador,contadorborradas,lista,nombreficherousuario,comprobarfichero); 
                    }else{             
    ComprobarFichero(fichero,contadoragregadas,contador,contadorborradas,lista,nombrefichero,comprobarfichero);
        }
                }        
                else{           
    ComprobarFichero(fichero,contadoragregadas,contador,contadorborradas,lista,nombreficherousuario,comprobarfichero);  
}

    //Dentro del bucle porque ira variando cada vez que se ejecute comando.
    LISTA *listaauxiliar;
    listaauxiliar = (LISTA *) malloc (sizeof(LISTA));   
    InicializarLista(listaauxiliar);   
             
    char *token[1000];
    char *ptr;
    //Limpia la cadena de la anterior ejecucion
    memset(cadena, 0, 1000); 
    int i,b, tam=0,numeroconfirmado=0;

    for(b=0; b < 50; b++)
    {
        token[b] = 0;
    }
   //Comprobara si el fichero citas.txt existe e ira actualizandose cada vez que se modifique alguna frase.
     
    gets(s1);
    while(strlen(s1) == 0){
        gets(s1);
    }    
    ptr = strtok(s1," ");
    token[0]= ptr;
    i=1;
    while(ptr != NULL){ // Posteriores llamadas
        ptr = strtok(NULL, " ");
        token[i]=ptr;
        i=i+1;
        tam++;
     }
            //Si el comando es salir se saldra del programa.
            if(strcmp(token[0], "salir") ==0){            
             //Debemos de crear el archivo citax.txt si no estaba creado anteriormente.
                if(fichero==NULL){
                fichero = fopen(nombrefichero, "w+"); 
                //Recorrera toda la lista
                CrearFicheroDefecto(lista,fichero);
                }
                //Los cambios de frases almacenadas en la lista, se guardarán automáticamente en el fichero de frases cargado
                else{
                //Abrimos el fichero en modo añadir al final para actualizarlo.
                fichero = fopen(nombreficherousuario, "w+"); 
                //Recorrera toda la lista
                CrearFicheroDefecto(lista,fichero);
                }
             return 0;
            }  
                   
           // Si el comando es frase + añadir una frase a la lista.
            else if(strcmp(token[0],"frase") == 0){
                 if (token[1] == 0){
                    printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");  
                }
                else if (strcmp(token[1],"+") == 0){
                //Si el usuario no introduce nada despues de frase + mostrara un mensaje de error
                if (token[2] == 0){
                    printf("\nError introduzca un autor para la frase\n\n");     
                }
                //Todo lo de despues de frase + sera el autor.             
                else{
                    //Hacemos un bucle recorriendo el array de tokens y lo vamos pegando en cadena.
                   for(i=2;i<tam;i++){
                        if (i==2){
                        strcat (cadena,token[i]); 
                            }
                            else{
                     strcat (cadena," ");     
                     strcat (cadena,token[i]); }          
                }
                //Funcion que obtiene el tamaño de la cadena autor para reserver la memoria.
                longitud = strlen(cadena);
                //Reserva de memoria para autor de tamaño exacto.
                autor=(char*)malloc(longitud*sizeof(char)); 
                if (autor  == NULL){
                    printf("\nError al reservar memoria para autor\n\n");
                    }        
                //Guardamos el autor introducido por el usuario.
                strcpy(autor,cadena);
                printf("\nIntroduzca la cita: ");
                gets(citasmemoria);
                longitud = strlen(citasmemoria);
                //Reserva de memoria para la frase de tamaño longitud.
                cita = (char*) malloc(longitud*sizeof(char));
                 if (cita  == NULL){
                        printf("\nError al reservar memoria para frase\n\n");
                 }
                clave = NULL;
                free(clave);
                clave = (char*) malloc (sizeof(char));
                clave[0]= '\0';
                strcpy(cita,citasmemoria);          
                //Comprobar si se introduce cita vacia.
                  if (strlen(cita)==0){
                        printf("\nError, debe introducir una frase.\n\n");
                       LiberarMemoriaNodo(autor,cita,clave);
                       }
                 else{
                 printf("\nIntroduza el a%co: ",(char)(164));              
                 gets(anomemoria);
                 ano = (char*) malloc (strlen(anomemoria)*sizeof(char));
                 strcpy(ano,anomemoria); 
                 printf("\n");
                //Si no introduce el año sera 9999
                if(strlen(ano) == 0){
                    ano = "9999";
                    }else{
                        numeroconfirmado = confirmarNumero(ano,cadenanumerica);
                        //Comprobamos si ano no es un numero sera 9999, si es un numero comprobamos si esta entre 0 y 2018  
                        if(numeroconfirmado == 1){
                                    if(cadenanumerica[0] < 0 || cadenanumerica[0] > 2018){      
                                            printf("El a%co no es valido guardado como 9999 por defecto\n\n",(char)(164));
                                            ano = "9999";
                                            }
                            }else{
                                ano = "9999";
                                }
                    }
                insertarNodo(cita,autor,clave,ano,lista);    
                OrdenarLista(lista);            
                contadoragregadas++;               
                    }
                }
            }
            
            //Comando para borrar frase.
               else if (strcmp(token[1],"-") == 0){
                //Si el usuario no introduce nada despues de frase - mostrara un mensaje de error
                if (token[2] == 0){
                    printf("\nError introduzca un autor para borrar su frase\n\n");     
                } 
                else if(token[3] == 0){
                   printf("\nError introduzca un valor numerico despues del autor\n\n"); 
                }
                //Si el ultimo dato introducido es 0 o no se hara siempre lo siguiente.
                else if(token[4] == 0 || token[4] != 0 ){      
                    //Reiniciamos la cadena.
                    memset(cadena, 0, 1000);       
                    //Recorre la cadena y la junta para nombres compuestos introducida empieza por 2 ya que "frase" y "-" ocupan 1 cada 1 
                            for(i=2;i<tam-1;i++){                     
                           if(i<tam-2){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }           
                                }
                    //Miramos si es un numero el ultimo dato introducido por el usuario.                          
                      numeroconfirmado = confirmarNumero(token[tam-1],cadenanumerica);                   
            if(numeroconfirmado == 1){    
                      contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
            //Si no hay ningun autor se saldra con error.
            if (contadordefrases==0){
                 printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
            }
            //Si el contador es menor al numero introducido se saldra con error.
            else if(contadordefrases < cadenanumerica[0] ){
                printf("\nEl numero de frases de ese autor es menor.\n\n");
            }          
            //Si solo hay un autor con esa frase y el numero introducido es 1 se borrara la frase del autor.
            else if(contadordefrases > 0 && cadenanumerica [0] > 0){ 
                do{   
                printf("\nEsta apunto de borrar la siguiente frase: \n");
                MostrarCita(lista,cadena,cadenanumerica[0]);
                printf("\nDesea confirmar borrado? <si> <otro?>: ");
                gets(confirmar);
                printf("\n\n");
                if(strcmp(confirmar,"si") == 0){
                BorrarFrase(lista, cadena,cadenanumerica[0]);
                contadorborradas++;
                break;
                }
                        else if(strcmp(confirmar,"otro") == 0){
                            break;}    
        }while(strcmp(confirmar,"si") != 0 || strcmp(confirmar,"otro") != 0 );
                                                             }   
                                      }  
            else{
                printf("\nEl numero introducido no es valido \n\n"); 
                }
                    }   
            } 
              
    //Comando para modificar frase.
    else if (strcmp(token[1],"=") == 0){
      //Si el usuario no introduce nada despues de frase - mostrara un mensaje de error
                if (token[2] == 0){
                    printf("\nError introduzca un autor para modificar su frase\n\n");     
                } 
                else if(token[3] == 0){
                   printf("\nError introduzca un valor numerico despues del autor\n\n"); 
                }
                //Si el ultimo dato introducido es 0 o no se hara siempre lo siguiente.
                else if(token[4] == 0 || token[4] != 0 ){      
                    //Reiniciamos la cadena.
                    memset(cadena, 0, 1000);       
                    //Recorre la cadena y la junta para nombres compuestos introducida empieza por 2 ya que "frase" y "-" ocupan 1 cada 1 
                            for(i=2;i<tam-1;i++){
                             if(i<tam-2){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }
                                }
                    //Miramos si es un numero el ultimo dato introducido por el usuario.                          
                      numeroconfirmado = confirmarNumero(token[tam-1],cadenanumerica);                       
            if(numeroconfirmado == 1){    
                      contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
            //Si no hay ningun autor se saldra con error.
            if (contadordefrases==0){
                 printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
            }
            //Si el contador es menor al numero introducido se saldra con error.
            else if(contadordefrases < cadenanumerica[0] ){
                printf("\nEl numero de frases de ese autor es menor.\n\n");
            }          
            //Si contadordefrase > 1
            else if(contadordefrases > 0 && cadenanumerica [0] > 0){              
                MostrarCita(lista,cadena,cadenanumerica[0]);
                printf("\nIntroduzca la nueva frase: ");
                gets(citasmemoria);
                //Reserva de memoria para la frase de tamaño longitud.
                cita=(char*)malloc(strlen(citasmemoria)*sizeof(char)); 
                strcpy(cita,citasmemoria);
                printf("\nIntroduzca el autor: ");   
                gets(autormemoria); 
                autor=(char*)malloc(strlen(autormemoria)*sizeof(char));
                strcpy(autor,autormemoria);
                printf("\nIntroduzca un a%co: ",(char)(164));   
                gets(anomemoria); 
                ano=(char*)malloc(strlen(anomemoria)*sizeof(char));
                strcpy(ano,anomemoria);         
                numeroconfirmado = confirmarNumero(ano,cadenanumerica2);            
                if(numeroconfirmado == 1){                         
                //Comprobar si se introduce cita vacia.
                if (strlen(cita) == 0 && strlen(ano) == 0 && strlen(autor) == 0){
                        printf("\nNo se ha modificado nada de la frase.\n\n");
                                    }
                else{                                                 
                // Cambiamos la frase del Autor con numero introducido por la frase guardadaen cita
                contador = ModificarFrase(lista,contador,cadena,cadenanumerica [0],cita,ano,autor);
                OrdenarLista(lista);    
                ImprimirLista(lista);
                }
                                    }
                                    //Si año no es un numero
                                    else{
                          //Si la cadena de ano esta vacia la dejamos vacia si introducen un caracter no numerico la pasamos a 9999
                                        if (strlen(ano) == 0){
                                            }else{
                                                  ano = "9999"; 
                                                }                                 
                  // Cambiamos la frase del Autor con numero introducido por la frase guardadaen cita
                contador = ModificarFrase(lista,contador,cadena,cadenanumerica [0],cita,ano,autor);
                OrdenarLista(lista);    
                ImprimirLista(lista);           
                                    }
                                }
                            }
                    else{ 
                           printf("\nEl numero introducido no es valido\n\n");   
                        }
                    }      
             }
                else{
                   printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");
                    }     
}
            // Si el comando es clave + añadira una clave a la frase del autor introducidos.
            else if(strcmp(token[0],"clave") == 0){
                    if (token[1] == 0){
                    printf("Comando introducido incorrecto, intentelo de nuevo.\n");  
                }
                //Comando para añadir clave
                else if (strcmp(token[1],"+") == 0){       
                  if (token[2] == 0){
                    printf("\nError introduzca un autor \n\n");     
                }           
               else if(token[3] == 0){
                    printf("\nError introduzca el numero de frase \n\n");
                }
                else if (token[4] == 0){
                    printf("\nError introduzca una clave o numero correcto \n\n");
                }
                else if (token[5] == 0 || token[5] != 0){
                   //Reiniciamos la cadena.
                   memset(cadena, 0, 1000); 
                   //Hacemos un bucle recorriendo el array de tokens y lo vamos pegando en cadena.
                   for(i=2;i<tam-2;i++){
                        if(i<tam-3){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }
                                      }  
            //Miramos si es un numero el ultimo dato introducido por el usuario.                          
            numeroconfirmado = confirmarNumero(token[tam-2],cadenanumerica);                                                                              
            if(numeroconfirmado == 1){    
                      contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
                      printf("Nº de frases de ese autor: %i",contadordefrases);
                      printf("\n",contadordefrases);
            //Si no hay ningun autor se saldra con error.
            if (contadordefrases==0){
                 printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
            }
            //Si el contador es menor al numero introducido se saldra con error.
            else if(contadordefrases < cadenanumerica[0] ){
                printf("\nEl numero de frases de ese autor es menor.\n\n");
            }          
            //Si contadordefrase > 1
            else if(contadordefrases > 0 && cadenanumerica [0] > 0){ 
               clave = NULL;
               free(clave);
                clave = (char*) malloc (strlen(token[tam-1])*sizeof(char));
                   clave = token[tam-1];  
                   //Si se hace modificacion correctamente se añade al contador.          
                     contador = AnadirClave(lista,cadena,cadenanumerica[0],clave,contador);
                                                                    }            
                                                              }  
                   else{
                        printf("\nEl numero introducido no es valido \n\n"); 
                        }
                        }                                  
                    }
                //Comando para borrar clave                            
                else if (strcmp(token[1],"-") == 0){
                if (token[2] == 0){
                    printf("\nError introduzca un autor \n\n");     
                }            
                else if(token[3] == 0){
                    printf("\nError introduzca el numero de frase \n\n");
                }
                else if (token[4] == 0){
                    printf("\nError introduzca una clave o numero correcto \n\n");
                }
                else if (token[5] == 0 || token[5] != 0){
                   //Reiniciamos la cadena.
                   memset(cadena, 0, 1000); 
                   //Hacemos un bucle recorriendo el array de tokens y lo vamos pegando en cadena.
                   for(i=2;i<tam-2;i++){
                         if(i<tam-3){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }
                                    }  
             //Miramos si es un numero el penultimo dato introducido por el usuario.                          
            numeroconfirmado = confirmarNumero(token[tam-2],cadenanumerica);                                                                              
            if(numeroconfirmado == 1){    
                      contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
            //Si no hay ningun autor se saldra con error.
            if (contadordefrases==0){
                 printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
            }
            //Si el contador es menor al numero introducido se saldra con error.
            else if(contadordefrases < cadenanumerica[0] ){
                printf("\nEl numero de frases de ese autor es menor.\n\n");
            }          
            //Si contadordefrase > 1
            else if(contadordefrases > 0 && cadenanumerica [0] > 0){
               
                //Volvemos a reservar memoria.clave = NULL;
                clave = NULL;
                free(clave);
                clave = (char*) malloc (strlen(token[tam-1])*sizeof(char));
                   clave = token[tam-1];            
                   contadorborradas = BorrarClave(lista,cadena,cadenanumerica[0],clave,contadorborradas);                                  
                                                                                }            
                                                              }  
                   else{
                        printf("\nEl numero introducido no es valido \n\n"); 
                        }
                        }                                  
                    }       
                else{
                   printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");
                        }     
                    }   
                                    
   else if(strcmp(token[0],"ver") == 0){
       //Si no tiene argumentos opcionales se muestra la lista
       if (token[1] == 0){
                   ImprimirLista(lista); 
                }
            //Si se indica un autor habra dos opciones cuando se introduce numero y cuando no
            else {  
                 //Comprobamos si es numero el siguiente elemento de autor o es un apellido.         
                    //Reiniciamos la cadena.
                    memset(cadena, 0, 1000);       
                    //Recorre la cadena y la junta para nombres compuestos introducida empieza por 1 ya que "ver" ocupan 1 
                        for(i=1;i<tam-1;i++){                     
                              if(i<tam-2){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }                       
                                }
                    //Miramos si es un numero el ultimo dato introducido por el usuario.                          
                      numeroconfirmado = confirmarNumero(token[tam-1],cadenanumerica);             
                      if(numeroconfirmado == 1){    
                      contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
                        //Si no hay ningun autor se saldra con error.
                        if (contadordefrases==0){
                             printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
                        }
            //Si el contador es menor al numero introducido se saldra con error.
            else if(contadordefrases < cadenanumerica[0] ){
                printf("\nEl numero de frases de ese autor es menor.\n\n");
            }          
            //Si el autor tiene esa frase y el numero introducido es 1 se mostrara la frase del autor.
            else if(contadordefrases > 0 && cadenanumerica [0] > 0){   
                    MostrarCitaClaves(lista,cadena,cadenanumerica[0]); 
                        }                 
            }
            //Si no es numero confirmado es que tiene mas de un nombre ese autor.
            else{
                    //Reiniciamos la cadena.
                   memset(cadena, 0, 1000); 
                   //Hacemos un bucle recorriendo el array de tokens y lo vamos pegando en cadena. 
                    for(i=1;i<tam;i++){                     
                           if(i<tam-1){                     
                            strcat (cadena,token[i]);
                            strcat (cadena," ");}
                              else{
                                    strcat (cadena,token[i]);
                                    }    
                                }                     
                   contadordefrases = ImprimirFrasesAutor(lista,cadena);
                    if(contadordefrases == 0){
                        printf("Error, ningun autor de la lista tiene el nombre introducido.\n\n");
                            }
                    }    
        }
    }
    
     //Comando para buscar frases
       else if(strcmp(token[0],"buscar") == 0){
         if (token[1] == 0){                
                  printf("\nError introduzca frase/autor/clave\n\n");
                }
                //Buscara todas las frases que contengan el texto introducido
                else if(strcmp(token[1],"frase") == 0){
                    if (token[2] == 0){                
                        printf("\nError introduzca el texto a buscar\n\n");
                        }else{
                            //Reiniciamos la cadena.
                            memset(cadena, 0, 1000);                 
                            for(i=2;i<tam;i++){
                                if(i==tam-1){                     
                          strcat (cadena,token[i]);
                        }else{
                            strcat (cadena,token[i]);
                            strcat (cadena," ");
                            }            
                            }  
                        printf("\nMostrando coincidencias: \n\n");    
                        MostrarFrasesConTexto(cadena,lista); 
                }
            }
                //Buscara todas las frases de los autores que contengan el texto introducido
                else if(strcmp(token[1],"autor") == 0){ 
                              if (token[2] == 0){                
                        printf("\nError introduzca el texto a buscar\n\n");
                        }else{
                            //Reiniciamos la cadena.
                            memset(cadena, 0, 1000);                 
                            for(i=2;i<tam;i++){
                                if(i==tam-1){                     
                          strcat (cadena,token[i]);
                        }else{
                            strcat (cadena,token[i]);
                            strcat (cadena," ");
                            }            
                            }  
                        printf("\nMostrando coincidencias: \n\n");    
                        MostrarAutorConTexto(cadena,lista); 
                }   
                }
                //Buscara todas las frases que contengan las claves del texto introducido
                else if(strcmp(token[1],"clave") == 0){ 
                               if (token[2] == 0){                
                        printf("\nError introduzca el texto a buscar\n\n");
                        }else{
                            //Reiniciamos la cadena.
                            memset(cadena, 0, 1000);                 
                            for(i=2;i<tam;i++){
                                if(i==tam-1){                     
                          strcat (cadena,token[i]);
                        }else{
                            strcat (cadena,token[i]);
                            strcat (cadena," ");
                            }            
                            }  
                    
                    printf("\nMostrando coincidencias: \n\n");    
                           MostrarClavesConTexto(cadena,lista);       
            }
           
        }
             else{                
                  printf("\nError introduzca frase/autor/clave\n\n");
                }           
                                
                       
                    }      
           
        //Comando para buscar el numero de claves total entre todas las frases para cada clave.
       else if(strcmp(token[0],"informe") == 0){
          if (token[1] == 0){                
                    printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");}
            else if(strcmp(token[1],"temas") == 0){
                int numClaves=0;
                //Llenamos vecClaves con todas las claves de las frases.      
                numClaves = LlenarClaves(lista,vecClaves);
                OrdenarClaves(vecClaves,numClaves);
                //JuntarClavesIguales(numClaves,vecClaves);
                printf("\nListado de claves: \n\n");
                for(j=0;j<numClaves;j++){
             printf("Clave n-%d: %s \tNumero de frases con esta clave: %d\n",j+1,vecClaves[j].clave,vecClaves[j].num);
             }   
              printf("\n");            
                }
                else{
                    printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");}             
            }
       
        //Comando para exportar frases de un autor en un fichero
    else if(strcmp(token[0],"exportar") == 0){
         if (token[1] == 0){                
                  printf("\nError introduzca un autor\n\n");
                }else if(strcmp(token[1],"autor") == 0){
                    if (token[2] == 0){                
                        printf("\nError introduzca el nombre del autor\n\n");
                        }else{
                            if (token[3] == 0){
                                 printf("\nError introduzca el nombre del fichero\n\n");
                                }else{
                            //Si el nombre de fichero es citas.txt o el que esta cargando en ese momento dara error. 
                            if(strcmp(token[tam-1],nombrefichero)  == 0 || strcmp(token[tam-1],nombreficherousuario) == 0){
                                printf("%s",token[tam-1]);
                                printf("\nError, nombre de fichero invalido\n\n");
                                }
                                else{                               
                                memset(cadena, 0, 1000);                 
                                for(i=2;i<tam-1;i++){                     
                                 if(i<tam-2){                     
                                  strcat (cadena,token[i]);
                                  strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }  
                                 }         
                                contadordefrases=ContarFrasesDelMismoAutor(lista,cadena);
                                //Si no hay ningun autor se saldra con error.
                                if (contadordefrases==0){
                                    printf("%s",cadena);
                                     printf("\nError, ningun autor de la lista tiene el nombre introducido.\n\n");
                                }
                                //Si no creamos el fichero con las frases de ese autor.
                                else{        
                                    ExportarFichero(lista,cadena,token[tam-1]);
                                    printf("\n");
                                    }            
                          }
                    }    
                }
            }
                else if(strcmp(token[1],"tema") == 0){
                     if (token[2] == 0){                
                        printf("\nError introduzca el nombre del tema\n\n");
                        }else{
                            if (token[3] == 0){
                                 printf("\nError introduzca el nombre del fichero\n\n");
                                }else{
                            //Si el nombre de fichero es citas.txt o el que esta cargando en ese momento dara error. 
                            if(strcmp(token[tam-1],nombrefichero)  == 0 || strcmp(token[tam-1],nombreficherousuario) == 0){
                                printf("%s",token[tam-1]);
                                printf("\nError, nombre de fichero invalido\n\n");
                                }
                                else{                               
                                memset(cadena, 0, 1000);                 
                                for(i=2;i<tam-1;i++){                     
                                 if(i<tam-2){                     
                                  strcat (cadena,token[i]);
                                  strcat (cadena," "); 
                              }
                              else{
                                    strcat (cadena,token[i]);
                                    }  
                                 }          
                                    ExportarFicheroClaves(lista,cadena,token[tam-1]);
                                    printf("\n");                                  
                          }
                    }    
                }
                    
                }
            }
             
        //Comando para cargar fichero
       else if(strcmp(token[0],"cargar") == 0){
               if (token[1] == 0){                
                    printf("Error, introduzca el nombre del fichero a cargar. \n");     
                }else if(token[1] != 0){
                        if (fichero == NULL){                         
                                //Abrimos fichero en escritura y lectura
                                fichero = fopen(token[1], "r+");
                                if(fichero != NULL){
                                while (feof(fichero) == 0){     
                                comprobarfichero=AnadirNodoLista(listaauxiliar,fichero);                     
                                //Si el formato del fichero no es correcto dara error y se recuperara la lista previa en caso de que la hubiera, si no se vaciara.
                                if(comprobarfichero == 0){       
                                break;
                                    }else{
                                          if(contador > 0 || contadorborradas > 0 || contadoragregadas > 0){
                                            printf("\nTiene cambiaos sin guardar,si desea cargar escriba 'ok':");
                                            gets(confirmar);
                                            printf("\n\n");
                                    if(strcmp(confirmar,"ok") == 0){
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                        }else{
                                            printf("\nNo ha cargado el archivo\n\n");
                                            comprobarfichero = 0;
                                            nombreficherousuario = "[NO FILE]";
                                            break;
                                            }  
                                            }
                                            
                                        lista = listaauxiliar;
                                        } 
                                }  
                                if(comprobarfichero != 0){
                                 OrdenarLista(lista);
                                 
                                 //Copiamos el nombre de fichero introducido por el usuario
                                strcpy(nombreficherousuario,token[1]); 
                                  //Contador a 0 al cargar.
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0; 
                                    } 
                                }
                                else{
                                    printf("\nError, el fichero esta vacio o no existe.\n\n");  
                                    comprobarfichero = 0;            
                                    }            
                                }else{
                                    fichero = fopen(token[1], "r+");
                                    //Si tenemos fichero lo cargamos.
                                    if(fichero != NULL){
                                    VaciarListaCargada(listaauxiliar);    
                                    while (feof(fichero) == 0){
                                    comprobarfichero=AnadirNodoLista(listaauxiliar,fichero);
                                    //Si el formato del fichero no es correcto dara error y se recuperara la lista previa en caso de que la hubiera, si no se vaciara.
                                    if(comprobarfichero == 0){
                                    break;
                                    }else{ 
                                      if(contador > 0 || contadorborradas > 0 || contadoragregadas > 0){
                                            printf("Tiene cambiaos sin guardar,si desea cargar escriba 'ok':");
                                            gets(confirmar);
                                            printf("\n\n");
                                    if(strcmp(confirmar,"ok") == 0){
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                        }else{
                                            printf("\nNo ha cargado el archivo\n\n");
                                            comprobarfichero = 0;
                                            break;
                                            }
                                    }else{
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                     
                                        }
                                        }        
                                    }
                                    if(comprobarfichero != 0){   
                                    OrdenarLista(lista);             
                                    //Copiamos el nombre de fichero introducido por el usuario
                                    strcpy(nombreficherousuario,token[1]);
                                  }
                                } 
                                 else{
                                    printf("\nError, el fichero esta vacio o no existe.\n\n");    
                                    comprobarfichero = 0;   
                                    }
                            }                        
                                    if(comprobarfichero != 0){
                                        printf("\n%i frases cargadas correctamente del fichero: %s\n\n",lista->longitud,token[1]);
                                        }                         
                                         }  
                                            }
                                            
           //Comando para guardar fichero
          else if(strcmp(token[0],"guardar") == 0)
            {
               if (token[1] == 0){                     
                //Guardara la lista actual en el fichero cargado.             
                //Debemos de crear el archivo citax.txt si no estaba creado anteriormente.
                if(fichero==NULL){
                    if(contador==0 && contadorborradas == 0 && contadoragregadas == 0){
                        printf("\nError,no hay ningun frase en la lista.\n\n");
                        }else{
                printf("\nError,no hay fichero cargado.\n\n");
                              }
                                 }                             
                //Los cambios de frases almacenadas en la lista, se guardarán automáticamente en el fichero de frases cargado
                else{
                     if(contador==0 && contadorborradas == 0 && contadoragregadas == 0){
                        printf("\nError,no hay ningun frase en la lista para guardar.\n\n");
                        }else{
                //Abrimos el fichero en modo añadir al final para actualizarlo.
                fichero = fopen(nombreficherousuario, "w+"); 
                //Recorrera toda la lista
                CrearFicheroDefecto(lista,fichero);      
                //Contador a 0 al guardar cambios.
                contador=0;  
                contadorborradas =0;
                contadoragregadas =0;       
                printf("\n");
                             }
                         }
                        } 
                //Si se indica el nombre del fichero a guardar 
                else{
                    //Si la lista esta vacia no se guardara.
                    if(lista->longitud == 0){
                        printf("\nError,la lista esta vacia.\n\n");
                        }
                        else{
                //Abrimos el fichero en modo añadir al final para actualizarlo.
                fichero = fopen(token[1], "w+"); 
                //Recorrera toda la lista
                CrearFicheroDefecto(lista,fichero);
                strcpy(nombreficherousuario,token[1]);
                            }
                //Contador a 0 al guardar cambios.
                contador=0;  
                contadorborradas =0;
                contadoragregadas =0;
                printf("\n");
                }   
            }  
             
               else if(strcmp(token[0],"limpiar") == 0){
                    if(token[1] != 0){
                        printf("\nError introduzca el comando correcto: limpiar\n\n");
                    }
                    else{
                        reiniciarnombreficherousuario = nombreficherousuario;
                        limpiar(lista,reiniciarnombreficherousuario);
                        contadoragregadas = 0;
                        contador = 0;
                        contadorborradas = 0;
                        }
                    }
                    
                else if(strcmp(token[0],"incluir") == 0){
                    if(token[1] == 0){
                        printf("\nError introduzca nombre de fichero\n\n");
                    }
                    else{
                        if(lista->longitud == 0){
                        if (fichero == NULL){                         
                                //Abrimos fichero en escritura y lectura
                                fichero = fopen(token[1], "r+");
                                if(fichero != NULL){
                                while (feof(fichero) == 0){     
                                comprobarfichero=AnadirNodoLista(listaauxiliar,fichero);                     
                                //Si el formato del fichero no es correcto dara error y se recuperara la lista previa en caso de que la hubiera, si no se vaciara.
                                if(comprobarfichero == 0){       
                                break;
                                    }else{
                                          if(contador > 0 || contadorborradas > 0 || contadoragregadas > 0){
                                            printf("\nTiene cambiaos sin guardar,si desea cargar escriba 'ok':");
                                            gets(confirmar);
                                            printf("\n\n");
                                    if(strcmp(confirmar,"ok") == 0){
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                        }else{
                                            printf("\nNo ha cargado el archivo\n\n");
                                            comprobarfichero = 0;
                                            nombreficherousuario = "[NO FILE]";
                                            break;
                                            }  
                                            }
                                            
                                        lista = listaauxiliar;
                                        } 
                                }  
                                if(comprobarfichero != 0){
                                 OrdenarLista(lista);
                                 
                                 //Copiamos el nombre de fichero introducido por el usuario
                                strcpy(nombreficherousuario,token[1]); 
                                  //Contador a 0 al cargar.
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0; 
                                    } 
                                }
                                else{
                                    printf("\nError, el fichero esta vacio o no existe.\n\n");  
                                    comprobarfichero = 0;            
                                    }            
                                }else{
                                    fichero = fopen(token[1], "r+");
                                    //Si tenemos fichero lo cargamos.
                                    if(fichero != NULL){
                                    VaciarListaCargada(listaauxiliar);    
                                    while (feof(fichero) == 0){
                                    comprobarfichero=AnadirNodoLista(listaauxiliar,fichero);
                                    //Si el formato del fichero no es correcto dara error y se recuperara la lista previa en caso de que la hubiera, si no se vaciara.
                                    if(comprobarfichero == 0){
                                    break;
                                    }else{ 
                                      if(contador > 0 || contadorborradas > 0 || contadoragregadas > 0){
                                            printf("Tiene cambiaos sin guardar,si desea cargar escriba 'ok':");
                                            gets(confirmar);
                                            printf("\n\n");
                                    if(strcmp(confirmar,"ok") == 0){
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                        }else{
                                            printf("\nNo ha cargado el archivo\n\n");
                                            comprobarfichero = 0;
                                            break;
                                            }
                                    }else{
                                    lista = listaauxiliar;
                                    contador=0;  
                                    contadorborradas =0;
                                    contadoragregadas =0;
                                     
                                        }
                                        }        
                                    }
                                    if(comprobarfichero != 0){   
                                    OrdenarLista(lista);             
                                    //Copiamos el nombre de fichero introducido por el usuario
                                    strcpy(nombreficherousuario,token[1]);
                                  }
                                } 
                                 else{
                                    printf("\nError, el fichero esta vacio o no existe.\n\n");    
                                    comprobarfichero = 0;   
                                    }
                            }                        
                                    if(comprobarfichero != 0){
                                        printf("\n%i frases cargadas correctamente del fichero: %s\n\n",lista->longitud,token[1]);
                                        }      
                        }    
                        else{
                            //Abrimos fichero en escritura y lectura
                                fichero = fopen(token[1], "r+");
                                if(fichero != NULL){
                                while (feof(fichero) == 0){     
                                comprobarfichero=AnadirNodoLista(listaauxiliar,fichero);  
                            }
                            if(comprobarfichero == 0){       
                                break;
                                    }
                                    else{
                                    contadoragregadas = anadirnodosaotralista(lista,listaauxiliar,contadoragregadas);  
                                    OrdenarLista(lista);
                                    }  
                                }
                            }
                        }
                    }
                            
                            
    
         
            
    //Comando no valido.
    else{
        printf("\nComando introducido incorrecto, intentelo de nuevo.\n\n");
        }
    }while(1);
      system("pause");
}

