#include "pila.h"

int apilar(Pila *miPila, Nodo *nuevoNodo){

	if(miPila != NULL && nuevoNodo != NULL){		/* verifico que el nodo dado y la lista dada existan y no esten apuntando a NULO */
		if (esPilaVacia(miPila))					/* si no tiene nodos */
		{
			nuevoNodo->siguiente = NULL;			/* por si no estaba en nulo el siguiente del nodo a agregar */	
			miPila->cima = nuevoNodo;				/* la cima es el nodo dado */
			miPila->cantidad++;					    /* al agregar un nodo a la pila incremento el contador de nodos */
			return VERDADERO;
		}
		else
		{
			nuevoNodo->siguiente = miPila->cima;		/* el siguiente del nuevo es el nodo de la cima */
			miPila->cima = nuevoNodo;					/* ahora el nodo de la cima es el nuevo nodo */
			miPila->cantidad++;						    /* al agregar un nodo a la pila incremento el contador de nodos */
			return VERDADERO;
		}
	}
	return ERROR;
}

Nodo* desapilar(Pila *miPila){

	Nodo *temporalNodo = NULL;					/* creo un apuntador a un nodo*/
	
	if(esPilaVacia(miPila) == FALSO){							/* si la pila existe */
		temporalNodo = miPila->cima;				/* al apuntador nodo lo hago apuntar al nodo de la cima de la pila */
		miPila->cima = temporalNodo->siguiente;	/* al puntero de la cima lo hago apuntar al segundo de la cima */
		temporalNodo->siguiente = NULL;				/* desvinculo el nodo a desapilar totalmente de la pila */
		miPila->cantidad--;						/* decremento la cantidad de nodos de la lista */ 
	}

	return temporalNodo;						/* devuelvo el apuntador al nodo */
}

Nodo* crearNodo(){
	Nodo *node = NULL;							/* creo un apuntador de tipo nodo */
	node = malloc(sizeof(Nodo));				/* reservo memoria y al apuntador lo hago apuntar al sector de memoria */
	node->siguiente = NULL;
	return node;								/* devuelvo el apuntador apuntando al sector de memoria */
}


int esPilaVacia(Pila *miPila) {
	if (miPila->cima == NULL && miPila->cantidad == 0)
	{
		return VERDADERO;
	}
	return FALSO;
}

Pila* crearPila(){
	Pila *miPila = NULL;							/* creo un apuntador de tipo pila */
	miPila = malloc(sizeof(Pila));				/* reservo memoria y al apuntador lo hago apuntar al sector de memoria */
	miPila->cima = NULL;
	miPila->cantidad = 0;
	return miPila;								/* devuelvo el apuntador apuntando al sector de memoria reservado*/
}

int cantElementos(Pila *miPila){
	return miPila->cantidad;
}

int vaciarPila(Pila *miPila){
	Nodo *temp = NULL;
	
	if (!esPilaVacia(miPila)) /* se verifica que la pila contiene elementos */
	{
		temp = desapilar(miPila); /* se desapila y guarda el nodo desapilada*/
		while (temp != NULL)/* se repte mientras hallan nodos*/
		{
			free(temp);/* se libera la memoria ocupada por el nodo desapilado */
			temp = desapilar(miPila);/*  se desapila y guarda el posible nodo de la pila*/
		}
		return VERDADERO;/* si concluye correctamente se devuelve el codigo 1*/
	}
	return FALSO;/* si la pila estaba vacia se se retorna el codigo 0 */
}


int liberarPila( Pila *miPila ){
	if ( miPila != NULL )/** se verifica que la pila dada exista */
	{
		if ( esPilaVacia( miPila ) ) /** si no se encuentra vacia la pila... */
			vaciarPila( miPila );/** se procede a liberar los nodos de la pila */
		free( miPila );/** se procede a liberar la memoria ocupada por la pila */
		return VERDADERO;/** se retorna el codigo numerico que informa la finalizacion exitosa del proceso */
	} else 
		return ERROR;/** se retorna el codigo numerico que informa la finalizacion erronea del proceso */
}
