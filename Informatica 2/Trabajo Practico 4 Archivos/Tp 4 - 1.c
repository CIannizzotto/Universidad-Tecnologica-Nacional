#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_TEXT_LENGTH 1000

int validarNombreArchivo(char nombre[]);
void agregarTextoArchivo(char nombre[]);
void leerYMostrarArchivo(char nombre[]);

int main() {
	char nombreArchivo[MAX_FILENAME_LENGTH];
	
	printf("Ingrese el nombre del archivo: ");
	scanf("%s", nombreArchivo);
	
	if (validarNombreArchivo(nombreArchivo)) {
		agregarTextoArchivo(nombreArchivo);
		leerYMostrarArchivo(nombreArchivo);
	} else {
		printf("Nombre de archivo inválido.\n");
	}
	
	return 0;
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

void agregarTextoArchivo(char nombre[]) {
	FILE *archivo = fopen(nombre, "a");	
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return;
	}
	
	char texto[MAX_TEXT_LENGTH];
	printf("Ingrese el texto a agregar (máximo %d caracteres):\n", MAX_TEXT_LENGTH);
	fflush(stdin);
	fgets(texto, sizeof(texto), stdin);
	
	fputs(texto, archivo);
	fclose(archivo);
	printf("Texto agregado al archivo.\n");
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
