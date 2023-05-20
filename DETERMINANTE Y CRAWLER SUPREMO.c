#include <stdio.h>
#include <math.h>
#define F 2
#define C 3 //f+1


//variables reservadas para matrices 3*3 NOOOOOOO MOVEEEERRR
#define FOK 5
#define COK 3

/* configuracion para 2*2
#define F 2
#define C 3 //f+1
*/

/* configuracion para 4*4
#define F 4
#define C 5 //f+1
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
        
        //CASOS DE PRUEBA 3*3
       /*
       matriz_operable[0][0] = 3;
        matriz_operable[0][1] = 4;
        matriz_operable[0][2] = -2;
        matriz_operable[0][3] = 0;

        matriz_operable[1][0] = 2;
        matriz_operable[1][1] = -3;
        matriz_operable[1][2] = 4;
        matriz_operable[1][3] = 11;


        matriz_operable[2][0] = 1;
        matriz_operable[2][1] = -2;
        matriz_operable[2][2] = 3;
        matriz_operable[2][3] = 7;
        */
        
         //CASOS DE PRUEBA 4*4
        /*
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
        */
    }
        
    void imprimirMatriz(double matriz_operable[F][C]){
        for (int i = 0; i < F; i++){
            for (int f = 0; f < C; f++){
                printf("%lf    ", matriz_operable[i][f]);//filas y columnas
            }
            puts("\n");
        }
    }
        

	double calcular_determinante_orden_tres_x_tres(double matriz_operable[FOK][COK]){
		double resultado_determinante = 0;
		
		
		/*  ida  \     */
		int fila_de_inicio = 0;
		double contador_ida = 0;

		for (int recorer_columnas_global = 0; recorer_columnas_global < COK; recorer_columnas_global++){
			double multiplicador = 1;
			for (int columna_recorrida = 0 ; columna_recorrida < COK; columna_recorrida++){
				multiplicador *= matriz_operable[fila_de_inicio][columna_recorrida];
				fila_de_inicio++;
			}
			fila_de_inicio = fila_de_inicio - 2;
			contador_ida += multiplicador;
		}
		resultado_determinante += contador_ida;
		
		
		/*  vuelta  /    */
		fila_de_inicio = 0;
		int contador_vuelta = 0;
		for (int recorer_columnas_global = 0; recorer_columnas_global < COK; recorer_columnas_global++){
			double multiplicador = -1;
			for (int columna_recorrida = COK-1 ; columna_recorrida >= 0; columna_recorrida--){
				multiplicador *= matriz_operable[fila_de_inicio][columna_recorrida];
				fila_de_inicio++;
			}
			fila_de_inicio = fila_de_inicio - 2;
			contador_vuelta += multiplicador;
		}
		resultado_determinante += contador_vuelta;


		return resultado_determinante;
	}

	void copiar_filas_rellenar_matriz_3_x_3(int fila_a_tomar, int fila_a_copiar, double matriz_operable[FOK][COK]){
		for (int i = 0; i < COK; i++){
			matriz_operable[fila_a_copiar][i] = matriz_operable[fila_a_tomar][i]; 
		}
	}
	

	double calcular_determinante_orden_cuatro_x_cuatro(double matriz_operable[F][F]){
		
		double matriz_temporal[FOK][COK];
		double resultado_final = 0;
		
	
		for (int indice_columna_global = 0; indice_columna_global < F; indice_columna_global++){

			int indice_fila = 0;
		
			//------- Esta seccion "recorta la matriz " para volverla  3 * 3---------------------- 
            // LA FILA 0 EN LA MATRIZ ES LA ANCLADA, LAS COLUMNAS SON LAS QUE ITERAN
			for (int indice_fila_limitada = 1; indice_fila_limitada < F; indice_fila_limitada++){
				int indice_columna = -1;
				for (int indice_columna_limitada = 0; indice_columna_limitada < F; indice_columna_limitada++){
					if (indice_columna_limitada != indice_columna_global){
						indice_columna++;
						matriz_temporal[indice_fila][indice_columna] = matriz_operable[indice_fila_limitada][indice_columna_limitada];
					}
				}
				indice_fila++;
			}
			copiar_filas_rellenar_matriz_3_x_3(0, 3,matriz_temporal);
			copiar_filas_rellenar_matriz_3_x_3(1, 4,matriz_temporal);
            //----------------------------------------------------------------
			
            

            int indice_fila_i = 1;
			int indice_columna_j = indice_columna_global + 1;
			int primer_valor_multiplicable = (pow(-1, indice_fila_i + indice_columna_j));

            double valor_a_trabajar_interseccion = matriz_operable[0][indice_columna_global];

            double determinante_orden_tres_x_tres = calcular_determinante_orden_tres_x_tres(matriz_temporal);

			resultado_final += ( primer_valor_multiplicable * valor_a_trabajar_interseccion * determinante_orden_tres_x_tres );
		}

		return resultado_final;
	}
	
   

    void copiar_filas_3_x_3(int fila_a_tomar, int fila_a_copiar, double matriz_operable[FOK][COK]){
		for (int i = 0; i < COK; i++){
			matriz_operable[fila_a_copiar][i] = matriz_operable[fila_a_tomar][i]; 
		}
	}

    void restaurar_matriz_3_x_3(double matriz_operable[F][C], double matriz_operable_reducida[FOK][COK]){
		//restaurar original
		for (int i = 0; i<F ; i++){
			for (int f = 0; f<F ; f++){
				matriz_operable_reducida[i][f] = matriz_operable[i][f];
			}
		}
	
        copiar_filas_3_x_3(0, 3,matriz_operable_reducida);
        copiar_filas_3_x_3(1, 4,matriz_operable_reducida);
							
	}

    //OK
    void sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4(double matriz_operable[F][C], double matriz_operable_reducida[F][F], int t){
        for (int i = 0; i<F; i++){
				matriz_operable_reducida[i][t] = matriz_operable[i][F];
		}
    }

   

    void obtener_incognitas_3_X_3(double matriz_operable[3][4]){
        double matriz_operable_reducida[5][3];
        restaurar_matriz_3_x_3( matriz_operable, matriz_operable_reducida);

        float determinante_3_x_3_matriz_original = calcular_determinante_orden_tres_x_tres(matriz_operable_reducida);

        for (int t = 0; t < 3; t++){
            restaurar_matriz_3_x_3( matriz_operable, matriz_operable_reducida);
            
           
            sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4( matriz_operable, matriz_operable_reducida, t);
            
            copiar_filas_3_x_3(0, 3, matriz_operable_reducida);
            copiar_filas_3_x_3(1, 4, matriz_operable_reducida);

            //imprimirMatriz(matriz_operable_reducida);

            double determinante_res = (calcular_determinante_orden_tres_x_tres(matriz_operable_reducida)) / (float)determinante_3_x_3_matriz_original;
            printf("%f yyy\n", determinante_res);
        }
    }
    
	void copiar_datos_para_otra_matriz_4_x_4(double matriz_operable[F][C], double matriz_operable_reducida[F][F]){
        for (int i = 0; i<F ; i++){
			for (int f = 0; f<F; f++){
				matriz_operable_reducida[i][f] = matriz_operable[i][f];
			}
		}
    }

    
	void obtener_incognitas_4_X_4(double matriz_operable[F][C]){
        double matriz_operable_reducida[F][F];
       
        copiar_datos_para_otra_matriz_4_x_4(matriz_operable,matriz_operable_reducida);
        
		float determinante_4_x_4_matriz_original = calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida);
		
		for (int numero_columna = 0; numero_columna < F; numero_columna++){
            
            copiar_datos_para_otra_matriz_4_x_4(matriz_operable,matriz_operable_reducida);
			
			//imprimirMatriz_2(matriz_operable_reducida);
			sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4( matriz_operable, matriz_operable_reducida, numero_columna);
			
			
			double resultado_incognita = (calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida)) /(float)determinante_4_x_4_matriz_original;
			printf("%f xxxx \n", resultado_incognita);
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

    void simplificacion_obtener_incognitas_2_x_2(double matriz_operable[F][C]){
        double determinante_maestro = calcular_determinante_orden_dos_x_dos(matriz_operable);
        printf("%f  X\n", obterner_incognitas_2_x_2(matriz_operable,determinante_maestro, 2 , 1));
        printf("%f  Y\n", obterner_incognitas_2_x_2(matriz_operable,determinante_maestro, 0 , 2));
	    
    }
	
int main() {
	double matriz_operable[F][C];
	
	
	leermatriz(matriz_operable);
	imprimirMatriz(matriz_operable);
	puts("\n");
	//obtener_incognitas_4_X_4(matriz_operable);
	//obtener_incognitas_3_X_3(matriz_operable);
    //simplificacion_obtener_incognitas_2_x_2(matriz_operable);


    //SE DEBE ADECUAR LOS VALORES F Y C A LA DIMENSION DE LAS MATRICES
    // EJEMPLO ORDEN 3 X 3  F = 3 y C =3
    // EJEMPLO ORDEN 4 X 4  F = 4 y C =4
    /*
    calcular_determinante_orden_dos_x_dos(matriz_operable);
    calcular_determinante_orden_tres_x_tres(matriz_operable);
	calcular_determinante_orden_cuatro_x_cuatro(matriz_operable);
    */
    
	return 0;
}
