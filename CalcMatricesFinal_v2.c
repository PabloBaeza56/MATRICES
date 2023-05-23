#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct dimensiones{
	int filas;
	int columnas;
};
typedef struct dimensiones dimensiones;

dimensiones leerDimensiones();
dimensiones leerDimensionesCuadradas();
float **inicializarMatriz(dimensiones);
void liberarMemoria(float**, dimensiones);
void leerMatriz(float**, dimensiones);
void imprimirMatriz(float**, dimensiones);
void imprimirMatrizCramer(double**, dimensiones);
void liberarMemoriaDouble(double**, dimensiones);

void matrizTranspuesta();
void sumarMatrices();
void multiplicacionEscalar();
void multiplicacionMatrices();

void inversaGaussJordan();
void leerMatrizGaussJordan(float**, dimensiones);
float validacionDeterminante(float**, dimensiones);
void operar_matriz_con_pivotes(float**, int, int, float, dimensiones);
void operar_matriz_estocada_final(float**, int, float, dimensiones);
void imprimirMatriz_matraca_desendente(float**, dimensiones);
void imprimirMatriz_matraca_asendente(float**, dimensiones);
void corregir_0_negativo(float**, dimensiones);
void redondeo_milesimal(float**, dimensiones);

float determiannte_2x2(float**, dimensiones);
float determinante_3x3(float**, dimensiones);
float determinante_4x4(float**, dimensiones);
void restaurarMatriz_3x3(float**, dimensiones, float**, dimensiones);
void copiarFilas_3x3(int fila_a_tomar, int fila_a_copiar, float**, dimensiones);

void sistemaEcuacionesGaussJordan();
void imprimirEcuacionGaussJordan(float**, dimensiones);
void leerEcuacionesGaussJordan(float**, dimensiones);

void calcularDeterminante();
void leerMatrizCramer(double**, dimensiones);

void sistemaEcuacionesCramer();
double** inicializarMatrizCramer(dimensiones);
void leerEcuacionCramer(double**, dimensiones);
void imprimirEcuacionCramer(double**, dimensiones);
double calcular_determinante_orden_tres_x_tres(double**, dimensiones); //Matriz FOK/COK
void copiar_filas_rellenar_matriz_3_x_3(int fila_a_tomar, int fila_a_copiar, double**, dimensiones); //Matriz FOK/COK
double calcular_determinante_orden_cuatro_x_cuatro(double**, dimensiones); //Matriz F/F
void copiar_filas_3_x_3(int fila_a_tomar, int fila_a_copiar, double**, dimensiones); //Matriz FOK/COK
void restaurar_matriz_3_x_3(double**, dimensiones, double**, dimensiones); //Matriz F/C, Matriz FOK/COK
void sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4(double**, dimensiones, double**, dimensiones, int t); //Matriz F/C, Matriz F/F
void obtener_incognitas_3_X_3(double**, dimensiones); //Matriz F/C
void copiar_datos_para_otra_matriz_4_x_4(double**, dimensiones, double**, dimensiones); //Matriz F/C, Matriz F/F
void obtener_incognitas_4_X_4(double**, dimensiones); //Matriz F/C
double calcular_determinante_orden_dos_x_dos(double**, dimensiones); //Matriz F/C
double obterner_incognitas_2_x_2(double**, dimensiones, float determinante_maestro, int fila_a, int fila_b); //Matriz F/C
void simplificacion_obtener_incognitas_2_x_2(double**, dimensiones); //Matriz F/C

