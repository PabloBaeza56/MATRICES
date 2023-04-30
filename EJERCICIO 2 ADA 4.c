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

	void multiplicar_por_escalar(int matriz_A[M][N], int matriz_B[M][N], int escalar ){
		for (int i = 0; i < M; i++){
			for (int j = 0; j < M; j++){
				matriz_B[i][j] = matriz_A[i][j] * escalar;
			}
		}
	}
	
		
	int main(int argc, char *argv[]) {
		
		int escalar;
		int matriz_A[M][N];  //PRIMERA MATRIZ INGRESADA
		int matriz_B[M][N];  //MATRIZ RESULTADO
		
		puts("Calculadora que multiplica una matriz por un escalar:  ");
		leer_matriz(matriz_A, 'A');
		system("cls");
		puts("Ingrese el escalar:");
		scanf("%d", &escalar);
		
		multiplicar_por_escalar(matriz_A, matriz_B, escalar);
		system("cls");
		
		puts("\n Matriz A ");
		imprimir_Matriz(matriz_A);
		puts("\n Matriz Resultado ");
		imprimir_Matriz(matriz_B);
		
	
		
		return 0;
	}
