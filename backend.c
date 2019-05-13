#include "definiciones.h"
#include "backend.h"


void generar_mundo (int m1 [FILAS] [COLUMNAS])	//Funcion que "limpia" la matriz inicial m1, colocando celulas muertas en todas las posiciones, luego coloca las celulas vivas en los lugares deseados; (en caso de modificarlo tener en cuenta el tamanio de la matriz) 
{
	int i = 0, j = 0;

	for (i=0; i<FILAS; i++)
	{
		for (j=0; j<COLUMNAS; j++)
		{
			m1 [i] [j] = 0;
		}
	}
	//COLOCAR CELULAS EN LOS SIGUIENTES CASILLEROS; MAXIMO DE FILAS = filas-1 , MAXIMO DE COLUMNAS = columnas-1

	/*m1 [6] [3] = VIVO;
	m1 [6] [4] = VIVO;
	m1 [6] [5] = VIVO;
	m1 [5] [5] = VIVO;
	m1 [4] [4] = VIVO;
	m1 [3] [2] = VIVO;
	m1 [4] [1] = VIVO;
	m1 [3] [2] = VIVO;
	m1 [3] [1] = VIVO;
	m1 [3] [3] = VIVO;*/
	m1 [14] [8] = VIVO;
	m1 [14] [7] = VIVO;
	m1 [13] [6] = VIVO;
	m1 [12] [5] = VIVO;
	m1 [11] [5] = VIVO;
	m1 [10] [5] = VIVO;
	m1 [9] [6] = VIVO;
	m1 [8] [7] = VIVO;
	m1 [8] [8] = VIVO;
	m1 [9] [10] = VIVO;
	m1 [10] [11] = VIVO;
	m1 [11] [11] = VIVO;
	m1 [12] [11] = VIVO;
	m1 [11] [12] = VIVO;
	m1 [11] [9] = VIVO;
	m1 [13] [10] = VIVO;
	

}

void contar_vecinos (int m1[FILAS][COLUMNAS],int m2[FILAS][COLUMNAS] ) //la funcion recibe las dos matrices y guarda en la segunda matriz, poniendo en cada elemento la cantidad de celulas que tiene alrededor 
{
	int i;
	int j;
	for (i = 1 ; i < (FILAS-1) ; ++i) //De cada elemento de la primer matriz, analiza cuantas 							celulas vivas tiene a su alrededor y guarda el 							resultado en la misma posicion de la nueva matriz 
	{
		for (j = 1; j < (COLUMNAS-1); ++j) 
		{		
			if (m1 [i-1] [j-1] == VIVO)
			{
				m2 [i][j]++;
			}
			if (m1 [i] [j-1] == VIVO)
			{
				m2[i][j]++;
			}
			if (m1 [i+1] [j-1] == VIVO)
			{
				m2[i][j]++;
			}
			if (m1 [i-1] [j] == VIVO)
			{
				m2 [i][j]++;
			}
			if (m1 [i+1] [j] == VIVO)
			{
				m2 [i][j]++;
			}
			if (m1 [i-1] [j+1] == VIVO)
			{
				m2 [i][j]++;
			}
			if (m1 [i] [j+1] == VIVO)
			{
				m2 [i][j]++;
			}
			if (m1 [i+1] [j+1] == VIVO)
			{
				m2 [i][j]++;
			}
		}
	}	
}

void Viva_Muerta (int m1[FILAS][COLUMNAS], int m2[FILAS][COLUMNAS]) 	// la funcion analiza si la celula de m1 esta viva o muerta y dependiendo de la cantidad de celulas vivas que tiene alrededor se 										//establece su nuevo estado en m2. (la funcion recibe las dos matrices como paramentros de entrada)
{
	int j;
	int i;
	
	for (i = 1 ; i < (FILAS-1) ; ++i)  
	{
		for (j = 1; j < (COLUMNAS-1); ++j) 
		{
			if (m1 [i][j]) //analiza si la celula de m1 esta viva o muerta
			{	
				switch (m2 [i][j])
				{
					case 0:case 1:case 4:case 5: case 6: // si la celula tiene menos que 2 o mas que 3 celulas vivas alrededor, la celula muere
					m2[i][j] = MUERTO; break;
					case 2: case 3: //si tiene exactamente 2 o 3 celulas vivas alrededor, la celula sobrevive
					m2[i][j] = VIVO; break; 
				}
			}
			else 
			{
				switch (m2[i][j]) // si la celula de m1 esta muerta se analiza si alrededor tiene 2 o 3 celulas vivas. entonces la celula nace en m2
				{	
					case 0:case 1:case 2:case 4:case 5: case 6: 
					m2[i][j] = MUERTO; break;
					case 3:
					m2[i][j] = VIVO; break; // por mas que el break no tenga efecto en la sentencia lo agrego para mas claridad en el codigo
				}
			}
		}
	}	
}

void vaciar_mundo (int m2 [FILAS] [COLUMNAS])	//Limpia la matriz m2 antes de actualizar la nueva evolucion
{
	int i = 0, j = 0;

	for (i=0; i<FILAS; i++)
	{
		for (j=0; j<COLUMNAS; j++)
		{
			m2 [i] [j] = 0;
		}
	}
}

void copy_mat (int m1[FILAS][COLUMNAS],int m2[FILAS][COLUMNAS] ) // Vuelca los datos de la evolucion de la matriz m2 a la matriz m1 
{
	int i = 0, j = 0;

	for (i=0; i<FILAS; i++)
	{
		for (j=0; j<COLUMNAS; j++)
		{
			m1 [i] [j] = m2 [i] [j];
		}
	}
}

