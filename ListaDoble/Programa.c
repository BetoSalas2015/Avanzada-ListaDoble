#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ListaDoble.h"

void llenaLista()
{
	insertder("Juanito", "Perez", "2455885522");
	insertder("Pedrita", "Lopez", "2455484452");
	insertder("Tomas", "Ramirez", "2465464522");
	insertder("Daniela", "Jimenez", "2455812212");
}

int main()
{
	nodo *ant, *sig;
	llenaLista();
	imprimeLista();
	imprimeListaInv();

	ant = primero;
	sig = primero->sig;

	sig -> sig -> ant =	ant;
	ant -> ant = ant -> sig;
	ant ->sig = sig -> sig;
	sig -> ant = NULL;
	sig -> sig = ant;

	primero = sig;

	printf("------------------\n");
	imprimeLista();
	imprimeListaInv();
	

	system("pause");
}



