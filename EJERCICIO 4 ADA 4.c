#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 3

	void leer_matriz(int matriz[M][N], char letra){
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				printf("%c[%d,%d]  ",letra, i, j);
				scanf("%d",&matriz[i][j]);
			}
		}
	}
	
	void imprimir_Matriz(int matriz[M][N]){
		for (int i = 0; i < M; i++){
			printf("[   ");
			for (int j = 0; j < M; j++){
				printf("%d   ",matriz[i][j]);
			}
			printf("]");
			printf("\n");
		}
	}
	
	void transpuesta_Matriz(int matriz_A[M][N], int matriz_B[M][N]){
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				matriz_B[i][j] = matriz_A[j][i];
			}
		}
	}
	
	
	int main(int argc, char *argv[]) {
		
		int matriz_A[M][N];  //PRIMERA MATRIZ INGRESADA
		int matriz_B[M][N];  //MATRIZ RESULTADO
		
		puts("Calculadora que crea una matriz transpuesta:  ");
		leer_matriz(matriz_A, 'A');
		system("cls");
		
		transpuesta_Matriz(matriz_A, matriz_B);
		
		puts("\n Matriz A ");
		imprimir_Matriz(matriz_A);
		puts("\n Matriz Resultado ");
		imprimir_Matriz(matriz_B);
		
		
		return 0;
	}
	
