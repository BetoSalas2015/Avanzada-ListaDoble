
struct Nodo					//  DEfinimos la estructura nodo
{
	char nombre[20];
	char apellido[35];
	char telefono[11];
	struct Nodo *ant, *sig;
};

typedef struct Nodo nodo;	//  Definimos el nuevo tipo de dato nodo

nodo *primero, *ultimo = NULL;			//  Creamos la lista vacía o nula

int isEmpty()
{
	if(primero == NULL && ultimo == NULL)
		return 1;
	else
		return 0;
}
			
void insertizq(char nom[],char ap[], char tel[])
{
	nodo *nuevo = NULL;
	if( isEmpty() )		//  La lista está vacía
	{
		nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
		strcpy(nuevo->nombre, nom);		//  copia la cadena2 en la cadena1
		strcpy(nuevo->apellido, ap);// Guardamos los datos en el campo info
		strcpy(nuevo->telefono, tel);	
		nuevo -> sig = NULL;		// No hay siguiente nodo
		nuevo -> ant = NULL;
		primero = ultimo = nuevo;				// Enlazamos a la lista ligada.
	}
	else					// La lista NO está vacía...
	{
		nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
		strcpy(nuevo->nombre, nom);		//  copia la cadena2 en la cadena1
		strcpy(nuevo->apellido, ap);// Guardamos los datos en el campo info
		strcpy(nuevo->telefono, tel);	
		nuevo -> sig = primero;		// No hay siguiente nodo
		nuevo -> ant = NULL;
		primero -> ant = nuevo;
		primero = nuevo;				// Enlazamos a la lista ligada.
	}
}

void insertder(char nom[],char ap[], char tel[])
{
	nodo *nuevo = NULL;
	if( isEmpty() )		//  La lista está vacía
	{
		nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
		strcpy(nuevo->nombre, nom);		//  copia la cadena2 en la cadena1
		strcpy(nuevo->apellido, ap);// Guardamos los datos en el campo info
		strcpy(nuevo->telefono, tel);	
		nuevo -> sig = NULL;		// No hay siguiente nodo
		nuevo -> ant = NULL;
		primero = ultimo = nuevo;				// Enlazamos a la lista ligada.
	}
	else					// La lista NO está vacía...
	{
		nuevo = (nodo *) malloc( sizeof(nodo) );  // Creamos el nuevo nodo
		strcpy(nuevo->nombre, nom);		//  copia la cadena2 en la cadena1
		strcpy(nuevo->apellido, ap);// Guardamos los datos en el campo info
		strcpy(nuevo->telefono, tel);	
		nuevo -> ant = ultimo;		// No hay siguiente nodo
		nuevo -> sig = NULL;
		ultimo -> sig = nuevo;
		ultimo = nuevo;				// Enlazamos a la lista ligada.
	}
}

void remueveizq(char *nom,char *ap, char *tel)
{
	nodo *elimina = NULL;	
	if( !isEmpty() )
	{
		elimina = primero;
		primero = elimina->sig;
		primero -> ant = NULL;
		strcpy(nom,elimina->nombre);
		strcpy(ap, elimina->apellido);
		strcpy(tel,elimina->telefono);
		free(elimina);
	}
}

void remueveder(char *nom,char *ap, char *tel)
{
	nodo *elimina = NULL;	
	if( !isEmpty() )
	{
		elimina = ultimo;
		ultimo = elimina->ant;
		ultimo -> sig = NULL;
		strcpy(nom,elimina->nombre);
		strcpy(ap, elimina->apellido);
		strcpy(tel,elimina->telefono);
		free(elimina);
	}
}

void imprimeLista()
{
	nodo *recorre = primero;
	while(recorre != NULL)
	{
		printf("%s %s, tel: %s \n", recorre ->nombre,recorre->apellido, recorre->telefono);
		recorre = recorre -> sig;
	}
	printf("\n");
}

void imprimeListaInv()
{
	nodo *recorre = ultimo;
	while(recorre != NULL)
	{
		printf("%s %s, tel: %s \n", recorre ->nombre,recorre->apellido, recorre->telefono);
		recorre = recorre -> ant;
	}
	printf("\n");
}