int main(int argc, char *argv[]) {
	int opcion;
	char continuar;
	
	do{
		puts("\n");
		puts("Biblioteca de Operaciones con Matrices\n");
		
		puts("\n");
		
		puts("1. Suma de Matrices\n");
		puts("2. Multiplicacion de Matrices por una Escalar\n");
		puts("3. Multiplicacion de Matrices\n");
		puts("4. Obtencion de Transpuesta de una Matriz\n");
		puts("5. Obtencion de la Inversa de una Matriz por Gauss-Jordan\n");
		puts("6. Solucion de Sistema de Ecuaciones por Gauss-Jordan\n");
		puts("7. Calculo de Determinante de una Matriz\n");
		puts("8. Solucion de Sistema de Ecuaciones por Cramer");
		
		puts("\n");
		
		puts("Ingrese una opcion");
		scanf("%d", &opcion);
		system("cls"); 
		
		switch(opcion){
		case 1:
			sumarMatrices();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 2:
			multiplicacionEscalar();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 3:
			multiplicacionMatrices();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 4:
			matrizTranspuesta();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 5:
			inversaGaussJordan();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 6:
			sistemaEcuacionesGaussJordan();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		case 7:
			calcularDeterminante();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls");
			break;
		case 8:
			sistemaEcuacionesCramer();
			puts("Desea realizar otra operacion? (y/n)");
			scanf("%c", &continuar);
			system("cls"); 
			break;
		}
	} while(continuar!='n');
	
	puts("Creado por:\n");
	puts("Pablo Baeza\n");
	puts("Mariana Caballero\n");
	puts("Ian Rodriguez");
	
	return 0;
}
dimensiones leerDimensiones(){
	dimensiones medidas;
	int filas, col;
	do{
		puts("Filas:");
		while (scanf("%d",&filas)!=1||getchar()!='\n'){
			printf("Entrada invalida. Ingrese un numero: ");
			fflush(stdin);
		}
		medidas.filas=filas;
		puts("Columnas:");
		while (scanf("%d",&col)!=1||getchar()!='\n'){
			printf("Entrada invalida. Ingrese un numero: ");
			fflush(stdin);
		}
		medidas.columnas=col;
		if(medidas.filas<1 || medidas.columnas<1){
			puts("Entrada/s invalida. Ingrese numeros positivo:");
		}
	} while(medidas.filas<1 || medidas.columnas<1);
	
	return medidas;
}
dimensiones leerDimensionesCuadradas(){
	dimensiones medidas;
	int num;
	
	do{
		puts("Inserte el numero de filas/columnas o variables:");
		while (scanf("%d",&num)!=1||getchar()!='\n'){
			printf("Entrada invalida. Ingrese un numero: ");
			fflush(stdin);
		}
		medidas.filas=num;
		medidas.columnas=num;
		if(medidas.filas<1 || medidas.columnas<1){
			puts("Entrada/s invalida. Ingrese numeros positivo:");
		}
	} while(medidas.filas<1 || medidas.columnas<1);
	
	return medidas;
}
float **inicializarMatriz(dimensiones medidas){
	float **matriz;
	
	matriz=(float**)malloc(medidas.filas*sizeof(float*));
	for(int i=0; i<medidas.filas; i++){
		matriz[i]=(float*)malloc(medidas.columnas*sizeof(float));
	}
	
	return matriz;
}
void liberarMemoria(float **matriz, dimensiones medidas){
	for (int i=0; i<medidas.filas; i++) {
		free(matriz[i]);
	}
	free(matriz);
	
	return;
}
void leerMatriz(float **matriz, dimensiones medidas){
	float num;
	int i, j;
	
	for(i=0; i<medidas.filas; i++){
		for(j=0; j<medidas.columnas; j++){
			matriz[i][j]=0;
		}
	}
	
	for(i=0; i<medidas.filas; i++){
		for (j=0;j<medidas.columnas; j++){
			printf("\nIngrese el valor [%d][%d]: ", i, j);
			while (scanf("%f",&num)!=1||getchar()!='\n'){
				printf("Entrada invalida. Ingrese un numero: ");
				fflush(stdin);
			}
			matriz[i][j]=num;
			for(int a=0; a<medidas.filas; a++){
				for(int b=0; b<medidas.columnas; b++){
					printf("%.2f    ", matriz[a][b]);
				}
				puts("\n");
			}
		}
	}
	
	return;
}
void leerMatrizGaussJordan(float **matriz, dimensiones medidas){
	float num;
	
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			matriz[i][j]=0;
		}
	}
	
	for(int i=0; i<medidas.filas; i++){
		for (int j=0;j<medidas.filas; j++){
			printf("\nIngrese el valor [%d][%d]: ", i, j);
			while (scanf("%f",&num)!=1||getchar()!='\n'){
				printf("Entrada invalida. Ingrese un numero: ");
				fflush(stdin);
			}
			matriz[i][j]=num;
			for(int a=0; a<medidas.filas; a++){
				for(int b=0; b<medidas.filas; b++){
					printf("%.2f    ", matriz[a][b]);
				}
				puts("\n");
			}
		}
	}
	
	int fila_de_arranque = 0;
	int columna_de_arranque = medidas.filas;
	
	for (int i = 0; i< medidas.filas; i++){
		for (int f = medidas.filas; f<medidas.columnas; f++){
			
			if ((i == fila_de_arranque) && (f == columna_de_arranque)){
				matriz[i][f] = 1;
			} else {
				matriz[i][f] = 0;
			}
		}
		fila_de_arranque++;
		columna_de_arranque++;
	}
	
	return;
}
void imprimirMatriz(float **matriz, dimensiones medidas){

	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			printf("%.2f    ", matriz[i][j]);
		}
		puts("\n");
	}
	
	return;
}
void imprimirMatrizCramer(double** matriz, dimensiones medidas){
	
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			printf("%.2f    ", matriz[i][j]);
		}
		puts("\n");
	}
	
}
void matrizTranspuesta(){
	float **transpuesta, **matriz;
	dimensiones medidasEntrada, medidasTranspuesta;
	
	puts("Transpuesta de una Matriz\n");
	
	medidasEntrada=leerDimensiones();
	matriz=inicializarMatriz(medidasEntrada);
	
	puts("\n");
	
	leerMatriz(matriz, medidasEntrada);
	puts("\n");
	imprimirMatriz(matriz, medidasEntrada);
	
	puts("\n");
	
	medidasTranspuesta.filas=medidasEntrada.columnas;
	medidasTranspuesta.columnas=medidasEntrada.filas;
	transpuesta=inicializarMatriz(medidasTranspuesta);
	
	for(int i=0; i<medidasTranspuesta.filas; i++){
		for(int j=0; j<medidasTranspuesta.columnas; j++){
			transpuesta[i][j]=matriz[j][i];
		}
	}
	
	puts("Matriz Transpuesta\n");
	imprimirMatriz(transpuesta, medidasTranspuesta);
	
	liberarMemoria(transpuesta, medidasTranspuesta);
	liberarMemoria(matriz, medidasEntrada);
	
	return;
}
void sumarMatrices(){
	float **matrizA, **matrizB, **matrizC;
	dimensiones medidas;
	
	puts("Suma de Matrices\n");
	
	medidas=leerDimensiones();
	
	puts("\n");
	
	puts("Matriz A");
	matrizA=inicializarMatriz(medidas);
	leerMatriz(matrizA, medidas);
	puts("\n");
	puts("Matriz B");
	matrizB=inicializarMatriz(medidas);
	leerMatriz(matrizB, medidas);
	
	puts("\n");
	
	puts("Matriz A");
	imprimirMatriz(matrizA, medidas);
	puts("\n");
	puts("Matriz B");
	imprimirMatriz(matrizB, medidas);
	
	matrizC=inicializarMatriz(medidas);
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			matrizC[i][j]=matrizA[i][j]+matrizB[i][j];
		}
	}
	
	puts("\n");
	
	puts("Resultado");
	imprimirMatriz(matrizC, medidas);
	
	liberarMemoria(matrizA, medidas);
	liberarMemoria(matrizB, medidas);
	liberarMemoria(matrizC, medidas);
	
	return;
}
void multiplicacionEscalar(){
	float **matriz, **matrizProducto, escalar;
	dimensiones medidas;
	
	puts("Multiplicacion por una Escalar\n");
	
	medidas=leerDimensiones();
	matriz=inicializarMatriz(medidas);
	matrizProducto=inicializarMatriz(medidas);
	
	puts("\n");
	
	leerMatriz(matriz, medidas);
	puts("\n");
	imprimirMatriz(matriz, medidas);
	
	puts("\n");
	
	puts("Ingrese el valor de la escalar");
	scanf("%f", &escalar);
	
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			matrizProducto[i][j]=matriz[i][j]*escalar;
		}
	}
	
	puts("\n");
	
	puts("Resultado");
	imprimirMatriz(matrizProducto, medidas);
	
	liberarMemoria(matriz, medidas);
	liberarMemoria(matrizProducto, medidas);
	
	return;
}
void multiplicacionMatrices(){
	float **matrizA, **matrizB, **matrizC, sumaProductos=0;
	dimensiones medidasA, medidasB, medidasC;
	
	puts("Multiplicacion de Matrices\n");
	
	puts("\n");
	
	do{
		puts("Matriz A");
		medidasA=leerDimensiones();
		puts("\n");
		puts("Matriz B");
		medidasB=leerDimensiones();
		if(medidasA.columnas!=medidasB.filas){
			puts("Las columnas de matriz A deben ser iguales a las filas de matriz B");
		}
	} while(medidasA.columnas!=medidasB.filas);
	
	matrizA=inicializarMatriz(medidasA);
	matrizB=inicializarMatriz(medidasB);
	
	puts("\n");
	
	puts("Matriz A");
	leerMatriz(matrizA, medidasA);
	puts("\n");
	puts("matriz B");
	leerMatriz(matrizB, medidasB);
	
	puts("\n");
	
	puts("Matriz A");
	imprimirMatriz(matrizA, medidasA);
	puts("\n");
	puts("Matriz B");
	imprimirMatriz(matrizB, medidasB);
	
	puts("\n");
	
	//matriz C
	medidasC.filas=medidasA.filas;
	medidasC.columnas=medidasB.columnas;
	matrizC=inicializarMatriz(medidasC);
	
	for(int i=0; i<medidasA.filas; i++){
		for(int j=0; j<medidasB.columnas; j++){
			for(int n=0; n<medidasA.columnas; n++){
				sumaProductos+=matrizA[i][n]*matrizB[n][j];
			}
			matrizC[i][j]=sumaProductos;
			sumaProductos=0;
		}
	}
	
	puts("Resultado");
	imprimirMatriz(matrizC, medidasC);
	
	liberarMemoria(matrizA, medidasA);
	liberarMemoria(matrizB, medidasB);
	liberarMemoria(matrizC, medidasC);
	
	return;
}	

