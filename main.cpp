#include <stdio.h>
#include "backend.h"
#include "frontend.h"
#include "definiciones.h"
int main (void)
{
	int m1 [FILAS] [COLUMNAS];				// Matriz que genera el mundo de tamano maximo 50x50
	int m2 [FILAS] [COLUMNAS];				// Matriz secundaria para volcar los datos de la proxima evolucion
	int filas = 20 + CORRECTOR, columnas = 20 + CORRECTOR;  //el corrector evita problemas de analisis en los bordes de la matriz dejando filas y columnas para completar con celulas muertas

	generar_mundo (m1);
	vaciar_mundo (m2);
	int c;
	do
	{
		mostrar_mundo (m1, filas, columnas);
		contar_vecinos (m1, m2);
		Viva_Muerta(m1, m2);				//Durante le ejecucion del programa, evoluciona cada vez que se presiona enter
		copy_mat (m1, m2);
		vaciar_mundo (m2);
		printf("Presione enter para evolucionar");
	}while((c = getchar()) == '\n');

	
return 0;
}
