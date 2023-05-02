#include <stdio.h>
#include <math.h>
#define F 4
#define C 5 //f+1


//variables reservadas para matrices 3*3
#define FOK 5
#define COK 3

/* configuracion para 4*4
#define F 4
#define C 5 //f+1
*/
/* configuracion para 2*2
#define F 2
#define C 3 //f+1

*/
/* configuracion para 3*3
#define F 3
#define C 4 //f+1

*/
void leermatriz(double matriz_operable[F][C]){
	/*for (int i = 0; i < F ; i++){
		for (int f = 0; f < C; f++){
			scanf("%lf", &matriz_operable[i][f]);//filas y columnas
		}
	}*/
	matriz_operable[0][0] = -1;
	matriz_operable[0][1] = 0;
	matriz_operable[0][2] = 2;
	matriz_operable[0][3] = 2;
	matriz_operable[0][4] = 1;
	
	
	matriz_operable[1][0] = 2;
	matriz_operable[1][1] = 0;
	matriz_operable[1][2] = -3;
	matriz_operable[1][3] = -3;
	matriz_operable[1][4] = 0;
	
	
	matriz_operable[2][0] = -1;
	matriz_operable[2][1] = 0;
	matriz_operable[2][2] = -3;
	matriz_operable[2][3] = 2;
	matriz_operable[2][4] = 0;
	
	
	matriz_operable[3][0] = -2;
	matriz_operable[3][1] = -1;
	matriz_operable[3][2] = 2;
	matriz_operable[3][3] = 1;
	matriz_operable[3][4] = 0;
	
}
	
void imprimirMatriz(double matriz_operable[F][C]){
	for (int i = 0; i < F; i++){
		for (int f = 0; f < C; f++){
			printf("%lf    ", matriz_operable[i][f]);//filas y columnas
		}
		puts("\n");
	}
}
	
	void imprimirMatriz_2(double matriz_operable[F][F]){
		for (int i = 0; i < F; i++){
			for (int f = 0; f < F; f++){
				printf("%lf    ", matriz_operable[i][f]);//filas y columnas
			}
			puts("\n");
		}
	}

	double calcular_determinante_orden_tres_x_tres(double matriz_operable[FOK][COK]){
		double contador_total = 0;
		
		
		//ida
		int inicio_fila_imaginario = 0;
		double contador = 0;
		for (int f = 0; f < COK; f++){
			double multiplicador = 1;
			for (int i = 0 ; i < COK; i++){
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
		for (int f = 0; f < COK; f++){
			double multiplicador = -1;
			for (int i = COK-1 ; i >= 0; i--){
				multiplicador = multiplicador * matriz_operable[inicio_fila_imaginario][i];
				inicio_fila_imaginario++;
			}
			inicio_fila_imaginario = inicio_fila_imaginario - 2;
			contador = contador + multiplicador;
		}
		contador_total = contador_total + contador;
		return contador_total;
	}

	void copiar_filas(int fila_a_tomar, int fila_a_copiar, double matriz_operable[FOK][COK]){
		for (int i = 0; i < COK; i++){
			matriz_operable[fila_a_copiar][i] = matriz_operable[fila_a_tomar][i]; 
		}
	}
	
	void restaurar_matriz(double matriz_operable[F][C], double matriz_operable_reducida[F][F]){
		
		for (int i = 0; i<F ; i++){
			for (int f = 0; f<F; f++){
				matriz_operable_reducida[i][f] = matriz_operable[i][f];
			}
		}
	}
	
	double calcular_determinante_orden_cuatro_x_cuatro(double matriz_operable[F][F]){
		
		double contador_total = 0;
		double resultado_final = 0;
		double matriz_temporal[FOK][COK];
	
		for (int h = 0; h < F; h++){
			
			double valor_operable = matriz_operable[0][h];
			int indice_fila_real = 0;
			
			int indice_fila_importante = 1;
			int indice_columna_importante = h+1;
			int exponente_importante = indice_fila_importante + indice_columna_importante;
			
			
			for (int i = 1; i < F; i++){
				int indice_columna_real = -1;
				for (int j = 0; j < F; j++){
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
		return resultado_final;
	}
	
	
	
	void obtener_incognitas_4_X_4(double matriz_operable[F][C], double matriz_operable_reducida[F][F]){
		for (int i = 0; i<F ; i++){
			for (int f = 0; f<F; f++){
				matriz_operable_reducida[i][f] = matriz_operable[i][f];
			}
		}
		float determinante_maestro = calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida);
		
		for (int t = 0; t < F; t++){
			for (int i = 0; i<F ; i++){
				for (int f = 0; f<F; f++){
					matriz_operable_reducida[i][f] = matriz_operable[i][f];
				}
			}
			
			imprimirMatriz_2(matriz_operable_reducida);
			
			for (int i = 0; i<F; i++){
				matriz_operable_reducida[i][t] = matriz_operable[i][F];
			}
			
			double determinante_res = (calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida)) /(float)determinante_maestro;
			printf("%f xxxx\n", determinante_res);
		}
	}
	


	
int main(int argc, char *argv[]) {
	double matriz_operable[F][C];
	double matriz_operable_reducida[F][F];
	
	leermatriz(matriz_operable);
	imprimirMatriz(matriz_operable);
	puts("\n");
	
	obtener_incognitas_4_X_4(matriz_operable, matriz_operable_reducida);
	
	
	

	
	
	
	
	
	
	return 0;
}

