#include<stdio.h>
#include <math.h>
#define M 3 // FILA REALES
#define N 6 // COLUMNAS OSEA M*2

void operar_matriz_con_pivotes(double matriz[M][N], int fila_a_trabajar, int fila_posicion_actual, float valor_a_operar){
	float matriz_temporal_operaciones[M][N]; // 2 FILAS M COLUMNAS
	
	for (int col = 0; col < N; col++){
		// asignar valores a la matriz temporal
		matriz_temporal_operaciones[fila_a_trabajar][col] = matriz[fila_a_trabajar][col];
		matriz_temporal_operaciones[fila_posicion_actual][col] = matriz[fila_posicion_actual][col];
		// realizar la operacion deseada
		matriz_temporal_operaciones[fila_a_trabajar][col] = matriz_temporal_operaciones[fila_a_trabajar][col] * valor_a_operar;
		// reasignar datos en la matriz oficial
		matriz[fila_posicion_actual][col] = matriz_temporal_operaciones[fila_posicion_actual][col] + matriz_temporal_operaciones[fila_a_trabajar][col];
	}
}

void operar_matriz_estocada_final(double matriz[M][N], int fila_posicion_actual, float valor_a_operar){
	for (int col = 0; col < N; col++){
		matriz[fila_posicion_actual][col] = matriz[fila_posicion_actual][col] * valor_a_operar;
	}
}

// rellenar matriz testing
void leer_matriz(double matriz[M][N])
{
	
	matriz[0][0] = 5;
	matriz[1][0] = 6;
	matriz[2][0] = 7;
	//matriz[0][3] = 1;
	//matriz[0][4] = -1;
	
	matriz[0][1] = 8;
	matriz[1][1] = 9;
	matriz[2][1] = 10;
	//matriz[1][3] = -1;
	//matriz[1][4] = 2;
	
	matriz[0][2] = 11;
	matriz[1][2] = 12;
	matriz[2][2] = 12;
	
	
	
	
	int fila_de_arranque = 0;
	int columna_de_arranque = M;
	
	for (int i = 0; i< M; i++){
		for (int f = M; f<N; f++){
			
			if ((i == fila_de_arranque) && (f == columna_de_arranque)){
				matriz[i][f] = 1;
			} else {
				matriz[i][f] = 0;
			}
		}
		fila_de_arranque++;
		columna_de_arranque++;
	}
}

void imprimirMatriz(double matriz[M][N])
{
	for (int fila = 0; fila < M; fila++){
		for (int col = 0; col < N; col++){
			printf("%.4f  ", matriz[fila][col]);
		}
		printf("\n");
	}
}

void imprimirMatriz_matraca_desendente(double matriz[M][N]){ // ok
	int fila = 0;
	int col = 0;
	int contador_identidad = 0;
	
	while (fila < M){
		while (col < M){
			
			if (fila == col){
				float res = 1 / matriz[fila][col];
				operar_matriz_estocada_final(matriz, fila, res);
			}else{
				float res = (matriz[col][fila]) * -1;
				operar_matriz_con_pivotes(matriz, fila, col, res);
			}
			
			if (col == M - 1){
				contador_identidad++;
				
				col = contador_identidad;
				fila = contador_identidad;
				continue;
			}
			col++;
		}
		fila++;
	}
}

void imprimirMatriz_matraca_asendente(double matriz[M][N]){
	
	int fila = M - 2; 
	int col = M - 1;  
	int setear_fila = fila;
	int setear_columna = col;
	
	for (int f = 0; f < N; f++){
		for (int i = 0; i < col; i++){
			if (fila != col){
				float res = (matriz[fila][col]) * -1;
				operar_matriz_con_pivotes(matriz, col, fila, res);
			}
			fila--;
		}
		setear_fila--;	  
		setear_columna--; 
		
		fila = setear_fila;
		col = setear_columna;
	}
}

void corregir_0_negativo(double matriz[M][N]){
	for (int i = 0; i < M; i++){
		for (int f = 0; f < M; f++){
			int res = floor(matriz[i][f]);
			if (res <= -0){
				matriz[i][f] = 0;
			}
		}
	}
}

void redondeo_milesimal(double matriz[M][N])
{ 
	int fila_de_arranque = 0;
	int columna_de_arranque = 3;
	
	for (int i = 0; i< M; i++){
		for (int f = M; f<N; f++){
			
			float numerox = matriz[i][f];
			//printf("%f numero a evaluar\n", numerox);
			int entero = (int)numerox;
			//printf("%d entero\n", entero);
			float res = numerox - (int)entero;
			//printf("%f residuo\n", res);
			if (res < 0){
				res = res + 1;
			} else {
				res = 1 - res ;
			}
			//printf("%f nano residuo\n", res);
			
			if (res <= 0.00001){
				matriz[i][f] = round(numerox);
			}
		}
		fila_de_arranque++;
		columna_de_arranque++;
	}
}



int main(int argc, char *argv[])
{
	double matriz[M][N];
	
	
	leer_matriz(matriz);
	imprimirMatriz(matriz);
	
	imprimirMatriz_matraca_desendente(matriz);
	imprimirMatriz_matraca_asendente(matriz);
	redondeo_milesimal(matriz);
	corregir_0_negativo(matriz);
	puts("\n");
	imprimirMatriz(matriz);
	
	
	return 0;
}
