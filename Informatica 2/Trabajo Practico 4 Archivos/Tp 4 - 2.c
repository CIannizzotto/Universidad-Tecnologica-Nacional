#include <stdio.h>
#include <stdlib.h>

void copiarArchivo(const char *nombreOrigen, const char *nombreDestino);

int main() {
	char nombreArchivoOrigen[100];
	char nombreArchivoDestino[100];
	
	printf("Ingrese el nombre del archivo origen (incluyendo la extensión): ");
	scanf("%s", nombreArchivoOrigen);
	
	printf("Ingrese el nombre del archivo destino (incluyendo la extensión): ");
	scanf("%s", nombreArchivoDestino);
	
	copiarArchivo(nombreArchivoOrigen, nombreArchivoDestino);
	
	printf("Archivo copiado exitosamente.\n");
	
	return 0;
}

void copiarArchivo(const char *nombreOrigen, const char *nombreDestino) {
	FILE *archivoOrigen = fopen(nombreOrigen, "rb");
	FILE *archivoDestino = fopen(nombreDestino, "wb");
	
	if (archivoOrigen == NULL || archivoDestino == NULL) {
		printf("No se pudo abrir uno o ambos archivos.\n");
		return;
	}
	
	char caracter;
	
	while ((caracter = fgetc(archivoOrigen)) != EOF) {
		fputc(caracter, archivoDestino);
	}
	
	fclose(archivoOrigen);
	fclose(archivoDestino);
}
