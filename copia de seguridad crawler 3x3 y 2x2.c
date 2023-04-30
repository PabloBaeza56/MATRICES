#include <stdio.h>
#include <math.h>
#define F 2
#define C 3 //f+1


//variables reservadas para matrices 3*3 NO MOVER
#define CO 3 
#define FO 5



/* configuracion para 2*2
#define F 2
#define C 3 //f+1

*/
/* configuracion para 3*3
#define F 3
#define C 4 //f+1

*/
void leermatriz(double matriz_operable[F][C]){
	for (int i = 0; i < F ; i++){
		for (int f = 0; f < C; f++){
			scanf("%lf", &matriz_operable[i][f]);//filas y columnas
		}
	}
	
}
	
	void imprimirMatriz(double matriz_operable[FO][CO]){
		for (int i = 0; i < F; i++){
			for (int f = 0; f < F; f++){
				printf("%lf    ", matriz_operable[i][f]);//filas y columnas
			}
			puts("\n");
		}
	}
		
		
		double calcular_determinante_orden_dos_x_dos(double matriz_operable[F][C]){
			double determinante = matriz_operable[0][0] * matriz_operable[1][1] - matriz_operable[0][1] * matriz_operable[1][0];
			return determinante;
			
		}
			
			double obterner_incognitas_2_x_2(double matriz_operable[F][C], float determinante_maestro, int fila_a, int fila_b){
				double matriz_temporal[F][C];
				for (int i = 0; i < F; i++){
					matriz_temporal[i][0] = matriz_operable[i][fila_a];
					matriz_temporal[i][1] = matriz_operable[i][fila_b];
				}
				double res = calcular_determinante_orden_dos_x_dos(matriz_temporal) / (float)determinante_maestro;
				return res;
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
					return contador_total;
				}
					
					void copiar_filas(int fila_a_tomar, int fila_a_copiar, double matriz_operable[FO][CO]){
						for (int i = 0; i < CO; i++){
							matriz_operable[fila_a_copiar][i] = matriz_operable[fila_a_tomar][i]; 
						}
					}
						
						void restaurar_matriz(double matriz_operable[F][C], double matriz_operable_reducida[FO][CO]){
							//restaurar original
							for (int i = 0; i<F ; i++){
								for (int f = 0; f<C ; f++){
									matriz_operable_reducida[i][f] = matriz_operable[i][f];
								}
							}
							//----------------
							copiar_filas(0, 3,matriz_operable_reducida);
							copiar_filas(1, 4,matriz_operable_reducida);
							
						}
							
							double calcular_determinante_orden_cuatro_x_cuatro(double matriz_operable[FO][CO]){
								
								
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
								
								//printf("%f", resultado_final);
								return resultado_final;
							}
								
								void obtener_incognitas_3_X_3(double matriz_operable[F][C], double matriz_operable_reducida[FO][CO]){
									restaurar_matriz(matriz_operable, matriz_operable_reducida);
									
									
									float determinante_maestro = calcular_determinante_orden_tres_x_tres(matriz_operable_reducida);
									//printf("%f \n", determinante_maestro);
									
									for (int t = 0; t < CO; t++){
										restaurar_matriz(matriz_operable, matriz_operable_reducida);
										for (int i = 0; i<CO; i++){
											matriz_operable_reducida[i][t] = matriz_operable[i][3];
										}
										copiar_filas(0, 3,matriz_operable_reducida);
										copiar_filas(1, 4,matriz_operable_reducida);
										
										imprimirMatriz(matriz_operable_reducida);
										
										double determinante_res = (calcular_determinante_orden_tres_x_tres(matriz_operable_reducida)) /(float)determinante_maestro;
										printf("%f yyy\n", determinante_res);
										//poner en un arreglo para mostralo de forma mas adecuada
										
									}
									
								}
									
									void obtener_incognitas_4_X_4(double matriz_operable[F][C], double matriz_operable_reducida[FO][CO]){
										restaurar_matriz(matriz_operable, matriz_operable_reducida);
										
										
										float determinante_maestro = calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida);
										//printf("%f \n", determinante_maestro);
										
										for (int t = 0; t < CO; t++){
											restaurar_matriz(matriz_operable, matriz_operable_reducida);
											for (int i = 0; i<CO; i++){
												matriz_operable_reducida[i][t] = matriz_operable[i][4];
											}
											copiar_filas(0, 3,matriz_operable_reducida);
											copiar_filas(1, 4,matriz_operable_reducida);
											
											imprimirMatriz(matriz_operable_reducida);
											
											double determinante_res = (calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida)) /(float)determinante_maestro;
											printf("%f xxxx\n", determinante_res);
											//poner en un arreglo para mostralo de forma mas adecuada
											
										}
										
									}
										
										
										
										int main(int argc, char *argv[]) {
											double matriz_operable[F][C];
											double matriz_operable_reducida[FO][CO];
											
											leermatriz(matriz_operable);
											puts("\n");
											
											//obtener_incognitas_4_X_4(matriz_operable, matriz_operable_reducida);
											
											
											
											//obtener_incognitas_3_X_3(matriz_operable, matriz_operable_reducida);
											printf("%f  Y\n", obterner_incognitas_2_x_2(matriz_operable,determinante_maestro, 0 , 2));
											printf("%f  X\n", obterner_incognitas_2_x_2(matriz_operable,determinante_maestro, 2 , 1));
											
											
											
											
											
											
											return 0;
										}
										