void inversaGaussJordan(){
	float **matriz;
	dimensiones medidas;
	float determinante;
	
	puts("Inversa de una Matriz por Gauss Jordan\n");
	
	medidas=leerDimensionesCuadradas();
	while(medidas.filas==1 || medidas.filas>4){
		if(medidas.filas==1){
			puts("Tamaño minimo es de 2");
		}
		if(medidas.filas>4){
			puts("Tamaño maximo es de 4");
		}
		medidas=leerDimensionesCuadradas();
	}
	medidas.columnas=medidas.filas*2;
	
	puts("\n");
	
	matriz=inicializarMatriz(medidas);
	leerMatrizGaussJordan(matriz, medidas);
	
	puts("\n");
	
	determinante = validacionDeterminante(matriz, medidas);
	if(determinante == 0){
		puts("Determinante de matriz: 0. La matriz ingresada no tiene inversa");
	}else{
		puts("Matriz aumentada");
		imprimirMatriz(matriz, medidas);
		
		puts("\n");
		
		imprimirMatriz_matraca_desendente(matriz, medidas);
		imprimirMatriz_matraca_asendente(matriz, medidas);
		redondeo_milesimal(matriz, medidas);
		corregir_0_negativo(matriz, medidas);
		puts("\n");
		puts("Inversa de matriz");
		imprimirMatriz(matriz, medidas);
	}
	
	liberarMemoria(matriz, medidas);
	
	return;
}
void imprimirMatriz_matraca_desendente(float **matriz, dimensiones medidas){
	int fila = 0;
	int col = 0;
	int contador_identidad = 0;
	
	while (fila < medidas.filas){
		while (col < medidas.filas){
			
			if (fila == col){
				float res = 1 / matriz[fila][col];
				printf("Convertir [%d][%d] = %.2f a 1\n", fila, col, matriz[fila][col]);
				operar_matriz_estocada_final(matriz, fila, res, medidas);
				printf("Multiplicamos %.2f por fila[%d]\n", res, fila);
				imprimirMatriz(matriz, medidas);
				puts("\n");
			}else{
				float res = (matriz[col][fila]) * -1;
				printf("Convertir [%d][%d] = %.2f a 0\n", col, fila, matriz[col][fila]);
				operar_matriz_con_pivotes(matriz, fila, col, res, medidas);
				printf("Multiplicamos %.2f por fila[%d] y sumamos a fila[%d]\n", res, fila, col);
				imprimirMatriz(matriz, medidas);
				puts("\n");
			}
			
			if (col == medidas.filas - 1){
				contador_identidad++;
				
				col = contador_identidad;
				fila = contador_identidad;
				continue;
			}
			col++;
		}
		fila++;
	}
	
	return;
}
void imprimirMatriz_matraca_asendente(float **matriz, dimensiones medidas){
	int fila = medidas.filas - 2; 
	int col = medidas.filas - 1;  
	int setear_fila = fila;
	int setear_columna = col;
	
	for (int f = 0; f < medidas.columnas; f++){
		for (int i = 0; i < col; i++){
			if (fila != col){
				float res = (matriz[fila][col]) * -1;
				printf("Convertir [%d][%d] = %.2f a 0\n", fila, col, matriz[fila][col]);
				operar_matriz_con_pivotes(matriz, col, fila, res, medidas);
				printf("Multiplicamos %.2f por fila[%d] y sumamos a fila[%d]\n", res, col, fila);
				imprimirMatriz(matriz, medidas);
				puts("\n");
			}
			fila--;
		}
		setear_fila--;	  
		setear_columna--; 
		
		fila = setear_fila;
		col = setear_columna;
	}
	
	return;
}
void corregir_0_negativo(float **matriz, dimensiones medidas){
	
	for (int i = 0; i < medidas.filas; i++){
		for (int f = 0; f < medidas.filas; f++){
			int res = floor(matriz[i][f]);
			if (res <= -0){
				matriz[i][f] = 0;
			}
		}
	}
	
	return;
}
void redondeo_milesimal(float **matriz, dimensiones medidas){
	int fila_de_arranque = 0;
	int columna_de_arranque = 3;
	
	for (int i = 0; i< medidas.filas; i++){
		for (int f = medidas.filas; f<medidas.columnas; f++){
			
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
	
	return;
}
void operar_matriz_con_pivotes(float **matriz, int fila_a_trabajar, int fila_posicion_actual, float valor_a_operar, dimensiones medidas){
	float **matriz_temporal_operaciones;
	matriz_temporal_operaciones=inicializarMatriz(medidas);
	
	for (int col = 0; col < medidas.columnas; col++){
		// asignar valores a la matriz temporal
		matriz_temporal_operaciones[fila_a_trabajar][col] = matriz[fila_a_trabajar][col];
		matriz_temporal_operaciones[fila_posicion_actual][col] = matriz[fila_posicion_actual][col];
		// realizar la operacion deseada
		matriz_temporal_operaciones[fila_a_trabajar][col] = matriz_temporal_operaciones[fila_a_trabajar][col] * valor_a_operar;
		// reasignar datos en la matriz oficial
		matriz[fila_posicion_actual][col] = matriz_temporal_operaciones[fila_posicion_actual][col] + matriz_temporal_operaciones[fila_a_trabajar][col];
	}
	
	
	liberarMemoria(matriz_temporal_operaciones, medidas);
	
	return;
}
void operar_matriz_estocada_final(float **matriz, int fila_posicion_actual, float valor_a_operar, dimensiones medidas){
	
	for (int col = 0; col < medidas.columnas; col++){
		matriz[fila_posicion_actual][col] = matriz[fila_posicion_actual][col] * valor_a_operar;
	}
	
	return;
}
void sistemaEcuacionesCramer(){
	double **matriz;
	dimensiones medidas;
	
	puts("Sistema de Ecuaciones por Cramer\n");
	
	medidas=leerDimensionesCuadradas();
	while(medidas.filas==1 || medidas.filas>4){
		if(medidas.filas==1){
			puts("Tamaño minimo es de 2");
		}
		if(medidas.filas>4){
			puts("Tamaño maximo es de 4");
		}
		medidas=leerDimensionesCuadradas();
	}
	medidas.columnas++;
	
	puts("\n");
	
	matriz=inicializarMatrizCramer(medidas);
	leerEcuacionCramer(matriz, medidas);
	puts("\n");
	imprimirEcuacionCramer(matriz, medidas);
	
	switch(medidas.filas){
	case 2:
		simplificacion_obtener_incognitas_2_x_2(matriz, medidas);
		break;
	case 3:
		obtener_incognitas_3_X_3(matriz, medidas);
		break;
	case 4:
		obtener_incognitas_4_X_4(matriz, medidas);
		break;
	}
	
	liberarMemoriaDouble(matriz, medidas);
	
}
double** inicializarMatrizCramer(dimensiones medidas){
	double **matriz;
	
	matriz=(double**)malloc(medidas.filas*sizeof(double*));
	for(int i=0; i<medidas.filas; i++){
		matriz[i]=(double*)malloc(medidas.columnas*sizeof(double));
	}
	
	return matriz;
}
void leerEcuacionCramer(double** matriz, dimensiones medidas){
	float num;
	int i, j;
	
	for(i=0; i<medidas.filas; i++){
		for(j=0; j<medidas.columnas; j++){
			matriz[i][j]=0;
		}
	}
	
	for(i=0; i<medidas.filas; i++){
		for (j=0;j<medidas.columnas; j++){
			if(j==medidas.columnas-1){
				printf("Ingrese el resultado de la ecuacion %d: ", i+1);
				while (scanf("%f",&num)!=1||getchar()!='\n'){
					printf("Entrada invalida. Ingrese un numero: ");
					fflush(stdin);
				}
			}else{
				printf("\nIngrese el coeficiente de %c, de la ecuacion %d: ", 87+j, i+1);
				while (scanf("%f",&num)!=1||getchar()!='\n'){
					printf("Entrada invalida. Ingrese un numero: ");
					fflush(stdin);
				}
			}
			matriz[i][j]=num;
			for(int a=0; a<medidas.filas; a++){
				for(int b=0; b<medidas.columnas; b++){
					printf("%.2f    ", matriz[a][b]);
				}
				puts("\n");
			}
		}
	}
	
	return;
	
}
void imprimirEcuacionCramer(double** matriz, dimensiones medidas){
	
	puts("El sistema de ecuaciones se veria de la siguiente forma:");
	puts("\n");
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			if(j==medidas.columnas-1){
				printf("%.2f", matriz[i][j]); 
			}else{
				if(j==medidas.columnas-2){
					printf("%.2f %c = ", matriz[i][j], 87+j);
				}else{
					printf("%.2f %c + ", matriz[i][j], 87+j);
				}
			}
		}
		puts("\n");
	}
	
	return;
}
void simplificacion_obtener_incognitas_2_x_2(double** matriz, dimensiones medidas){
	puts("\nDeterminante Principal\n");
	double determinante_maestro = calcular_determinante_orden_dos_x_dos(matriz, medidas);
	if(determinante_maestro==0){
		puts("\nDeterminante principal: 0. La ecuacion no tiene solucion\n");
	}else{
		printf("%f  w\n", obterner_incognitas_2_x_2(matriz, medidas, determinante_maestro, 2 , 1));
		puts("\nPresiones enter para continuar\n");
		char continuar=getchar();
		printf("%f  x\n", obterner_incognitas_2_x_2(matriz, medidas, determinante_maestro, 0 , 2));
	}
}
double calcular_determinante_orden_dos_x_dos(double** matriz, dimensiones medidas){
	double determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	puts("[0][0] * [1][1] - [0][1] * [1][0] =");
	printf("%.2lf * %.2lf - %.2lf * %.2lf = %.2lf\n", matriz[0][0], matriz[1][1], matriz[0][1], matriz[1][0], determinante);
	puts("\n");
	return determinante;	
}
double obterner_incognitas_2_x_2(double** matriz, dimensiones medidas, float determinante_maestro, int fila_a, int fila_b){
	double** matriz_temporal;
	matriz_temporal=inicializarMatrizCramer(medidas);
	
	for (int i = 0; i < medidas.filas; i++){
		matriz_temporal[i][0] = matriz[i][fila_a];
		matriz_temporal[i][1] = matriz[i][fila_b];
	}
	
	puts("\nSustitucion de matriz\n");
	imprimirMatrizCramer(matriz_temporal, medidas);
	
	puts("\nDeterminante de matriz\n");
	double determinante2x2 = calcular_determinante_orden_dos_x_dos(matriz_temporal, medidas);
	double res = determinante2x2 / (float)determinante_maestro;
	printf("\n%.2lf / %.2f = %.2lf\n", determinante2x2, (float)determinante_maestro, res);
	
	liberarMemoriaDouble(matriz_temporal, medidas);
	
	return res;
}
void obtener_incognitas_3_X_3(double** matriz, dimensiones medidas){
	dimensiones medidasReducidas;
	medidasReducidas.filas=5;
	medidasReducidas.columnas=3;
	
	dimensiones medidasOriginales;
	medidasOriginales.filas=3;
	medidasOriginales.columnas=3;
	
	double** matriz_operable_reducida;
	matriz_operable_reducida=inicializarMatrizCramer(medidasReducidas);
	
	restaurar_matriz_3_x_3(matriz, medidas, matriz_operable_reducida, medidasReducidas);
	
	puts("\nDeterminante Principal\n");
	float determinante_3_x_3_matriz_original = calcular_determinante_orden_tres_x_tres(matriz_operable_reducida, medidasReducidas);
	if(determinante_3_x_3_matriz_original==0){
		puts("\nDeterminante principal: 0. La ecuacion no tiene solucion\n");
	}else{
		int j=0;
		for (int t = 0; t < 3; t++){
			restaurar_matriz_3_x_3(matriz, medidas, matriz_operable_reducida, medidasReducidas);
			
			
			sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4(matriz, medidas, matriz_operable_reducida, medidasReducidas, t);
			
			copiar_filas_3_x_3(0, 3, matriz_operable_reducida, medidasReducidas);
			copiar_filas_3_x_3(1, 4, matriz_operable_reducida, medidasReducidas);
			
			//imprimirMatrizCramer(matriz_operable_reducida, medidasReducidas);
			
			puts("\nSustitucion de matriz\n");
			imprimirMatrizCramer(matriz_operable_reducida, medidasOriginales);
			puts("\n");
			puts("\nDeterminante de matriz\n");
			double determinante3x3 = calcular_determinante_orden_tres_x_tres(matriz_operable_reducida, medidasReducidas);
			double determinante_res = determinante3x3 / (float)determinante_3_x_3_matriz_original;
			printf("\n%.2lf / %.2f = %.2lf\n", determinante3x3, (float)determinante_3_x_3_matriz_original, determinante_res);
			printf("%f %c\n", determinante_res, 87+j);
			j++;
			puts("\nPresiones enter para continuar\n");
			char continuar=getchar();
		}
	}
	
}
void restaurar_matriz_3_x_3(double** matriz, dimensiones medidas, double** matriz_operable_reducida, dimensiones medidasReducidas){
	//restaurar original
	for (int i = 0; i<medidas.filas ; i++){
		for (int f = 0; f<medidas.filas ; f++){
			matriz_operable_reducida[i][f] = matriz[i][f];
		}
	}
	
	copiar_filas_3_x_3(0, 3, matriz_operable_reducida, medidasReducidas);
	copiar_filas_3_x_3(1, 4, matriz_operable_reducida, medidasReducidas);
}
void copiar_filas_3_x_3(int fila_a_tomar, int fila_a_copiar, double** matriz, dimensiones medidasReducidas){
	for (int i = 0; i < medidasReducidas.columnas; i++){
		matriz[fila_a_copiar][i] = matriz[fila_a_tomar][i]; 
	}
}
double calcular_determinante_orden_tres_x_tres(double** matriz, dimensiones medidasReducidas){
	double resultado_determinante = 0;
	
	puts("\nMatriz Aumentada\n");
	imprimirMatrizCramer(matriz, medidasReducidas);
	puts("\n");
	
	/*  ida  \     */
	int fila_de_inicio = 0;
	double contador_ida = 0;
	
	puts("Regla de Sarrus\n");
	puts("[1][1]*[2][2]*[3][3] + [2][1]*[3][2]*[1][3] + [3][1]*[1][2]*[2][3] - [3][1]*[2][2]*[1][3] - [1][1]*[3][2]*[2][3] - [2][1]*[1][2]*[3][3]\n");
	
	for (int recorer_columnas_global = 0; recorer_columnas_global < medidasReducidas.columnas; recorer_columnas_global++){
		double multiplicador = 1;
		for (int columna_recorrida = 0 ; columna_recorrida < medidasReducidas.columnas; columna_recorrida++){
			printf("(%.2lf) \t", matriz[fila_de_inicio][columna_recorrida]);
			multiplicador *= matriz[fila_de_inicio][columna_recorrida];
			fila_de_inicio++;
		}
		printf("= %.2lf\n", multiplicador);
		fila_de_inicio = fila_de_inicio - 2;
		printf("%.2lf + (%.2lf)\t", contador_ida, multiplicador);
		contador_ida += multiplicador;
		printf("= %.2lf\n", contador_ida);
		puts("\n");
	}
	resultado_determinante += contador_ida;
	
	
	/*  vuelta  /    */
	fila_de_inicio = 0;
	double contador_vuelta = 0;
	for (int recorer_columnas_global = 0; recorer_columnas_global < medidasReducidas.columnas; recorer_columnas_global++){
		double multiplicador = -1;
		for (int columna_recorrida = medidasReducidas.columnas-1 ; columna_recorrida >= 0; columna_recorrida--){
			printf("(%.2lf) \t", matriz[fila_de_inicio][columna_recorrida]);
			multiplicador *= matriz[fila_de_inicio][columna_recorrida];
			fila_de_inicio++;
		}
		printf("= %.2lf\n", multiplicador * -1);
		fila_de_inicio = fila_de_inicio - 2;
		printf("%.2lf - (%.2lf)\t", contador_vuelta, multiplicador * -1);
		contador_vuelta += multiplicador;
		printf("= %.2lf\n", contador_vuelta);
		puts("\n");
	}
	
	resultado_determinante += contador_vuelta;
	
	printf("%.2lf + (%.2lf) = %.2lf\n", contador_ida, contador_vuelta, resultado_determinante);
	
	return resultado_determinante;
}
	
