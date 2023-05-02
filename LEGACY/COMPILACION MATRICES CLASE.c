#include <stdio.h>
#define M 4 //FILA
#define N 4 //COLUMNA


	void leer_matriz(int matriz[M][N]){
		for (int fila = 0; fila < M; fila++){
			for (int col = 0; col < N; col++){
				printf ("\n Introduzca un valor en la Posicion [%d][%d]:",fila,col) ;
				scanf ("%d",&matriz[fila][col]);
				
			}
		}
		
	}
	
	void imprimirMatriz(int matriz[M][N]){
		puts("MATRIZ INSERTADA");
		for (int fila = 0; fila < M; fila++){
			for (int col = 0; col < 1; col++){
				printf ("\n %d | %d | %d | %d\n",matriz[fila][col],matriz[fila][col+1], matriz[fila][col+2],matriz[fila][col+3]);
			}
		}
	}
	
	void matrizIdentidad(int matriz[M][N]){
		
		int contador_elementos = 0;
		
		for (int col = 0; col < M; col++){
			if ( (matriz[col][col]) == 1){
				contador_elementos++;
			}
		}
		
		if (contador_elementos == M){
			puts("La matriz si es una matriz identidad");
		} else {
			puts("La matriz NOOO es una matriz identidad");
		}
		
	}
	
	
	void producto_diagonal_func(int matriz[M][N]){
		
		int producto_diagonal = 1;
		for (int col = 0; col < M; col++){
			producto_diagonal = producto_diagonal * (matriz[col][col]);
		}
		printf("%d es el producto diagonal", producto_diagonal); 
	}
	
	void imprimirTranspuesta(int matriz[M][N]){
		
		printf("\n");
		puts("MATRIZ TRANSPUESTA");
		for (int fila = 0; fila < M; fila++){
			for (int col = 0; col < 1; col++){
				printf ("\n %d | %d | %d | %d \n",matriz[col][fila], matriz[col+1][fila], matriz[col+2][fila], matriz[col+3][fila]);
			}
		}
	}
	
	void matrizSimetrica(int matriz[M][N]){
		int validacion = (M * N) - M;
		int contador_simetria = 0;
		
		for (int fila = 0; fila < M; fila++){
			for (int col = 0; col < N; col++){
				if ((matriz[fila][col]) == (matriz[col][fila])){
					contador_simetria++;
				}
			}
		}
		
		contador_simetria = contador_simetria - M;
		
		if (contador_simetria == validacion){
			puts("La matriz si es simetrica");
		} else {
			puts("La matriz NOOO es simetrica");
		}
	}
	

int main(int argc, char *argv[]) {
	
	int matriz[M][N];
	

	leer_matriz(matriz);
	
	printf("\n");
	imprimirMatriz(matriz);
	
	printf("\n");
	matrizIdentidad(matriz);
	matrizSimetrica(matriz);
	producto_diagonal_func(matriz);
	
	printf("\n");
	imprimirTranspuesta(matriz);
	
	
	/*
	leer matriz ok
	imprimir matriz ok 
	matriz identidad ok 
	matrizsimetrica
	producto diagonal principal ok 
	matriz transpuesta ok
	*/
	
	return 0;
}

