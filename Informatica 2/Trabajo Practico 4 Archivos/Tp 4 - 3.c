#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 200

void copiarYReemplazar(const char *nombreOrigen, const char *nombreDestino, const char *palabra1, const char *palabra2);
void leerYMostrarArchivo(char nombre[]);
int validarNombreArchivo(char nombre[]);

int main() {
	char nombreArchivoOrigen[MAX_FILENAME_LENGTH];
	char nombreArchivoDestino[MAX_FILENAME_LENGTH];
	char palabra1[MAX_WORD_LENGTH];
	char palabra2[MAX_WORD_LENGTH];
	int aux=0, aux2=0;
	
	do {
	printf("Ingrese el nombre del archivo origen: ");
	scanf("%s", nombreArchivoOrigen);
	aux = validarNombreArchivo(nombreArchivoOrigen);
	if (aux == 0) {
		printf("Nombre incorrecto de archivo\n");
	}else{
		FILE *archivo = fopen(nombreArchivoOrigen, "r");
		if (archivo == NULL) {
			printf("El archivo origen no existe o no se puede abrir, por favor ingresa otro nombre de archivo.\n");
			fclose(archivo);
			aux = 0;
		} else {
			printf("El archivo existe y se pudo abrir.\n");
			fclose(archivo);
		}
	}
	} while (aux == 0);
	
	
	do{
	printf("Ingrese el nombre del archivo destino: ");
	scanf("%s", nombreArchivoDestino);
	aux2 = validarNombreArchivo(nombreArchivoDestino);
	if (aux2 == 0) {
		printf("Nombre incorrecto de archivo\n");
	}else{
		FILE *archivo2 = fopen(nombreArchivoDestino, "r");
		if (archivo2 == NULL) {
			printf("El archivo destino no existe o no se puede abrir, por favor ingresa otro nombre de archivo.\n");
			fclose(archivo2);
			aux2 = 0;
		} else {
			printf("El archivo existe y se pudo abrir.\n");
			fclose(archivo2);
		}
	}
	}while (aux2 == 0);
	
	printf("Ingrese la primera palabra: ");
	scanf("%s", palabra1);
	
	printf("Ingrese la segunda palabra: ");
	scanf("%s", palabra2);
	
	copiarYReemplazar(nombreArchivoOrigen, nombreArchivoDestino, palabra1, palabra2);
	
	printf("Contenido del archivo copiado y reemplazado.\n El contenido en el archivo destino quedo de la siguiente forma:");
	leerYMostrarArchivo(nombreArchivoDestino);
	
	return 0;
}	

void copiarYReemplazar(const char *nombreOrigen, const char *nombreDestino, const char *palabra1, const char *palabra2) {
	FILE *archivoOrigen = fopen(nombreOrigen, "r");
	FILE *archivoDestino = fopen(nombreDestino, "w");
	
	if (archivoOrigen == NULL || archivoDestino == NULL) {
		printf("No se pudo abrir uno o ambos archivos.\n");
		return;
	}
	
	char linea[MAX_LINE_LENGTH];
	
	while (fgets(linea, sizeof(linea), archivoOrigen) != NULL) {
		char nuevaLinea[MAX_LINE_LENGTH] = ""; 
		char *posicion = linea;  
		
		while (*posicion != '\0') {
			if (strstr(posicion, palabra1) == posicion) {
				strcat(nuevaLinea, palabra2);
				posicion += strlen(palabra1);
			} else {
				strncat(nuevaLinea, posicion, 1);
				posicion++;
			}
		}
		fputs(nuevaLinea, archivoDestino);
	}
	fclose(archivoOrigen);
	fclose(archivoDestino);
}


void leerYMostrarArchivo(char nombre[]) {
	FILE *archivo = fopen(nombre, "r");
	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return;
	}
	
	printf("\nContenido del archivo:\n");
	
	char caracter;
	while ((caracter = fgetc(archivo)) != EOF) {
		putchar(caracter);
	}
	
	fclose(archivo);
}
int validarNombreArchivo(char nombre[]) {
	int longitud = strlen(nombre);
	int indice = -1, i;
	
	for (i=0; i < longitud; i++){
		if (nombre[i] == '.') {
			indice = i;
			break;
		}
	}
	
	if ( indice == -1 || indice == 0 || indice == longitud - 1){
		return 0;
	}
	
	if (longitud == 0 || longitud > MAX_FILENAME_LENGTH) {
		return 0;
	}
	
	for (int i = 0; i < indice; i++) {
		// Verificar que el carácter sea una letra o número
		if (!((nombre[i] >= 'a' && nombre[i] <= 'z') || 
			(nombre[i] >= 'A' && nombre[i] <= 'Z') || 
			(nombre[i] >= '0' && nombre[i] <= '9'))) {
			return 0;
		}
	}
	for (int i = indice + 1; i < longitud; i++) {
		// Verificar que el carácter sea una letra
		if (!((nombre[i] >= 'a' && nombre[i] <= 'z') || 
			(nombre[i] >= 'A' && nombre[i] <= 'Z'))) {
			return 0;
		}
	}
	
	return 1;
}
