#include <iostream>
#include <math.h>
using namespace std;
void ingresar_matriz(int matriz[10][10], int filas, int columnas) {
	printf("\nIngrese los valores de la matriz: \n");
	for (int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			scanf("%d",&matriz[i][j]);
		}
	}
	printf("\n");
}
void ingresar_vector(int vector[10], int dimension) {
	printf("\nIngrese los valores del vector:\n");
	for (int i=0;i<dimension;i++){
		scanf("%d",&vector[i]);
	}
	printf("\n");
}
void sumar_matrices(int matriz_a[10][10], int matriz_b[10][10], int filas, int columnas) {
	int resultado[10][10];
	printf("El resultado de la suma de las matrices es:");
	for (int i=0;i<filas;i++){
		printf ("\n[");
		for (int j=0;j<columnas;j++){
			resultado[i][j]=matriz_a[i][j]+matriz_b[i][j];
			printf("%d, ",resultado[i][j]);
		}
		printf ("]\n");
	}
}
void multiplicar_matriz_vector(int matriz[10][10], int vector[10], int filas, int columnas) {
	int resultado[10];
	for (int i=0;i<filas;i++){
		resultado[i]=0;
		for (int j=0;j<columnas;j++) {
			resultado[i]+=matriz[i][j]*vector[j];
		}
	}
	printf("\nEl resultado de la multiplicación es:\n[");
	for (int i=0;i<filas;i++){
		printf("%d, ",resultado[i]);
	}
	printf ("]\n");
}
void norma_vector(int vector[10], int dimension){
	float suma=0;
	for (int i=0;i<dimension;i++) {
		suma+=vector[i]*vector[i];
	}
	suma=sqrt(suma);
	printf("\nLa norma del vector es %.3f\n",suma);
}
int main(int argc, char *argv[]) {
	const int tam=10;
	int A[tam][tam],B[tam][tam],C[tam],m;
	int fa,fb,ca,cb,v,opc;
	
	do{
	printf("\n");
	printf("\nIngrese al menú: ");
	printf("\n1. Ingrese a la matriz y el tamaño de la matriz. ");
	printf("\n2. Suma de matrices.");
	printf("\n3. Multiplicación de matriz con vector");
	printf("\n4. Calcular la norma del vector");
	printf("\n5. Salir.\n");
	scanf("%d",&m);
	switch(m){
		case 1:{
			printf("\nIngrese las filas de la Matriz A: ");
			do{
				scanf("%d",&fa);
			}while(fa<0 || fa>10);
			printf("\nIngrese las columnas de la Matriz A: ");
			do{
				scanf("%d",&ca);
			}while(ca<0 || ca>10);
			ingresar_matriz (A,fa,ca);
			printf("\nIngrese las filas de la Matriz B: ");
			do{
				scanf("%d",&fb);
			}while(fb<0 || fb>10);
			printf("\nIngrese las columnas de la Matriz B: ");
			do{
				scanf("%d",&cb);
			}while(cb<0 || cb>10);
			ingresar_matriz (B,fb,cb);
			printf("\nIngrese el tamaño del vector C: ");
			do{
				scanf("%d",&v);
			}while(v<0 || fa>v);
			ingresar_vector (C,v);
		}
		break;
		case 2:{
			if (ca==cb){
				if (fa==fb){
					sumar_matrices(A,B,fa,ca);
				}
				else {
					printf("\nLas matrices no pueden sumarse porque no son de igual tamaño");
				}
			}
			else {
				printf("\nLas matrices no pueden sumarse porque no son de igual tamaño");
			}
		}
		break;
		case 3:{
			printf("\nElija la matriz a multiplicar con el vector: \n1.Matriz A.\n2.Matriz B.\n");
			do{
				scanf("%d",&opc);
			}while(opc<0||opc>2);
			if (opc==1){
				if (ca==v){
					multiplicar_matriz_vector(A,C,fa,ca);
				}
				else {
					printf("\nNo pueden multiplicarse porque las columnas de la matriz A no tiene la misma dimensión que el vector C.");
				}
			}
			if (opc==2){
				if (cb==v){
					multiplicar_matriz_vector(B,C,fb,cb);
				}
				else {
					printf("\nNo pueden multiplicarse porque las columnas de la matriz B no tiene la misma dimensión que el vector C.");
				}
			}
		}
		break;
		case 4:{
			norma_vector(C,v);
		}
		break;
	default:
		printf("Fin del programa.");
	}
	}while (m!=5);
	return 0;
}
	
