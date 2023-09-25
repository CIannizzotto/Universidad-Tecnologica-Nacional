#include <stdio.h>
int tamano (char *palabra){
	int x=0;
	while(*palabra != '\0'){
		*palabra++;
		x++;
	}
	return x;
}
int especiales (char *puntero) {
	int especial = 0;
	while (*puntero != '\0'){
		if (!((*puntero <= 'z' && *puntero>='a')||(*puntero <= 'Z' && *puntero>='A')||(*puntero >= '0' && *puntero <= '9' ))){
			especial++;
		}
		*puntero++;
	}
	return especial;
}
int main(int argc, char *argv[]) {
	char matriz[6][100];
	int i,x,max,min,maxpos,minpos,espe=0,espepos;
	printf("\nIngrese 6 cadenas de longitud maxima 100:");
	for(i=0;i<6;i++){
		printf("\nIngrese la cadena %d:",i);
		gets(matriz[i]);
		printf("\nLa cadena ingresada es: \"%s\"",matriz[i]);
	};
	for(i=0;i<6;i++){
		x=tamano(matriz[i]);
		printf("\nEl tamaño de la cadena %d es: %d",i,x);
	}
	max=x;
	min=x;
	for(i=0;i<6;i++){
		x=tamano(matriz[i]);
		if(x>=max){
			max=x;
			maxpos=i;
		}
		if(x<=min){
			min=x;
			minpos=i;
		}
		x=especiales(matriz[i]);
		if (x>=espe){
			espe=x;
			espepos=i;
		}
	}
	printf("\n\nLa cadena de menor tamaño es: \"%s\" y el tamaño es: %d",matriz[minpos],min);
	printf("\n\nLa cadena de mayor tamaño es: \"%s\" y el tamaño es: %d",matriz[maxpos],max);
	if (espe==0){
		printf("\n\nNo hay cadenas con carácteres especiales");
	}else{
	printf("\n\nLa cadena de mayor cantidad de caracteres especiales es: \"%s\" y la cantidad es: %d",matriz[espepos],espe);
	}
	return 0;
}

