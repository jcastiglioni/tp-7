/* 
 * File:   frontend.h
 * Author: jorge
 *
 * Created on 12 de mayo de 2019, 14:38
 */

#ifndef BACKEND_H
#define BACKEND_H
#define FILAS 50 // tamaño maximo de filas
#define COLUMNAS 50 // tamaño maximo de filas

void generar_mundo (int m1 [FILAS] [COLUMNAS]);	//Funcion que "limpia" la matriz inicial m1, colocando celulas muertas en todas las posiciones, luego coloca las celulas vivas en los lugares deseados; (en caso de modificarlo tener en cuenta el tamanio de la matriz) 
void contar_vecinos (int m1[FILAS][COLUMNAS],int m2[FILAS][COLUMNAS] ); //la funcion recibe las dos matrices y guarda en la segunda matriz, poniendo en cada elemento la cantidad de celulas que tiene alrededor 
void Viva_Muerta (int m1[FILAS][COLUMNAS], int m2[FILAS][COLUMNAS]); // la funcion analiza si la celula de m1 esta viva o muerta y dependiendo de la cantidad de celulas vivas que tiene alrededor y establece su nuevo estado en m2. (la funcion recibe las dos matrices como paramentros de entrada)
void vaciar_mundo (int m2 [FILAS] [COLUMNAS]);	//Limpia la matriz m2 antes de actualizar la nueva evolucion
void copy_mat (int m1[FILAS][COLUMNAS],int m2[FILAS][COLUMNAS]);// Vuelca los datos de la evolucion de la matriz m2 a la matriz m1 
#endif // BACKEND_H

