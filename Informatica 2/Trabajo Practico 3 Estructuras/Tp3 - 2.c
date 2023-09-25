#include <stdio.h>
#include <string.h>

#define MAX_IMAGES 100

struct Imagen {
	int codigo;
	char nombre[50];
	char extension[10];
	int tamano;
	float precio;
};

struct Imagen stock[MAX_IMAGES];
int numImagenes = 0;

void agregarImagen();
void eliminarImagen(int codigo);
void modificarImagen(int codigo);
void buscarPorNombre(char nombre[]);
void buscarPorExtension(char extension[]);
void buscarPorTamano(int tamano);

int main() {
	int opcion,cod;
	char aux[50];
	
	do {
		printf("Men�:\n");
		printf("1. Agregar imagen\n");
		printf("2. Eliminar imagen\n");
		printf("3. Modificar imagen\n");
		printf("4. Buscar por nombre\n");
		printf("5. Buscar por extensi�n\n");
		printf("6. Buscar por tama�o\n");
		printf("7. Salir\n");
		printf("Ingrese una opci�n: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			agregarImagen();
			break;
		case 2:
			printf("Ingrese el c�digo de la imagen que desea eliminar:\n");
			scanf("%d",&cod);
			eliminarImagen(cod);
			break;
		case 3:
			printf("Ingrese el c�digo de la imagen que desea modificar:\n");
			scanf("%d",&cod);
			modificarImagen(cod);
			break;
		case 4:
			printf("Ingrese el nombre de la imagen que desea encontrar:\n");
			scanf("%s",&aux);
			buscarPorNombre(aux);
			break;
		case 5:
			printf("Ingrese el extensi�n de la imagen que desea encontrar:\n");
			scanf("%s",&aux);
			buscarPorExtension(aux);
			break;
		case 6:
			printf("Ingrese el tama�o de la imagen que desea encontrar:\n");
			scanf("%d",&cod);
			buscarPorTamano(cod);
			break;
		case 7:
			printf("Fin del programa.\n");
			break;
		default:
			printf("Opci�n no v�lida.\n");
		}
	} while (opcion != 7);
	
	return 0;
}

void agregarImagen() {
	if (numImagenes < MAX_IMAGES) {
		struct Imagen nuevaImagen;
		printf("Ingrese el c�digo de inventario: ");
		scanf("%d", &nuevaImagen.codigo);
		printf("Ingrese el nombre del archivo: ");
		scanf("%s", nuevaImagen.nombre);
		printf("Ingrese la extensi�n del archivo: ");
		scanf("%s", nuevaImagen.extension);
		printf("Ingrese el tama�o en bytes: ");
		scanf("%d", &nuevaImagen.tamano);
		printf("Ingrese el precio de la imagen: ");
		scanf("%f", &nuevaImagen.precio);
		
		stock[numImagenes] = nuevaImagen;
		numImagenes++;
		
		printf("Imagen agregada correctamente.\n");
	} else {
		printf("No hay espacio en el stock para m�s im�genes.\n");
	}
}

void eliminarImagen(int codigo){
	int indice = -1;
	
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			indice = i;
			break;
		}
	}
	
	if (indice != -1) {
		for (int i = indice; i < numImagenes - 1; i++) {
			stock[i] = stock[i + 1];
		}
		numImagenes--;
		
		printf("Imagen eliminada correctamente.\n");
	} else {
		printf("No se encontr� ninguna imagen con ese c�digo.\n");
	}
}


void modificarImagen (int codigo){
	int indice = -1,m;
	
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			indice = i;
			break;
		}
	}
	
	if (indice != -1) {
		do{printf("Men�:\n");
		printf("1. Modificar nombre\n");
		printf("2. Modificar extension\n");
		printf("3. Modificar tama�o\n");
		printf("4. Modificar precio\n");
		printf("5. Salir\n");
		printf("Ingrese una opci�n: ");
		scanf("%d", &m);
		switch (m) {
		case 1:
			printf("Ingrese el nuevo nombre del archivo: ");
			scanf("%s", stock[indice].nombre);
			break;
		case 2:
			printf("Ingrese el nuevo extension del archivo: ");
			scanf("%s", stock[indice].extension);
			break;
		case 3:
			printf("Ingrese el nuevo tama�o del archivo: ");
			scanf("%d", stock[indice].tamano);
			break;
		case 4:
			printf("Ingrese el nuevo precio del archivo: ");
			scanf("%d", stock[indice].precio);
			break;
		case 5:
			printf("Fin de las modificaciones.\n");
			break;
		default:
			printf("Opci�n no v�lida.\n");
		}
	}while (m != 5);
		printf("Se completo exitosamente la modificacion de la imagen.\n");
	} else {
		printf("No se encontr� ninguna imagen con ese c�digo.\n");
	}
}
void buscarPorNombre(char nombre[]){
	int indice = -1;
	
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].nombre == nombre) {
			indice = i;
			break;
		}
	}
	
	if (indice != -1){
		printf("Se encontr� correctamente la siguiente imagen:\n");
		printf("Codigo: %d\nNombre: %s\nExtencion: %s\nTama�o: %d\nPrecio: %d.\n", stock[indice].codigo, stock[indice].nombre, stock[indice].extension, stock[indice].tamano, stock[indice].precio);
	} else {
		printf("No se encontr� ninguna imagen con ese nombre\n");
	}
}
	void buscarPorExtension(char extension[]){
		int indice = -1;
		
		for (int i = 0; i < numImagenes; i++) {
			if (stock[i].extension == extension) {
				indice = i;
				break;
			}
		}
		
		if (indice != -1){
			printf("Se encontr� correctamente la siguiente imagen:\n");
			printf("Codigo: %d\nNombre: %s\nExtencion: %s\nTama�o: %d\nPrecio: %d.\n", stock[indice].codigo, stock[indice].nombre, stock[indice].extension, stock[indice].tamano, stock[indice].precio);
		} else {
			printf("No se encontr� ninguna imagen con esa extension\n");
		}
	}
	void buscarPorTamano(int tamano){
		int indice = -1;
		
		for (int i = 0; i < numImagenes; i++) {
			if (stock[i].tamano == tamano) {
				indice = i;
				break;
			}
		}
		
		if (indice != -1){
			printf("Se encontr� correctamente la siguiente imagen:\n");
			printf("Codigo: %d\nNombre: %s\nExtencion: %s\nTama�o: %d\nPrecio: %d.\n", stock[indice].codigo, stock[indice].nombre, stock[indice].extension, stock[indice].tamano, stock[indice].precio);
		} else {
			printf("No se encontr� ninguna imagen con ese tamano\n");
		}
	}
	
