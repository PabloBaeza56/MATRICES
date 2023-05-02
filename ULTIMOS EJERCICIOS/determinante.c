#include <stdio.h>
#include <math.h>
#define C 4   //3
#define F 4  //5

/* NO MOVER*/
#define CO 3   
#define FO 5
/* CONFIGURACION 4*4
#define C 4   //3
#define F 4 
*/
void leermatriz(double matriz_operable[C][C]){
	for (int i = 0; i < C ; i++){
		for (int f = 0; f < C; f++){
			scanf("%lf", &matriz_operable[i][f]);//filas y columnas
		}
	}
	
}
	
void imprimirMatriz(double matriz_operable[C][F]){
	for (int i = 0; i < CO; i++){
		for (int f = 0; f < CO; f++){
			printf("%lf    ", matriz_operable[i][f]);//filas y columnas
		}
		puts("\n");
	}
}
	
void copiar_filas(int fila_a_tomar, int fila_a_copiar, double matriz_operable[FO][CO]){
	for (int i = 0; i < CO; i++){
		matriz_operable[fila_a_copiar][i] = matriz_operable[fila_a_tomar][i]; 
	}
}
	
double calcular_determinante_orden_tres_x_tres(double matriz_operable[FO][CO]){
	double contador_total = 0;
	
	
	//ida
	int inicio_fila_imaginario = 0;
	double contador = 0;
	for (int f = 0; f < CO; f++){
		double multiplicador = 1;
		for (int i = 0 ; i < CO; i++){
			multiplicador = multiplicador * matriz_operable[inicio_fila_imaginario][i];
			inicio_fila_imaginario++;
		}
		inicio_fila_imaginario = inicio_fila_imaginario - 2;
		contador = contador + multiplicador;
	}
	contador_total = contador_total + contador;
	
	
	
	//vuelta
	inicio_fila_imaginario = 0;
	contador = 0;
	for (int f = 0; f < CO; f++){
		double multiplicador = -1;
		for (int i = CO-1 ; i >= 0; i--){
			multiplicador = multiplicador * matriz_operable[inicio_fila_imaginario][i];
			inicio_fila_imaginario++;
		}
		inicio_fila_imaginario = inicio_fila_imaginario - 2;
		contador = contador + multiplicador;
	}
	contador_total = contador_total + contador;
	//printf("%f", contador_total);
	return contador_total;
}
	
	/*
#define C 4   //3
#define F 4   //5
	
#define CO 3   
#define FO 5
	*/
	
void calcular_determinante_orden_cuatro_x_cuatro(double matriz_operable[F][C]){
	
	
	double contador_total = 0;
	double resultado_final = 0;
	double matriz_temporal[FO][CO];
	
	
	for (int h = 0; h < C; h++){
		
		double valor_operable = matriz_operable[0][h];
		int indice_fila_real = 0;
		
		int indice_fila_importante = 1;
		int indice_columna_importante = h+1;
		int exponente_importante = indice_fila_importante + indice_columna_importante;
		
		
		for (int i = 1; i < F; i++){
			int indice_columna_real = -1;
			for (int j = 0; j < C; j++){
				if (j != h){
					indice_columna_real++;
					matriz_temporal[indice_fila_real][indice_columna_real] = matriz_operable[i][j];
				}
			}
			indice_fila_real++;
		}
		
		copiar_filas(0, 3,matriz_temporal);
		copiar_filas(1, 4,matriz_temporal);
		contador_total = calcular_determinante_orden_tres_x_tres(matriz_temporal);
		int primer_multiplicable = (pow(-1, exponente_importante));
		resultado_final = resultado_final + ( primer_multiplicable * valor_operable * contador_total );
	}
	
	printf("%f", resultado_final);
	
	
	
	
}

int main(int argc, char *argv[]) {
	double matriz_operable[F][C];
	
	
	leermatriz(matriz_operable);
	
	printf("%f", calcular_determinante_orden_tres_x_tres(matriz_operable));
	//calcular_determinante_orden_cuatro_x_cuatro(matriz_operable);
	return 0;
}

