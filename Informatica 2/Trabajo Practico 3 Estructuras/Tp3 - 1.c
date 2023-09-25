#include <stdio.h>
#include <string.h>

struct Persona {
	char apellido[30];
	char nombre[30];
	int edad;
	float altura;
}personas[3]; 


void cargaValor (char apellido[30], char nombre[30], int edad, float altura, int i);
void cargarReferencia(struct Persona *persona, char apellido[30], char nombre[30], int edad, float altura);
void mostrarPersonas(struct Persona personas[], int numPersonas);

int main(int argc, char *argv[]) {
	
	cargaValor("Gomez", "Cristian", 20, 1.65, 0);
	cargaValor("Lopez", "Nahuel", 22, 1.70, 1);
	cargaValor("Garcia", "Martin", 29, 1.86, 2);
	
	printf("Personas cargadas por valor:\n");
	mostrarPersonas(personas, 3);
	
	cargarReferencia(&personas[0], "Martinez", "Laura", 25, 1.60);
	cargarReferencia(&personas[1], "Sanchez", "Carlos", 35, 1.75);
	cargarReferencia(&personas[2], "Rodriguez", "Ana", 28, 1.70);
	
	printf("\nPersonas cargadas por referencia:\n");
	mostrarPersonas(personas, 3);
	return 0;
}

void cargaValor (char apellido[30], char nombre[30], int edad, float altura, int i) {
	strcpy(personas[i].apellido, apellido);
	strcpy(personas[i].nombre, nombre);
	personas[i].edad = edad;
	personas[i].altura = altura;
}

void cargarReferencia(struct Persona *persona, char apellido[30], char nombre[30], int edad, float altura) {
	strcpy(persona->apellido, apellido);
	strcpy(persona->nombre, nombre);
	persona->edad = edad;
	persona->altura = altura;
}

void mostrarPersonas(struct Persona personas[], int numPersonas) {
	for (int i = 0; i < numPersonas; i++) {
		printf("Persona %d: %s %s, Edad: %d, Altura: %.2f\n",
			   i + 1, personas[i].nombre, personas[i].apellido, personas[i].edad, personas[i].altura);
	}
}
