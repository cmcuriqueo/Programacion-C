#include "lista.h"

/*
 * CrearLista
 * 
 * Reserva memoria para una lista
 * 
 * Entradas:
 * 		lista Puntero a un puntero lista que representa la lista para la cual se reservara memoria, el puntero a la lista debe estar apuntando a NULL
 * 
 * Salida:
 * 		0 si la lista ya estaba creada
 * 		1 si se pudo reservar memoria correctamente
 * 		-1 si no hay memoria disponible y no se pudo reservar
 * 
 */
Lista* crearLista(){
	Lista *lista = NULL;
	lista = malloc( sizeof( Lista ) );	/* reservo memoria para la lista */
	lista->CantidadNodos = 0;
	lista->primero = NULL;
	lista->ultimo = NULL;
	return lista;/* si el puntero a la lista ya apuntaba a una lista devuelvo 0 */
}

Nodo* crearNodo(){
	Nodo *node = NULL;
	node = malloc( sizeof( Nodo ) );
	return node;
}

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
int esListaVacia( Lista *lista ){
	return ( lista->CantidadNodos == CERO && lista->primero == NULL ); //Si es lista vacia retorna 1 sino 0
}

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
int vaciarLista( Lista *lista ){
	Nodo *tempNodo, *ActualNodo = lista->ultimo;/* al puntador actual lo apunto al ultimo de la lista*/
	if ( !esListaVacia( lista ) )/*si no es una lista vacia */
	{
		while( ActualNodo != NULL )
		{
			tempNodo = ActualNodo;/*al apuntador temporal lo apunto al actual */
			ActualNodo = tempNodo->Anterior;/* al actual lo apunto al anterior */
			free( tempNodo );/*libero esa memoria apuntada por el temporal*/
			lista->CantidadNodos--;/* decremento el contador cada que se elimina un nodo*/
		}
		lista->primero = NULL;/* se vacia la lista, por lo tanto el nodo inicial es NULO */
		lista->ultimo = NULL;/* se vacia la lista, por lo tanto el nodo ultimo es NULO */    
		return VERDADERO;/* devuelvo 1 indicando que se relizo exitosamente*/
	}
	return ERROR;/* si la lista ya se encotraba vacia devuelvo -1 */
}

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
int insertarNodoalPrincipio( Nodo *NuevoNodo, Lista *lista ){
	if( lista != NULL ){
		if ( esListaVacia( lista ) )/*No hay lista*/
		{
			NuevoNodo->Siguiente = NULL;/* apunto el siguiente a NULO*/
			NuevoNodo->Anterior = NULL;/* apunto el Anterior es NULO */
			lista->primero = NuevoNodo;/* el nodo inicial es el primer nodo */
			lista->ultimo = NuevoNodo;/* el ultimo nodo es el unico nodo de la lista */
			lista->CantidadNodos++;/* se incrementa uno el contador de nodos */
		}
		else
		{
			NuevoNodo->Siguiente = lista->primero;/*el siguiente del nodo nuevo es el primero de la lista*/
			lista->primero->Anterior = NuevoNodo; /* el anterior de primer nodo, ahora es el nuevo nodo*/
			NuevoNodo->Anterior = NULL;/*el anterior del nuevo nodo es NULO*/
			lista->primero = NuevoNodo;/*el nodo inicial es el nuevo nodo*/
			lista->CantidadNodos++;/* incremento la cantidad de nodos de la lista*/
		}
		return VERDADERO;
	}else{
		return ERROR;
	}
}
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
int insertarNodoalFinal( Nodo *NuevoNodo, Lista *lista ){
	if ( esListaVacia( lista ) )/* si es una lista vacia...*/
	{
		return ( insertarNodoalPrincipio( NuevoNodo, lista ) );/* llamo a crear lista */
	}
	lista->ultimo->Siguiente = NuevoNodo;/* el siguiente nodo es el creado */
	NuevoNodo->Anterior = lista->ultimo;/* el nodo anterior es el nodo que representa el puntero */
	NuevoNodo->Siguiente = NULL;/* el siguiente del ultimo nodo creado es NULO */
	lista->ultimo = NuevoNodo;/* ahora el ultimo nodo es el nuevo nodo */
	lista->CantidadNodos++;/* incremento el contador de nodos */
	return VERDADERO;/* indica que se realizo correctamente */
}

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
int insetarNodoenPos( Nodo *NuevoNodo, Lista *lista, int posicion ){
	Nodo *tempNodo = NULL;/* creo un apuntador a un tipo de dato nodo que servira para obtener el nodo de la posicion donde se quiere agregar el nuevo nodo*/
	Nodo *NodoAnterior = NULL;/*apuntador a un tipo de dato nodo, corresponde al nodo anterior al de la posicion dende se quiere agregar */
	int Contador = INICIO;/* contador de posiciones en la lista */
	
	if ( !esListaVacia( lista ) )/* si la lista no esta vacia */
	{
		if ( posicion <= lista->CantidadNodos )/*si es una posicion valida */
		{
			if ( posicion == INICIO )/* si la posicion donde se quiere insertar es la primera*/
			{
				return insertarNodoalPrincipio(NuevoNodo, lista);/*llamo a insertar al principio*/
			}
			tempNodo = lista->primero;/* al temporal le asigno el primero de la lista */
			while ( Contador < posicion )/* mientras no llegue a la posicion requerida */
			{
				tempNodo = tempNodo->Siguiente;/*al apuntador temporal le asigno el siguinete */
				Contador++;/*incremento el contador de posiciones */
			}
			NodoAnterior = tempNodo->Anterior;/* al apuntador anterior lo hago apuntar al anterior a temporal para no perder referencias */
			NuevoNodo->Siguiente = tempNodo;/* al siguinete de nodo a insertar lo apunto al nodo temporal */
			NodoAnterior->Siguiente = NuevoNodo;/* al siguinete del anterior lo apunto al nuevo nodo*/
			tempNodo->Anterior = NuevoNodo;/* al antrior de temporal lo apunto al nuevo nodo */
			lista->CantidadNodos++;/* incremento la cantidad de nodos de la lista */
			return VERDADERO;/* devuelvo 1 para indicar que la operacion se realizo exitosa mente */
		}
		else
		{
			return insertarNodoalFinal( NuevoNodo, lista );
		}
		
	}
	insertarNodoalPrincipio( NuevoNodo, lista );/* si la lista estaba vacia la creo y inserto el nodo dado */
	return ERROR;//se retorna -1 si se inserto en otra posicion
}

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
int quitarNodoInicio( Lista *lista ){
	Nodo *tempNodo = NULL;/* creo un apuntador temporal */

	if ( !esListaVacia( lista ) )/* si no es una lista vacia...*/
	{
		if ( lista->CantidadNodos == INICIO )/*... y si es una lista de un nodo...*/
		{
			return ( vaciarLista( lista ) );/*...llamo a funcion borrar lista */
		}
		else
		{
			tempNodo = lista->primero;/*al nodo temporal se asigno el primero de la lista*/
			lista->primero = lista->primero->Siguiente;/* al apuntador del primero de la lista lo apunto al siguiente */
			free( tempNodo );/* libero la memoria apuntada por el nodo temporal */
			lista->primero->Anterior = NULL;/* al anterior del ahora primero lo apunto a nulo */
			lista->CantidadNodos--;/* decremento la cantidad de nodos*/
			return VERDADERO;/* devuelvo uno para indicar que finalizo correctamente */
		}
	}
	return FALSO;/* si no se pudo realizar devuelvo 0 */
}

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
int quitarNodoFinal( Lista *lista ){
	Nodo *tempNodo = NULL;/* creo un nodo temporal que servira para liberar la memoria del ultimo nodo*/
	if ( !esListaVacia( lista ) )/* si la lista no esta vacia */
	{
		tempNodo = lista->ultimo;/* como ptrS es el ultimo nodo se lo asigno a temporal */
		tempNodo->Anterior->Siguiente = NULL;/* al puntero nodo dado por referencia le asigno el enterior a el, en caso de no haber anterior apuntara a nulo*/
		lista->ultimo = lista->ultimo->Anterior;
		lista->ultimo->Siguiente = NULL;
		free( tempNodo );/* libero la memoria del nodo a eliminar*/
		lista->CantidadNodos--; /* como se elimino un nodo tengo que decrementra el contador de nodos*/
		if ( esListaVacia( lista ) )/* si no hay nodos*/
		{
			lista->primero = NULL;/* los apuntadores son nulos*/
			lista->ultimo = NULL;/* los apuntadores son nulos*/
		}
		return VERDADERO;/* si se pudo realizar la operacion retorno 1*/
	}
	return FALSO;
}

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
int quitarNodoPos( int indiceNodo, Lista *lista ){
	Nodo *tempNodo = lista->primero;/* declaro punteros a nodos temporales */
	Nodo *siguienteNodo = NULL;/* declaro punteros a nodos temporales */
	Nodo *anteriorNodo = NULL;/* declaro punteros a nodos temporales */
	int tempContador = INICIO;/* contador para determinar en que nodo estoy */

	if ( ( lista )->CantidadNodos >= indiceNodo ) /* verifico que existe esa cantidad de nodos */
	{
		if ( lista->CantidadNodos ==  INICIO && indiceNodo == INICIO )/* si la lista posee un solo nodo y ese nodo es el que se quiere eliminar...*/
		{
			return vaciarLista( lista );/* ... llamo a vaciar lista*/
		}
		else
		{
			if ( indiceNodo == lista->CantidadNodos )/* si el ultimo nodo es el que se quiere eliminar*/
			{
				return quitarNodoFinal( lista );
			}
			else/* si no es el pimero ni el ultimo busco el que se quiere eliminar*/
			{
				while ( tempContador != indiceNodo ) /* repito mientras no llegue al nodo que se quiere */
				{
					tempNodo = tempNodo->Siguiente;/* se "mueve" entre los nodos */
					tempContador++; /* incremento el contador temporal */
				}
				siguienteNodo = tempNodo->Siguiente;/* guardo el nodo anterior */
				anteriorNodo = tempNodo->Anterior;/* guardo el nodo siguiente */
				siguienteNodo->Anterior = anteriorNodo;/* el anterior del siguiente es el anterior del nodo a eliminar */
				anteriorNodo->Siguiente = siguienteNodo;/* el siguiente del anterior es el siguiente del nodo a eliminar */
				free( tempNodo );/* una vez enlazadas los dos nodos (anterior y siguiente) elimino el nodo desbinculado */
				lista->CantidadNodos--;/* decremento la cantidad de nodos*/
				return VERDADERO; /* operacion exitosa */
			}
		}
	}
	return FALSO;/* si no se puede eliminar retorno -1*/
}

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
Nodo* obtenerPrimerNodo( Lista *lista ){
	Nodo *tempNodo = NULL;/* creo un apuntador a un nodo temporal */
	if( !esListaVacia( lista ) )/* si no es lista vacia */
	{
		tempNodo = lista->primero;/* al apuntador temporal le asigno el primero de la lista */
	}
	return tempNodo;/* devuelvo el apuntador temporal */
}

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
Nodo* obtenerUltimoNodo( Lista *lista ){
	Nodo *tempNodo = NULL;/* creo un apuntador temporal a un nodo */
	if( !esListaVacia( lista ) )/* si no es una lista vacia */
	{
		tempNodo = lista->ultimo;/* el asigno el ultimo */
	}
	return tempNodo;/* devuelvo el nodo */
}

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
Nodo* obtenerPosNodo( Lista *lista, int posicion ){
	Nodo *tempNodo = NULL;/* creo un apuntador temporal a un tipo de dato nodo */
	int Contador = INICIO;/* contador de posiciones en la lista*/
	if ( lista->CantidadNodos >= posicion )/* si la cantidad de nodos en la lista es mayor o igual a la posicion requerida */
	{
		if ( posicion == INICIO)/* si es el pimer nodo...*/
		{
			return obtenerPrimerNodo( lista );/*...llamo a funcion obtener primero*/
		}
		if ( posicion == lista->CantidadNodos )/* si es el ultimo...*/
		{
			return obtenerUltimoNodo( lista );/*...llamo a funcion obtener ultimo */
		}
		tempNodo = lista->primero;/* al apuntador temporal lo hago apuntar al primero de la lista */
		while ( Contador < posicion && tempNodo->Siguiente != NULL )
		{
			tempNodo = tempNodo->Siguiente;
			Contador++;/* incremento el contador hasta llegar al requerido*/
		}
	}
	return tempNodo;/* retorno el nodo escontrado o un nodo nulo si no se encontro*/
}

int cantElementos( Lista *lista ){
	int i = lista->CantidadNodos;
	return i;
}
