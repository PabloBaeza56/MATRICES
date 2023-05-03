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
float **inicializarMatriz(dimensiones);
void liberarMemoria(float**, dimensiones);
void leerMatriz(float**, dimensiones);
void imprimirMatriz(float**, dimensiones);

void matrizTranspuesta();
void sumarMatrices();
void multiplicacionEscalar();
void multiplicacionMatrices();

void inversaGaussJordan();
void leerMatrizGaussJordan(float**, dimensiones);
void operar_matriz_con_pivotes(float**, int, int, float, dimensiones);
void operar_matriz_estocada_final(float**, int, float, dimensiones);
void imprimirMatriz_matraca_desendente(float**, dimensiones);
void imprimirMatriz_matraca_asendente(float**, dimensiones);
void corregir_0_negativo(float**, dimensiones);
void redondeo_milesimal(float**, dimensiones);

int main(int argc, char *argv[]) {
	int opcion;
	
	puts("Biblioteca de Operaciones con Matrices\n");
	
	puts("\n");
	
	puts("1. Suma de Matrices\n");
	puts("2. Multiplicacion de Matrices por una Escalar\n");
	puts("3. Multiplicacion de Matrices\n");
	puts("4. Obtención de Transpuesta de una Matriz\n");
	puts("5. Obtencion de la Inversa de una Matriz por Gauss-Jordan\n");
	puts("6. Solución de Sistema de Ecuaciones por Gauss-Jordan\n");
	puts("7. Calcula de Determinante de una Matriz\n");
	puts("8. Solución de Sistema de Ecuaciones por Cramer");
	
	puts("\n");
	
	puts("Ingrese una opcion");
	scanf("%d", &opcion);
	
	switch(opcion){
	case 1:
		sumarMatrices();
		break;
	case 2:
		multiplicacionEscalar();
		break;
	case 3:
		multiplicacionMatrices();
		break;
	case 4:
		matrizTranspuesta();
		break;
	case 5:
		inversaGaussJordan();
		break;
	case 6:
		
		break;
	case 7:
		
		break;
	case 8:
		
		break;
	}
	
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
		if(medidas.filas>4 || medidas.columnas>4){
			puts("Tamaño maximo de matrices: 4x4");
		}
		if(medidas.filas<1 || medidas.columnas<1){
			puts("Entrada/s invalida. Ingrese numeros positivo:");
		}
	} while(medidas.filas>4 || medidas.columnas>4 || medidas.filas<1 || medidas.columnas<1);
	
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
	
	for(int i=0; i<medidas.filas; i++){
		for (int j=0;j<medidas.columnas; j++){
			printf("\nIngrese el valor [%d][%d]: ", i, j);
			while (scanf("%f",&num)!=1||getchar()!='\n'){
				printf("Entrada invalida. Ingrese un numero: ");
				fflush(stdin);
			}
			matriz[i][j]=num;
			for(int a=0; a<=i; a++){
				for(int b=0; b<=j; b++){
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
		for (int j=0;j<medidas.filas; j++){
			printf("\nIngrese el valor [%d][%d]: ", i, j);
			while (scanf("%f",&num)!=1||getchar()!='\n'){
				printf("Entrada invalida. Ingrese un numero: ");
				fflush(stdin);
			}
			matriz[i][j]=num;
			for(int a=0; a<=i; a++){
				for(int b=0; b<=j; b++){
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
void matrizTranspuesta(){
	float **transpuesta, **matriz;
	dimensiones medidasEntrada, medidasTranspuesta;
	
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
	
	return;
}
void sumarMatrices(){
	float **matrizA, **matrizB, **matrizC;
	dimensiones medidas;
	
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
	
	return;
}	

void inversaGaussJordan(){
	float **matriz;
	dimensiones medidas;
	
	do{
		medidas=leerDimensiones();
		if(medidas.filas!=medidas.columnas){
			puts("Ingrese una matriz cuadrada");
		}
		if(medidas.filas==1 || medidas.columnas==1){
			puts("Tamaño minimo de matriz: 2x2");
		}
	} while(medidas.filas!=medidas.columnas && (medidas.filas<=1 || medidas.columnas<=1));
	
	
	medidas.columnas=medidas.filas*2;
	
	puts("\n");
	
	matriz=inicializarMatriz(medidas);
	leerMatrizGaussJordan(matriz, medidas);
	puts("\n");
	puts("Matriz aumentada");
	imprimirMatriz(matriz, medidas);
	
	imprimirMatriz_matraca_desendente(matriz, medidas);
	imprimirMatriz_matraca_asendente(matriz, medidas);
	redondeo_milesimal(matriz, medidas);
	corregir_0_negativo(matriz, medidas);
	puts("\n");
	puts("Inversa de matriz");
	imprimirMatriz(matriz, medidas);
	
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
				operar_matriz_estocada_final(matriz, fila, res, medidas);
			}else{
				float res = (matriz[col][fila]) * -1;
				operar_matriz_con_pivotes(matriz, fila, col, res, medidas);
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
				operar_matriz_con_pivotes(matriz, col, fila, res, medidas);
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
	
	return;
}
void operar_matriz_estocada_final(float **matriz, int fila_posicion_actual, float valor_a_operar, dimensiones medidas){
	
	for (int col = 0; col < medidas.columnas; col++){
		matriz[fila_posicion_actual][col] = matriz[fila_posicion_actual][col] * valor_a_operar;
	}
	
	return;
}
