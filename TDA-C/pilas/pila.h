#include <stdio.h>
#include <stdlib.h>
/* codigos devuelto por funciones de lista */
#define VERDADERO 1
#define FALSO 0
#define ERROR -1

/*
 *	Estructura que representa un nodo
 * 
 * 	Atributos:
 * 		contenido: variable del tipo  Datos que contendra algun valor para trabajar
 * 		Siguiente: Puntero al nodo que sigue al nodo actual
 * 
 */
struct nodo{
	int contenido;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;

/*
 *	Estructura que representa una pila
 * 
 * 	Atributos:
 * 		cima: Puntero al primer nodo de la pila
 */
struct pila{
		Nodo *cima;
		int cantidad;
};
typedef struct pila Pila;


/*
 * apilar
 * 
 * Precondiciones:
 * 			para asegurar el funcionamiento correcro de la funcion:
 * 			-mi_pila debe existir .
 * 			-nuevoNodo debe existir y debe pasarse,
 * 			 ya con sus respectivos datos cargados.
 * 
 * Pos condiciones:
 * 			-La funcion con los datos dados por referencia correctamente
 * 			 agrega el nodo dado a la pila dada.
 * 
 * Entradas:
 * 			-mi_pila: Puntero a un tipo de dato pila, que corresponde a 
 * 			 la pila donde se agregara el nodo dado.
 * 			-nuevoNodo: Puntero a un tipo de dato nodo, corresponde al 
 * 			 nodo que se desea agregar a la pila.
 * Salidas:
 * 			-VERDADERO: Si el nodo dado se pudo agregar correctamente a 
 * 			 la pila dada.
 * 			-ERROR: Si no se ha podido agregar el nodo dado a la pila dada
 * 			 ya que o el nodo o la pila dada apuntan a NULL o no existen.
 * 
 */
int apilar(Pila *mi_pila, Nodo *nuevoNodo);

/*
 * desapilar
 * 
 * Precondiciones:
 * 			 para asegurar el funcionamiento correcro de la funcion:
 * 				-mi_pila debe existir.
 * 
 * Pos condiciones:
 * 			-La funcion con la pila dados por referencia correctamente
 * 			 desvincula completamente el nodo de la cima y lo devuelve.
 * 
 * Entradas:
 * 			-mi_pila: Puntero a un tipo de dato pila, que corresponde a 
 * 			 la pila donde se agregara el nodo dado.
 * Salidas:
 * 			-Puntero Nodo NULO: Si la pila dada no existe o la pila dada
 * 			 existe pero no posee nodos.
 * 			-Puntero Nodo con el Nodo de la Cima de la Pila: Si se pudo 
 * 	º		 desapilar correctamente el nodo de la cima se devuelve.
 * 
 */
Nodo* desapilar(Pila *mi_pila);

/*
 * crearNodo
 * 
 * Pos condiciones:
 * 			-La funcion retornara un puntero a una posicion de memoria 
 * 			 reservada por la funcion, el tipo de dato que reserva la 
 * 			 funcion en memoria es de tipo nodo.
 * 
 * Salidas:
 * 			-Puntero Nodo que apunta a la posición de memoria reservada
 * 			 por la funcion.
 * 			-Puntero Nodo NULO: si no se pudo reservar memoria por falta
 * 			 de esta, se retornara puntero nulo.
 */
Nodo* crearNodo();

/*
 * crearPila
 * 
 * Pos condiciones:
 * 			-La funcion retornara un puntero a una posicion de memoria 
 * 			 reservada por la funcion, el tipo de dato que reserva la 
 * 			 funcion en memoria es de tipo Pila.
 * 
 * Salidas:
 * 			-Puntero Pila que apunta a la posición de memoria reservada
 * 			 por la funcion.
 * 			-Puntero Nodo NULO: si no se pudo reservar memoria por falta
 * 		 	 de esta, se retornara puntero nulo.
 */
Pila* crearPila();

/*
 * esPilaVacia
 * 
 * Precondiciones:
 * 			-mi_pila debe existir.
 * 
 * Pos Condiciones:
 * 			-La funcion se encargara de acceder a los miembros de la 
 * 			 estructura pila encargada de contar y apuntar a el/los 
 * 			 nodos de la pila.
 * 
 * Entada:
 * 			-miPila Puntero de a tipo de dato pila, corresponde a la 
 * 			 pila a la cual se le pedira en numero de nodos que posee.
 * 
 * Salida:
 * 			-Entero que correspondera al numero de nodos enlazados a la 
 * 			 pila.
 * 		
 */
int esPilaVacia(Pila *miPila);

/*
 * esPilaVacia
 * 
 * Precondiciones:
 * 			-mi_pila debe existir.
 * 
 * Pos Condiciones:
 * 			-La funcion se encargara de acceder a al miembro de la 
 * 			 estructura pila encargada de contar.
 * 
 * Entada:
 * 			-miPila Puntero de a tipo de dato pila, corresponde a la 
 * 			 pila a la cual se le pedira en numero de nodos que posee.
 * 
 * Salida:
 * 			-Entero que correspondera al numero de nodos enlazados a la 
 * 			 pila.
 * 		
 */
int cantElementos(Pila *mipila);

/*
 * esPilaVacia
 * 
 * Precondiciones:
 * 			-mi_pila debe existir.
 * 
 * Pos Condiciones:
 * 			-Se desapilara nodo a nodo de la lista y se liberara la 
 * 			 memoria que ocupan hasta 
 * 
 * Entada:
 * 			-miPila Puntero de a tipo de dato pila, corresponde a la 
 * 			 pila a vaciar.
 * 
 * Salida:
 * 			-VERDADERO: se devolvera el codigo numerico 1 si se pudo 
 * 			 realizar correctamente el proceso de vaciameinto.
 * 			-FALSO: se devolvera 0 si la pila se encontraba vacia .
 * 		
 */
int vaciarPila( Pila *miPila );

int liberarPila( Pila *miPila );
