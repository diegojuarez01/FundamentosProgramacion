#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct nodo
{
//Datos del nodo.
char *frase;
char *autor;
char *claves;
char *ano;
struct nodo *siguiente, *anterior; 
// Una referencia al nodo siguiente, nulo para el último nodo
//Una referencia al nodo anterior, nulo para el primer nodo
} NODO;

//Estructura de la lista. con 3 punteros apuntando a NODO
typedef struct lista
{
NODO *primero;  //Apunta al primer nodo de la lista; nulo para la lista vacía
NODO *ultimo;   //Apunta al último nodo de la lista; nulo para la lista vacía
NODO *iterador; //Recorre la lista
int longitud;   //Saber el numero de nodos de la lista en cada momento
} LISTA;

typedef struct clave{
char *clave;
int num;
struct clave *siguiente, *anterior; 
} CLAVE ;
 
   
int anadirnodosaotralista(LISTA *lista, LISTA *listaauxiliar,int contador); 
void ExportarFicheroClaves (LISTA *lista,char *claves,char *nombreficherousuario);
void LiberarMemoriaNodo(char *autor,char *cita,char *clave);
void limpiar(LISTA *lista,char *reiniciarnombrefichero);
void InicializarLista(LISTA *l);
char* QuitarEtiquetas(char parte[],char cargarfrase[]);
void LeerFichero(LISTA *lista);
int TamanoLista(LISTA *lista);
void ImprimirLista(LISTA *lista);
int AnadirNodoLista(LISTA *lista,FILE *fichero);
int ModificarFrase(LISTA *lista,int contador, char *Autor,int numero,char *frase,char *ano,char *autorcambiado);
void CrearFicheroDefecto(LISTA *lista,FILE *fichero);
int ImprimirFrasesAutor(LISTA *lista,char *autor);
void MostrarCita(LISTA *lista,char *autor,int numero);
void MostrarCitaClaves(LISTA *lista,char *autor,int numero);
void ComprobarFichero(FILE* fichero,int contadoragregadas,int contador,int contadorborradas,LISTA *lista,char *nombreficherousuario,int comprobarfichero);
int BorrarClave(LISTA *lista,char *Autor,int numero, char *clave,int contadorborradas);
