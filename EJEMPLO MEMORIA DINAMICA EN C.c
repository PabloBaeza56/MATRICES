#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows, cols, i, j;
	
	printf("Ingrese el número de filas: ");
	scanf("%d", &rows);
	printf("Ingrese el número de columnas: ");
	scanf("%d", &cols);
	
	// Reservar memoria para la matriz
	int **matrix = (int **)malloc(rows * sizeof(int *));
	for (i = 0; i < rows; i++) {
		matrix[i] = (int *)malloc(cols * sizeof(int));
	}
	
	// Inicializar la matriz
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// Imprimir la matriz
	printf("La matriz es:\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	// Liberar la memoria reservada para la matriz
	for (i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
	
	return 0;
}
