#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct punto{
	float y;
	float x;
}Puntos;

void calcularFuncion(Puntos *pfuncion); // funcion que me permite calcular los puntos de la funcion cuya pendiente y ordenada al origen indique el usuario
void funcionArb(Puntos *pfuncion); // funcion que me permite calcular los puntos de una funcion arbitraria que defino
void intersecciones(Puntos *pfuncion1, Puntos *pfuncion_arb); // funcion que me permite calcular si las funciones tienen una intersecciones en el rango de -5 y 5

int main() {
	
	int j;
	
	Puntos funcion1[100], funcionArbitraria[100];
	Puntos funcion1Bin[100], funcionArbBin[100];
	FILE *archivoFuncion;
	
//----------------------------Hago el llamado de las 3 funciones para calculas los puntos de cada funcion y calcular su intersección-------------------------------------------------------
	calcularFuncion(&funcion1[0]);
	funcionArb(&funcionArbitraria[0]);
	intersecciones(&funcion1[0], &funcionArbitraria[0]);

	
//--------------------------------------------------Manipulacion de archivos---------------------------------------------------------------------------------------------------------
	archivoFuncion = fopen("Funciones.bin","wb");
	
// Verifico si hay un error en la apertura del archivo	
	
	if( archivoFuncion == NULL ){
		printf("Error al abrir al archivo");
		exit(1);
	}

	else{
	printf("\n\nApertura exitosa del archivo");
	
	fwrite( &funcion1, sizeof(*funcion1), 100, archivoFuncion);//se leen los puntos de la funcion1 y se guardan en el archivo
	fwrite ( &funcionArbitraria, sizeof(*funcionArbitraria), 100, archivoFuncion);// se leen los puntos de la f_arb y se guardan en el archivo
	
	}
	
	fclose(archivoFuncion);//se cierra la escritura para leer el archivo
	
	archivoFuncion = fopen("Funciones.bin","rb");
	printf("\n======================Lectura con fread======================");
	if( archivoFuncion == NULL ){
		printf("Error al abrir al archivo");
		exit(1);
	}
	else{
		printf("\nApertura exitosa del archivo\n");
		fread(&funcion1Bin[0], sizeof(*funcion1), 100, archivoFuncion); //se leen del archivo los datos de la f1 y se guardan en esta nueva variable
		fread (&funcionArbBin[0], sizeof(*funcionArbitraria), 100, archivoFuncion);// se leen del archivo los datos de la farb y se guardan en esta nueva variable
		
		for(j=0; j<100 ; j+=10){
			printf("\n[x]=%f [y]=%f",funcion1Bin[j].x, funcion1Bin[j].y);
		}
		printf("\n======================Funcion Arbitraria======================");
		for(j=0; j<100 ; j+=10){
			printf("\n[x]=%f [y]=%f",funcionArbBin[j].x, funcionArbBin[j].y);
		}
	}
	
	fclose(archivoFuncion);
	
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
