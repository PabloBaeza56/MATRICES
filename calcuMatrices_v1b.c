#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
	}
	
	return 0;
}
dimensiones leerDimensiones(){
	dimensiones medidas;
	
	puts("Ingrese las dimensiones de la matriz\n");
	puts("Filas:");
	scanf("%d", &medidas.filas);
	puts("Columnas:");
	scanf("%d", &medidas.columnas);
	
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