void copiar_filas_rellenar_matriz_3_x_3(int fila_a_tomar, int fila_a_copiar, double** matriz, dimensiones medidasReducidas){
	for (int i = 0; i < medidasReducidas.columnas; i++){
		matriz[fila_a_copiar][i] = matriz[fila_a_tomar][i]; 
	}
}
void sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4(double** matriz, dimensiones medidas, double** matriz_operable_reducida, dimensiones medidasReducidas, int t){
	for (int i = 0; i<medidas.filas; i++){
		matriz_operable_reducida[i][t] = matriz[i][medidas.filas];
	}
}
void obtener_incognitas_4_X_4(double** matriz, dimensiones medidas){
	
	dimensiones medidasReducidas;
	medidasReducidas.filas=medidas.filas;
	medidasReducidas.columnas=medidas.filas;
	
	dimensiones medidasOriginales;
	medidasOriginales.filas=4;
	medidasOriginales.columnas=4;
	
	double** matriz_operable_reducida;
	matriz_operable_reducida=inicializarMatrizCramer(medidasReducidas);
	
	copiar_datos_para_otra_matriz_4_x_4(matriz, medidas, matriz_operable_reducida, medidasReducidas);
	
	float determinante_4_x_4_matriz_original = calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida, medidasReducidas);
	if(determinante_4_x_4_matriz_original==0){
		puts("\nDeterminante principal: 0. La ecuacion no tiene solucion\n");
	}else{
		int j=0;
		for (int numero_columna = 0; numero_columna < medidas.filas; numero_columna++){
			
			copiar_datos_para_otra_matriz_4_x_4(matriz, medidas, matriz_operable_reducida, medidasReducidas);
			
			//imprimirMatriz_2(matriz_operable_reducida);
			sustituir_columna_a_trabajar_por_columna_coeficientes_3_y_4( matriz, medidas, matriz_operable_reducida, medidasReducidas, numero_columna);
			
			puts("\nSustitucion de matriz\n");
			imprimirMatrizCramer(matriz_operable_reducida, medidasOriginales);
			puts("\n");
			puts("Determinante de matriz\n");
			double determinante4x4=calcular_determinante_orden_cuatro_x_cuatro(matriz_operable_reducida, medidasReducidas);
			double resultado_incognita = determinante4x4 /(float)determinante_4_x_4_matriz_original;
			printf("\n%.2lf / %.2f = %.2lf\n", determinante4x4, (float)determinante_4_x_4_matriz_original, resultado_incognita);
			printf("%f %c \n", resultado_incognita, 87+j);
			j++;
			puts("\nPresiones enter para continuar\n");
			char continuar=getchar();
		}
	}
	
}
double calcular_determinante_orden_cuatro_x_cuatro(double** matriz_operable, dimensiones medidasReducidas){
	dimensiones medidasTemporales;
	medidasTemporales.filas=5;
	medidasTemporales.columnas=3;
	
	double** matriz_temporal;
	matriz_temporal=inicializarMatrizCramer(medidasTemporales);

	double resultado_final = 0;
	
	for (int indice_columna_global = 0; indice_columna_global < medidasReducidas.filas; indice_columna_global++){
		
		int indice_fila = 0;
		
		//------- Esta seccion "recorta la matriz " para volverla  3 * 3---------------------- 
		// LA FILA 0 EN LA MATRIZ ES LA ANCLADA, LAS COLUMNAS SON LAS QUE ITERAN
		for (int indice_fila_limitada = 1; indice_fila_limitada < medidasReducidas.filas; indice_fila_limitada++){
			int indice_columna = -1;
			for (int indice_columna_limitada = 0; indice_columna_limitada < medidasReducidas.filas; indice_columna_limitada++){
				if (indice_columna_limitada != indice_columna_global){
					indice_columna++;
					matriz_temporal[indice_fila][indice_columna] = matriz_operable[indice_fila_limitada][indice_columna_limitada];
				}
			}
			indice_fila++;
		}
		copiar_filas_rellenar_matriz_3_x_3(0, 3,matriz_temporal, medidasTemporales);
		copiar_filas_rellenar_matriz_3_x_3(1, 4,matriz_temporal, medidasTemporales);
		//----------------------------------------------------------------
		
		
		
		int indice_fila_i = 1;
		int indice_columna_j = indice_columna_global + 1;
		int primer_valor_multiplicable = (pow(-1, indice_fila_i + indice_columna_j));
		
		double valor_a_trabajar_interseccion = matriz_operable[0][indice_columna_global];
		
		printf("\nElemento [%d][%d]\n", indice_columna_j, indice_fila_i);
		
		double determinante_orden_tres_x_tres = calcular_determinante_orden_tres_x_tres(matriz_temporal, medidasTemporales);
		
		printf("\n(-1)^%d+%d * %.2lf * %.2lf = %.2lf\n", indice_fila_i, indice_columna_j, valor_a_trabajar_interseccion, determinante_orden_tres_x_tres, primer_valor_multiplicable * valor_a_trabajar_interseccion * determinante_orden_tres_x_tres);
		printf("%.2lf + %.2lf\t", resultado_final, primer_valor_multiplicable * valor_a_trabajar_interseccion * determinante_orden_tres_x_tres);
		
		resultado_final += ( primer_valor_multiplicable * valor_a_trabajar_interseccion * determinante_orden_tres_x_tres );
		
		printf("= %.2lf\n", resultado_final);
	}
	
	puts("\n");
	
	liberarMemoriaDouble(matriz_temporal, medidasTemporales);
	
	return resultado_final;
}
void copiar_datos_para_otra_matriz_4_x_4(double** matriz_operable, dimensiones medidas, double** matriz_operable_reducida, dimensiones medidasReducidas){
	for (int i = 0; i<medidas.filas ; i++){
		for (int f = 0; f<medidas.filas; f++){
			matriz_operable_reducida[i][f] = matriz_operable[i][f];
		}
	}
}
void sistemaEcuacionesGaussJordan(){
	float** matriz;
	dimensiones medidas;
	
	puts("Sistema de Ecuaciones por Gauss Jordan\n");
	
	medidas=leerDimensionesCuadradas();
	while(medidas.filas==1){
		if(medidas.filas==1){
			puts("Tamaño minimo es de 2");
		}
		medidas=leerDimensionesCuadradas();
	}
	medidas.columnas++;
	
	puts("\n");
	
	matriz=inicializarMatriz(medidas);
	leerEcuacionesGaussJordan(matriz, medidas);
	puts("\n");
	imprimirEcuacionGaussJordan(matriz, medidas);
	
	imprimirMatriz_matraca_desendente(matriz, medidas);
	imprimirMatriz_matraca_asendente(matriz, medidas);
	corregir_0_negativo(matriz, medidas);
	redondeo_milesimal(matriz, medidas);
	
	puts("\n");
	
	puts("Matriz final:");
	imprimirMatriz(matriz, medidas);
	
	puts("\n");
	
	int j=0;
	for(int i=0; i<medidas.filas; i++){
		printf("%f %c\n", matriz[i][medidas.columnas-1], 87+j);
		j++;
	}
	
	liberarMemoria(matriz, medidas);
	
}
void imprimirEcuacionGaussJordan(float** matriz, dimensiones medidas){
	puts("El sistema de ecuaciones se veria de la siguiente forma:");
	puts("\n");
	for(int i=0; i<medidas.filas; i++){
		for(int j=0; j<medidas.columnas; j++){
			if(j==medidas.columnas-1){
				printf("%.2f", matriz[i][j]); 
			}else{
				if(j==medidas.columnas-2){
					printf("%.2f %c = ", matriz[i][j], 65+j);
				}else{
					printf("%.2f %c + ", matriz[i][j], 65+j);
				}
			}
		}
		puts("\n");
	}
}
void leerEcuacionesGaussJordan(float** matriz, dimensiones medidas){
	float num;
	int i, j;
	
	for(i=0; i<medidas.filas; i++){
		for(j=0; j<medidas.columnas; j++){
			matriz[i][j]=0;
		}
	}
	
	for(i=0; i<medidas.filas; i++){
		for (j=0;j<medidas.columnas; j++){
			if(j==medidas.columnas-1){
				printf("Ingrese el resultado de la ecuacion %d: ", i+1);
				while (scanf("%f",&num)!=1||getchar()!='\n'){
					printf("Entrada invalida. Ingrese un numero: ");
					fflush(stdin);
				}
			}else{
				printf("\nIngrese el coeficiente de %c, de la ecuacion %d: ", 65+j, i+1);
				while (scanf("%f",&num)!=1||getchar()!='\n'){
					printf("Entrada invalida. Ingrese un numero: ");
					fflush(stdin);
				}
			}
			matriz[i][j]=num;
			for(int a=0; a<medidas.filas; a++){
				for(int b=0; b<medidas.columnas; b++){
					printf("%.2f    ", matriz[a][b]);
				}
				puts("\n");
			}
		}
	}
	
	puts("\n");
	
	return;	
}
void calcularDeterminante(){
	double **matriz;
	dimensiones medidas;
	double determinante;
	
	dimensiones medidasReducidas;
	medidasReducidas.filas=5;
	medidasReducidas.columnas=3;
	
	double** matriz_operable_reducida;
	matriz_operable_reducida=inicializarMatrizCramer(medidasReducidas);
	
	puts("Calculo de Determinante de una Matriz\n");
	
	medidas=leerDimensionesCuadradas();
	while(medidas.filas==1 || medidas.filas>4){
		if(medidas.filas==1){
			puts("Tamaño minimo es de 2");
		}
		if(medidas.filas>4){
			puts("Tamaño maximo es de 4");
		}
		medidas=leerDimensionesCuadradas();
	}
	
	puts("\n");
	
	matriz=inicializarMatrizCramer(medidas);
	leerMatrizCramer(matriz, medidas);
	puts("\n");
	
	switch(medidas.filas){
	case 2:
		determinante=calcular_determinante_orden_dos_x_dos(matriz, medidas);
		printf("El determinante de la matriz es de: %.2lf\n", determinante);
		break;
	case 3:
		restaurar_matriz_3_x_3(matriz, medidas, matriz_operable_reducida, medidasReducidas);
		determinante=calcular_determinante_orden_tres_x_tres(matriz_operable_reducida, medidasReducidas);
		printf("El determinante de la matriz es de: %.2lf\n", determinante);
		break;
	case 4:
		determinante=calcular_determinante_orden_cuatro_x_cuatro(matriz, medidas);
		printf("El determinante de la matriz es de: %.2lf\n", determinante);
		break;
	}
	
}
void leerMatrizCramer(double** matriz, dimensiones medidas){
	float num;
	int i, j;
	
	for(i=0; i<medidas.filas; i++){
		for(j=0; j<medidas.columnas; j++){
			matriz[i][j]=0;
		}
	}
	
	for(i=0; i<medidas.filas; i++){
		for (j=0;j<medidas.columnas; j++){
			printf("\nIngrese el valor [%d][%d]: ", i, j);
			while (scanf("%f",&num)!=1||getchar()!='\n'){
				printf("Entrada invalida. Ingrese un numero: ");
				fflush(stdin);
			}
			matriz[i][j]=num;
			for(int a=0; a<medidas.filas; a++){
				for(int b=0; b<medidas.columnas; b++){
					printf("%.2f    ", matriz[a][b]);
				}
				puts("\n");
			}
		}
	}
	
	return;
}
float validacionDeterminante(float** matriz, dimensiones medidas){
	float determinante;
	
	dimensiones medidasReducidas;
	medidasReducidas.filas=5;
	medidasReducidas.columnas=3;
	
	float** matriz_operable_reducida;
	matriz_operable_reducida=inicializarMatriz(medidasReducidas);
	
	switch(medidas.filas){
	case 2:
		determinante=determiannte_2x2(matriz, medidas);
		break;
	case 3:
		restaurarMatriz_3x3(matriz, medidas, matriz_operable_reducida, medidasReducidas);
		determinante=determinante_3x3(matriz_operable_reducida, medidasReducidas);
		break;
	case 4:
		determinante=determinante_4x4(matriz, medidas);
		break;
	}
	
	return determinante;
}
float determiannte_2x2(float** matriz, dimensiones medidas){
	float determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	return determinante;
}
float determinante_3x3(float** matriz, dimensiones medidasReducidas){
	float resultado_determinante = 0;
	
	
	/*  ida  \     */
	int fila_de_inicio = 0;
	double contador_ida = 0;
	
	for (int recorer_columnas_global = 0; recorer_columnas_global < medidasReducidas.columnas; recorer_columnas_global++){
		double multiplicador = 1;
		for (int columna_recorrida = 0 ; columna_recorrida < medidasReducidas.columnas; columna_recorrida++){
			multiplicador *= matriz[fila_de_inicio][columna_recorrida];
			fila_de_inicio++;
		}
		fila_de_inicio = fila_de_inicio - 2;
		contador_ida += multiplicador;
	}
	resultado_determinante += contador_ida;
	
	
	/*  vuelta  /    */
	fila_de_inicio = 0;
	int contador_vuelta = 0;
	for (int recorer_columnas_global = 0; recorer_columnas_global < medidasReducidas.columnas; recorer_columnas_global++){
		double multiplicador = -1;
		for (int columna_recorrida = medidasReducidas.columnas-1 ; columna_recorrida >= 0; columna_recorrida--){
			multiplicador *= matriz[fila_de_inicio][columna_recorrida];
			fila_de_inicio++;
		}
		fila_de_inicio = fila_de_inicio - 2;
		contador_vuelta += multiplicador;
	}
	resultado_determinante += contador_vuelta;
	
	
	return resultado_determinante;
}
float determinante_4x4(float** matriz_operable, dimensiones medidasReducidas){
	dimensiones medidasTemporales;
	medidasTemporales.filas=5;
	medidasTemporales.columnas=3;
	
	float** matriz_temporal;
	matriz_temporal=inicializarMatriz(medidasTemporales);
	
	float resultado_final = 0;
	
	
	for (int indice_columna_global = 0; indice_columna_global < medidasReducidas.filas; indice_columna_global++){
		
		int indice_fila = 0;
		
		//------- Esta seccion "recorta la matriz " para volverla  3 * 3---------------------- 
		// LA FILA 0 EN LA MATRIZ ES LA ANCLADA, LAS COLUMNAS SON LAS QUE ITERAN
		for (int indice_fila_limitada = 1; indice_fila_limitada < medidasReducidas.filas; indice_fila_limitada++){
			int indice_columna = -1;
			for (int indice_columna_limitada = 0; indice_columna_limitada < medidasReducidas.filas; indice_columna_limitada++){
				if (indice_columna_limitada != indice_columna_global){
					indice_columna++;
					matriz_temporal[indice_fila][indice_columna] = matriz_operable[indice_fila_limitada][indice_columna_limitada];
				}
			}
			indice_fila++;
		}
		copiarFilas_3x3(0, 3,matriz_temporal, medidasTemporales);
		copiarFilas_3x3(1, 4,matriz_temporal, medidasTemporales);
		//----------------------------------------------------------------
		
		
		
		int indice_fila_i = 1;
		int indice_columna_j = indice_columna_global + 1;
		int primer_valor_multiplicable = (pow(-1, indice_fila_i + indice_columna_j));
		
		double valor_a_trabajar_interseccion = matriz_operable[0][indice_columna_global];
		
		double determinante_orden_tres_x_tres = determinante_3x3(matriz_temporal, medidasTemporales);
		
		resultado_final += ( primer_valor_multiplicable * valor_a_trabajar_interseccion * determinante_orden_tres_x_tres );
	}
	
	return resultado_final;
}
void restaurarMatriz_3x3(float** matriz, dimensiones medidas, float** matriz_operable_reducida, dimensiones medidasReducidas){
	for (int i = 0; i<medidas.filas ; i++){
		for (int f = 0; f<medidas.filas ; f++){
			matriz_operable_reducida[i][f] = matriz[i][f];
		}
	}
	
	copiarFilas_3x3(0, 3, matriz_operable_reducida, medidasReducidas);
	copiarFilas_3x3(1, 4, matriz_operable_reducida, medidasReducidas);
}
void copiarFilas_3x3(int fila_a_tomar, int fila_a_copiar, float** matriz, dimensiones medidasReducidas){
	for (int i = 0; i < medidasReducidas.columnas; i++){
		matriz[fila_a_copiar][i] = matriz[fila_a_tomar][i]; 
	}
}
void liberarMemoriaDouble(double** matriz, dimensiones medidas){
	for (int i=0; i<medidas.filas; i++) {
		free(matriz[i]);
	}
	free(matriz);
	
	return;
}
