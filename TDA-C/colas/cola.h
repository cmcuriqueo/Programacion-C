#include <stdio.h>
#include <stdlib.h>

/* codigos devuelto por funciones de cola */
#define VERDADERO 1
#define FALSO 0
#define ERROR -1
#define CERO 0

/*
 *	Estructura que representa un nodo
 * 
 * 	Atributos:
 * 		-contenido: variable del tipo  Datos que contendra algun valor para trabajar
 * 		-siguiente: Puntero al nodo que sigue al nodo actual
 * 
 */
struct nodo{
	int contenido;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;

/*
 *	Estructura que representa una cola
 * 
 * 	Atributos:
 * 		-cabeza: Puntero al primer nodo de la cola
 * 		-fin:  Puntero al ultimo nodo de la cola
 * 		-cantidad: Entero encargado de contar el numero de elementos en 
 * 		 cola
 * 
 */
struct cola{
		Nodo *cabeza;
		Nodo *fin;
		int cantidad;
};
typedef struct cola Cola;

/*
 * encolar
 * 
 * Pre Condicion:
 * 			La cola dada y el nodo a encolar deben existir.
 * 
 * Pos Condicion:
 * 			La función se encargara del enlazamiento del nodo dado con 
 * 			la cola dada.
 * 
 * Entradas:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola donde se 
 * 			 agregara un nodo.
 * 			-nuevoNodo: Apuntador de tipo Nola, corresponde al nodo a 
 * 			 agregar a la cola dada.
 * 
 * Salidas:
 * 			-VERDADERO:	La función retornara el codigo numérico 1 que 
 * 			 indicara la finalización correcta de la funcion.
 * 			-ERROR: La función retornara el codigo numérico -1 que 
 * 			 indicara la finalización incorrecta de la funcion.
 * 
 */
int encolar(Cola *cola, Nodo *nuevoNodo);

/*
 * desencolar
 * 
 * Pre Condicion:
 * 			La cola dada y el nodo a encolar deben existir.
 * 
 * Pos Condicion:
 * 			La función se encargara de desenlazar el nodo que se encuentra 
 * 			en la cabeza de la cola.
 * 
 * Entradas:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola donde se 
 * 			 desencolara el nodo que se encuentra en la primera posicion.
 * 
 * Salidas:
 * 			-Apuntador de Tipo Nodo no nulo: correspondera el nodo 
 *			 desencolado (el nodo cabeza de la cola).
 * 			-Apuntador de Tipo Nodo nulo: si la cola no posee elementos 
 * 			 (nodos).
 * 
 */
Nodo* desencolar(Cola *cola);

/*
 * crearCola
 *  
 * Pos Condicion:
 * 			La funcion reservara memoria para un tipo de dato Cola.
 * 
 * Salida:
 * 			-Apuntador de tipo Cola que poseera la posición de memoria 
 * 			 reservada.
 * 
 */
Cola* crearCola(void);

/*
 * crearNodo
 *  
 * Pos Condicion:
 * 			La funcion reservara memoria para un tipo de dato Nodo.
 * 
 * Salida:
 * 			-Apuntador de tipo Nodo que poseera la posición de memoria 
 * 			 reservada.
 * 
 */
Nodo* crearNodo();

/*
 * esColaVacia
 * 
 * Uso:
 * 			esColaVacia(cola) -es cola vacia.
 * 			!esColaVacia(cola) -no es cola vacia.
 * 
 * Pre Condiciones:
 * 			La cola dada debe existir.
 * 
 * Pos Condiciones:
 * 			La funcion accedera a los apuntadores de cola, y determinara 
 * 			si tiene nodos.
 * 
 * Entrada:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola de la 
 * 			 cual se determinara si posee nodos.
 * 			 
 * Salidas:
 * 			-VERDADERO: Si la cola dada se ecuentra vacia (no tiene nodos
 * 			 enlazados), retornara el código numérico 1
 * 			FALSO: Si la cola dada no se ecuentra vacia (tiene nodos
 * 			 enlazados a ella), retornara el código numérico 0
 * 
 */
int esColaVacia(Cola *cola);

/*
 * cantElementos
 * 
 * Pre Condiciones:
 * 			La cola dada debe existir.
 * 
 * Pos Condiciones:
 * 			-La función accedera a la variables del tipo de dato cola 
 * 			 encargada de contar los elementos (nodos) de la cola.
 * 
 * Entrada:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola de la 
 * 			 cual se requiere la cantidad de nodos.
 * 			 
 * Salida:
 * 			-entero: que representara la cantidad de nodos que posee la 
 * 			 cola dada.
 * 
 */
int cantElementos(Cola *cola);

/*
 * vaciarCola
 * 
 * Pre Condiciones:
 * 			La cola dada debe existir.
 * 
 * Pos Condiciones:
 * 			La funcion mediante un proceso de desencolado eliminara los 
 * 			nodos que posee la cola, liberando la memoria ocupada por los 
 * 			mismos.
 * 
 * Entrada:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola de la cual se 
 * 			 eliminaran todos los nodos.
 * 
 * Salida: 
 * 			-VERDADERO: la función retornara el código numérico 1, que 
 * 			 indica la finalización con exito de la función.
 * 			-FALSO: la función retornara el código numérico o, que 
 * 			 indicara que la pila dada no posee nodos.
 * 
 */
int vaciarCola(Cola *cola);

/*
 * consultaPrimero
 * 
 * Pre Condiciones:
 * 			La cola dada debe existir.
 * 
 * Pos Condiciones:
 * 			la funcion accedera a la primero nodo de la cola dada.
 * 
 * Entreda:
 * 			-cola: Apuntador de tipo Cola, corresponde a la cola de la 
 * 			 cual se pedira el primer nodos.
 * 
 * Salidas:
 * 			-Apuntador de Tipo Nodo no nulo: correspondera al primer nodo 
 *			  (el nodo cabeza de la cola).
 * 			-Apuntador de Tipo Nodo nulo: si la cola no posee elementos 
 * 			 (nodos).
 * 
 */
Nodo* consultaPrimero(Cola *cola);
