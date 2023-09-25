#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct punto{
	float y;
	float x;
}Puntos;

void calcularFuncion(Puntos *pfuncion);
void funcionArb(Puntos *pfuncion);
void intersecciones(Puntos *pfuncion1, Puntos *pfuncionArb);

int main() {
	
	int j;
	Puntos funcion1[100], funcionArbitraria[100];
	
	calcularFuncion(&funcion1[0]);
	funcionArb(&funcionArbitraria[0]);
	intersecciones(&funcion1[0], &funcionArbitraria[0]);
	return 0;
}

void calcularFuncion(Puntos *pfuncion){
	
	float pendiente, ordenada;
	int i;
	
	printf("Ingrese la ordenada al origen ");
	scanf("%f", &ordenada);
	printf("Ingrese la pendiente de la funcion ");
	scanf("%f", &pendiente);
	fflush(stdin);
	
	(pfuncion+0)->x = -5;
	
	for (i=0;i<100;i++) {
		(pfuncion+i)->y = (pendiente * (pfuncion+i)->x) + ordenada;
		(pfuncion+(i+1))->x =(pfuncion+i)->x + 0.1;
	}
	
}
void funcionArb(Puntos *pfuncion){
	
	const int pendiente=2;
	const int ordenada=1;
	int i;
	(pfuncion+0)->x = -5;
	
	for (i=0;i<100;i++) {
		(pfuncion+i)->y = (pendiente * (pfuncion+i)->x) + ordenada;
		(pfuncion+(i+1))->x = (pfuncion+i)->x + 0.1;
	}
}		
void intersecciones(Puntos *pfuncion1, Puntos *pfuncionArb){
	int i;
	const float delta = 0.0001;
	for (i=0;i<100;i++) {	
		if( fabs( (pfuncion1+i)->y - (pfuncionArb+i)->y ) < delta ){
			if( fabs( (pfuncion1+i)->x - (pfuncionArb+i)->x ) < delta )
				printf("\nSe intersecan las funciones en [x]=%f [y]=%f", (pfuncion1+i)->x, (pfuncion1+i)->y);
		}
	}
}			
