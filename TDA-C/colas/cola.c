#include "cola.h"

int encolar(Cola *cola, Nodo *nuevoNodo){
	
	if (cola != NULL && nuevoNodo != NULL)/* Si cola existe y NuevoNodo existe*/
	{
		if (esColaVacia(cola))/* Si es cola vacia */
		{
			cola->cabeza = nuevoNodo;/* la cabeza es el NuevoNodo */
			cola->fin = nuevoNodo;/* el final es el NuevoNodo */
		}
		else/* si no esta vacia */
		{
			cola->fin->siguiente = nuevoNodo;/* el siguiente del que esta al final es el NuevoNodo*/
			cola->fin = nuevoNodo;/* Y ahora el Final es el ultimo de la fila */	
		}	
		cola->cantidad++;/* se incrememta la cantidad */
		return VERDADERO;/* se retorna el codigo numerico 1 indicando que se finalizo con exito */
	}
	/* si no existia cola o NuevoNodo */
	return ERROR;/* se retorna el codigo numerico -1 indicando la finalizacion si exiito de la funcion*/
}

Nodo* desencolar(Cola *cola){

	Nodo *temporalNodo = NULL;		

	if(!esColaVacia(cola)){/* si no es cola vacia */
		
		temporalNodo = cola->cabeza;/* guardo el primero en el temporal */
		cola->cabeza = temporalNodo->siguiente;/* la cabeza pasa a ser 
												el siguiente en la cola */
		temporalNodo->siguiente = NULL;	/* desvinculo el nodo de la cola */
		cola->cantidad--;/* decremento la cantidad de nodos en la cola */
		if (cantElementos(cola) == CERO);/* si se saco el ultimo nodo */
			cola->fin = NULL;/* apintador al final es nulo */
	}
	return temporalNodo;/* devuelvo el nodo */
}

Nodo* crearNodo(){
	Nodo *node = NULL;/* creo un apuntador a un tipo de dato nodo */					
	node = malloc(sizeof(Nodo));/* reservo memoria para el apuntador */			
	node->siguiente = NULL;/* inicializo en null*/
	return node; /* y lo devuelvo */		
}

Cola* crearCola(void){
	Cola *cola = NULL;/* creo un apuntador a un tipo de dato cola  */
	cola = malloc(sizeof(Cola));/* reservo memoria para el apuntador */	
	cola->cabeza = NULL;/* inicializo en null*/
	cola->fin = NULL;/* inicializo en null*/
	cola->cantidad = CERO;/* inicializo el contador en 0*/
	return cola;/* y lo devuelvo */
	
}

int esColaVacia(Cola *cola) {
	if (cola->cabeza == NULL && cantElementos(cola)== CERO)
		return VERDADERO;
	return FALSO;
}

int cantElementos(Cola *cola){
	return cola->cantidad;/* devuelvo la cantidad de elementos de esa cola */
}

int vaciarCola(Cola *cola){
	Nodo *temp = NULL;
	
	if (!esColaVacia(cola))/* si no es cola vacia */
	{
		temp = desencolar(cola);/* desencolo ...*/
		while (temp != NULL)/* repito mientras el nodo obtenido no sea nulo */
		{
			free(temp);/* libreo la memoria ocuada por el nodo desencolado */
			temp = desencolar(cola);/* desencolo nuevamente */
		}
		return VERDADERO;
	}
	return FALSO;
}

Nodo* consultaPrimero(Cola *cola){
	
	Nodo *temporal = NULL;
	if (!esColaVacia(cola))/* si no es cola vacia */
		temporal = cola->cabeza;/* guardo el nodo de la cabeza en temporal */

	return temporal;/* devuelvo temporal*/
}
