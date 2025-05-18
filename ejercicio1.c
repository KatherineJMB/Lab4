#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Funcion para encontrar longitud mas larga

/* 
*Inicializar variables
*For loop para recorrer la matriz por filas y columnas 
*Guardar en una variable el valor de cada casilla,usando punteros
*If para ver si el valor de la casilla es 1
*Si es 1:
*Se suma un 1 al contador
*Hacer un if para llevar un control del valor máximo del contador 
*Sino es 1, reiniciar el contador para seguir con la siguiente casilla 
*Guardar el valor del resultado en el puntero simple "result" 
 */

void findLargestLine (int **matrix, int size, int *result) {
        int resultado = 0;
        int contador = 0;

        for (int i = 0; i < size; i++) { //Recorrer la matriz
                for (int j = 0; j < size; j++) {
                        int largo = *(*(matrix + i)+j) ;
                        if ( largo  == 1) { //Revisar fila y columna si es igual a 1 
                                contador = contador + 1;
                                if (contador > resultado) { //Para tener guardado el mayor
                                resultado = contador ;
                                }

                        } else {
                                contador = 0;
                        }
                }
        }

        *result = resultado;
}

//Funcion para reservar la matriz en memoria dinamica
void allocatcMatrix(int ***matrix, int size) {
        *matrix = (int **)malloc(size * sizeof(int *));
        for (int i =0; i < size; i ++) {
        (*matrix)[i] = (int *)malloc(size * sizeof(int));
        }

}


//Funcion para llenar la matriz con numeros aleatorios
void fillMatrix (int **matrix, int size) {
        srand (time(NULL));
        int max = 1;
        int min = 0;

        for (int i =0; i < size; i ++) {
                for (int j =0; j < size; j ++) {
                        *(*(matrix + i)+j) = rand ()% (max - min +1 ) + min ;
                }
        }

}

//Funcion para imprimir la matriz
void printMatrix(int **matrix, int size) {
        printf("Matrix (%dx%d):\n", size, size) ;
        for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++) {
                        printf ("%d ", *(*(matrix + i) + j));
                }
                printf("\n");
        }
}


//Funcion para liberar la memoria asignada
void freeMatrix(int **matrix, int size) {
        for (int i = 0; i < size; i++) {
                free(matrix[i]);
        }
        free(matrix);
}


//Funcion principal (llama a las demas funciones)
int main () {
        int size, largestLine;
        int **matrix = NULL;
        printf ("Ingrese las dimensiones de la matriz: ");
        scanf ("%d" , &size);


        allocatcMatrix(&matrix, size);
        fillMatrix(matrix, size);
        printMatrix(matrix,size);
        findLargestLine(matrix, size, &largestLine);
        freeMatrix(matrix, size);

        printf("El tamano de la secuencia de 1s mas grande es: %d\n", largestLine);
        return 0;
}

