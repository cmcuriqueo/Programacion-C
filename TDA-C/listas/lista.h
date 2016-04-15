#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR -1
#define VERDADERO 1
#define FALSO 0
#define CERO 0
#define INICIO 1	/* corresponde al inicio de los contadores de posiciones */

/*
 *	Estructura que representa un nodo
 * 
 * 	Atributos:
 * 		elemento Datos que representa el/los datos que se guardaran en el nodo
 * 		Anterior Puntero a un nodo que representa el siguiente nodo de la lista
 * 		Siguiente Puntero a un nodo que representa el nodoa anterior en la lista
 * 
 */
struct nodo{
	int dato;
	struct nodo *Anterior;
	struct nodo *Siguiente;
};
typedef struct nodo Nodo;

/*
 *	Estructura que representa una lista
 * 
 * 	Atributos:
 * 		primero Puntero a un tipo de dato Nodo que representa el primer nodo de la lista
 * 		ultimo Puntero a un tipo de dato Nodo que representa el ultimo nodo de la lista
 * 		CantidadNodos Entero que representa un contador con la cantidad de nodos de la lista
 * 
 */
struct info{
	Nodo *primero;
	Nodo *ultimo;
	int CantidadNodos;
};
typedef struct info Lista;

/*
 * CrearLista
 * 
 * Reserva memoria para una lista
 * Salida:
 * 		Lista: apuntador al sector de memoria reservada por el sistema
 * 		NULL: apuntador de tipo lista NULO en caso de no poder reservar memoria 
 */
Lista* crearLista();

/*
 * crearNodo
 * 
 * Reserva memoria para un Nodo
 * Salida:
 * 		Nodo: apuntador al sector de memoria reservada por el sistema
 * 		NULL: apuntador de tipo nodo NULO en caso de no poder reservar memoria 
 */
Nodo* crearNodo();

/*
 * EsListaVacia
 *  
 * comprueba si una lista no posee o no nodos
 *  
 * Entradas:
 * 		lista Puntero a una lista que representa la lista a comprobar
 * 
 * Salida:
 * 		1 si la lista se encuenta vacia
 * 		0 si la lista no se encuenta vacia
 */
int esListaVacia(Lista *lista);

/*
 * VaciarLista
 * 
 * libera la memoria
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista, representa la lista en la que se eliminaran nodos
 * 
 * Salida:
 * 		1 si la operacion se ralizo correctamente y se libero la memoria ocupada por los nodos de la lista
 * 		-1 si la lista se encontraba vacia
 */
int vaciarLista(Lista *lista);

/*
 * InsertarNodoalPrincipio
 * 
 * inserta un nodo al principio de una lista, el nodo dado estara cargado con los datos. dentro de la funcion solo se enlaza el nodo a la lista
 * / la lista debe existir para el enlazamiento /
 * 
 * Entradas:
 * 		NuevoNodo Puntero a un puntero nodo que representra el nodo a agregar a la lista
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se agregara el nodo
 * 
 * Salida:
 * 		1 indicando que el nodo se inserto correctamente
 * 
 */
int insertarNodoalPrincipio(Nodo *NuevoNodo, Lista *lista);

/*
 * InsertarNodoalFinal
 * 
 * inserta un nodo al final de una lista
 * / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		NuevoNodo Puntero a un puntero nodo que representra el nodo a agregar a la lista
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se agregara el nodo
 * 
 * Salida:
 * 		1 si se pudo agregar correctamente el nodo dado
 * 		0 si no se pudo agregar
 */
int insertarNodoalFinal(Nodo *NuevoNodo, Lista *lista);

/*
 * InsetarNodoenPos
 * 
 * inserta un nodo en una posicion de una lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		NuevoNodo Puntero a un puntero nodo que representra el nodo a agregar a la lista
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se agregara el nodo
 * 		posicion Entero que representa la posicion el la lista donde se insertara el nodo dado
 * 
 * Salida:
 * 		1 si se pudo agregar correctamente el nodo dado
 * 		-1 si la lista se encontraba vacia y se inserto al pricipio 
 */
int insetarNodoenPos(Nodo *NuevoNodo, Lista *lista, int posicion);//

/*
 * QuitarNodoFinal
 * 
 * elimina el ultimo nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se eliminara el nodo
 * 
 * Salida:
 * 		1 si la operacion se realizo correctamenta
 * 		0 si la lista se encontraba vacia y no se puede eliminar un ultimo nodo
 */
int quitarNodoFinal(Lista *lista);

/*
 * QuitarNodoPos
 * 
 * elimina el primer nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		indiceNodo el numero de nodo a eliminar
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se eliminara el nodo
 * 
 * Salida:
 * 		1 si la operacion se realizo correctamenta
 * 		0 si la lista se encontraba vacia y no se puede eliminar un primer nodo
 */
int quitarNodoPos(int posicion, Lista *lista);

/*
 * QuitarNodoInicio
 * 
 * elimina el primer nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se eliminara el nodo
 * 
 * Salida:
 * 		1 si la operacion se realizo correctamenta
 * 		0 si la lista se encontraba vacia y no se puede eliminar un primer nodo
 */
int quitarNodoInicio(Lista *lista);

/*
 * ObtenerPirmerNodo
 * 
 * obtiene el primer nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se obtendra el nodo
 * 
 * Salida:
* 		retona un puntero nodo del primer nodo de la lista
 * 		si no se pudo obtener el nodo por que la lista esta vacia retona un puntero nodo NULO
 */
Nodo* obtenerPrimerNodo(Lista *lista);

/*
 * ObtenerUltimoNodo
 * 
 * obtiene el primer nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se obtendra el nodo
 * 
 * Salida:
 * 		retona un puntero nodo del ultimo nodo de la lista
 * 		si no se pudo obtener el nodo por que la lista esta vacia retona un puntero nodo NULO
 */
Nodo* obtenerUltimoNodo(Lista *lista);

/*
 * ObtenerPosNodo
 * 
 * obtiene un nodo de la lista
 *  / la lista debe existir para realizar el enlazamiento /
 * 
 * Entradas:
 * 		lista Puntero a un puntero de tipo lista que representa la lista donde se obtendra el nodo
 * 		posicion Entero que representa la posicion del nodo a obtener
 * 
 * Salida:
 * 		retona un puntero nodo de la lista en la posicion dada
 * 		si no se pudo obtener el nodo por que la lista esta vacia retona un puntero nodo NULO
 */
Nodo* obtenerPosNodo(Lista *lista, int posicion);

int cantElementos( Lista *lista );
