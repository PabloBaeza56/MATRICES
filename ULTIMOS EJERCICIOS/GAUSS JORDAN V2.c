#include <stdio.h>
#include <math.h>
#define M 5 // FILA
#define N 6 // COLUMNA osea M+1

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
void leer_matriz(double matriz[M][N]){
	
	matriz[0][0] = 2;
	matriz[0][1] = -1;
	matriz[0][2] = 4;
	matriz[0][3] = 1;
	matriz[0][4] = -1;
	
	matriz[1][0] = -1;
	matriz[1][1] = 3;
	matriz[1][2] = -2;
	matriz[1][3] = -1;
	matriz[1][4] = 2;
	
	matriz[2][0] = 5;
	matriz[2][1] = 1;
	matriz[2][2] = 3;
	matriz[2][3] = -4;
	matriz[2][4] = 1;
	
	matriz[3][0] = 3;
	matriz[3][1] = -2;
	matriz[3][2] = -2;
	matriz[3][3] = -2;
	matriz[3][4] = 3;
	
	matriz[4][0] = -4;
	matriz[4][1] = -1;
	matriz[4][2] = -5;
	matriz[4][3] = 3;
	matriz[4][4] = -4;
	
	
	matriz[0][5] = 7;
	matriz[1][5] = 1;
	matriz[2][5] = 33;
	matriz[3][5] = 24;
	matriz[4][5] = -49;
}

void imprimirMatriz(double matriz[M][N]){
	for (int fila = 0; fila < M; fila++){
		for (int col = 0; col < 1; col++){
			printf("\n %f | %f | %f | %f | %f | %f     \n", matriz[fila][col], matriz[fila][col + 1], matriz[fila][col + 2], matriz[fila][col + 3], matriz[fila][col + 4], matriz[fila][col + 5]);
		}
	}
}

void imprimirMatriz_matraca_desendente(double matriz[M][N]){ // ok
	int fila = 0;
	int col = 0;
	int contador_identidad = 0;
	
	// printf("%d col operada \n", columna_que_sera_operada);
	// printf("%d fila de inicio \n \n", fila_de_inicio);
	
	while (fila < M){
		while (col < M){
			
			if (fila == col){
				// printf("%d  %d beep\n", fila, col);
				float res = 1 / matriz[fila][col];
				operar_matriz_estocada_final(matriz, fila, res);
			}
			else{
				// printf("%d  %d boop\n", fila, col);
				float res = (matriz[col][fila]) * -1;
				operar_matriz_con_pivotes(matriz, fila, col, res);
			}
			
			if (col == M - 1){
				// puts("beep"); //trigger event
				
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
	
	int fila = M - 2; // 2
	int col = N - 2;  // 3
	int setear_fila = fila;
	int setear_columna = col;
	
	for (int f = 0; f <= N - 1; f++){
		for (int i = 0; i < col; i++){
			
			if (fila != col){
				// printf("%d %d \n", col,fila);
				// float res = (matriz[fila][col]) * -1;
				// operar_matriz_con_pivotes(matriz,col, fila, res);
				float res = (matriz[fila][col]) * -1;
				operar_matriz_con_pivotes(matriz, col, fila, res);
			}
			
			fila--;
		}
		
		setear_fila--;	  // 1
		setear_columna--; // 2
		
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

void redondeo_milesimal(double matriz[M][N]){ //falta comprobar mas casos de redondeo
	double numerox;
	for (int f = 0; f<M; f++){
		numerox = matriz[f][M];
		
		int entero = numerox;
		float res = numerox - entero;
		
		if (entero == 0){
			res = numerox - 1;
			if (res <= 0.00000001){
				matriz[f][M] = round(numerox);
			}
		}
	}
}

int main(int argc, char *argv[]){
	
	double matriz[M][N];
	
	leer_matriz(matriz);
	imprimirMatriz(matriz);
	
	imprimirMatriz_matraca_desendente(matriz);
	imprimirMatriz_matraca_asendente(matriz);
	corregir_0_negativo(matriz);
	redondeo_milesimal(matriz);
	
	
	puts("");
	imprimirMatriz(matriz);
	
	
	
	
	
	
	return 0;
}
