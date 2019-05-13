#include "definiciones.h"
#include "frontend.h"
#include <stdio.h>


void mostrar_mundo (int m1 [FILAS] [COLUMNAS], int filas, int columnas)	//Funcion que muestra en pantalla el estado actual del mundo
{
	int i , j;

	for (i=1; i<filas-1; i++)
	{
		for (j=1; j<columnas-1; j++)		//Recorre la matriz por filas y columnas colocando '*' donde hay una celula viva o' ' donde hay una celula muerta
		{
			if ((m1 [i] [j]) == VIVO)
			{
				printf ("|*");
			}
			else 
			{
				printf ("| ");
			}
		}
		printf ("|\n");
	}
}


