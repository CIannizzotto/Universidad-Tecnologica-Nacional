#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Imagen {
	int codigo;
	char nombre[50];
	char extension[10];
	float precio;	
	int tamano;
	struct Imagen *siguiente;
}primera={1,"001\n","png\n",100.50,64};

struct Imagen *agregarNodo(struct Imagen *nodo, int cant);
struct Imagen *eliminarNodo(struct Imagen *nodo, int cant);
void guardarArchivo(struct Imagen *nodo, int cant, FILE *archivo);
void mostrarArchivo(struct Imagen *nodo, int cant, FILE *archivo);
void mostrarLista(struct Imagen *nodoActual);
void mostrarListaOrdenada(struct Imagen *nodoActual, int cant);
void busqueda(struct Imagen *nodo, int cant);

int main() {
	int opcion,total=1;
	struct Imagen *inicio, *ultimo;
	FILE *ArchivoImagenes;
	inicio = &primera;
	ultimo = inicio;
	
	do {
		printf("Menú:\n");
		printf("1. Agregar nodo\n");
		printf("2. Eliminar nodo\n");
		printf("3. Grabar archivo\n");
		printf("4. Mostrar archivo\n");
		printf("5. Ver lista\n");
		printf("6. Buscar\n");
		printf("7. Mostrar lista ordenada alfabéticamente\n");
		printf("8. Salir\n");
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			ultimo = agregarNodo(inicio, total);
			total++;
			break;
			
		case 2:
			inicio = eliminarNodo(inicio, total);
			total--;
			break;
			
		case 3:
			guardarArchivo(inicio, total, ArchivoImagenes);
			break;
			
		case 4:
			mostrarArchivo(inicio, total, ArchivoImagenes);
			break;
			
		case 5:
			mostrarLista(inicio);
			break;
			
		case 6:
			busqueda(inicio, total);
			break;
		case 7:
			mostrarListaOrdenada(inicio, total);
			break;	
		case 8:
			printf("Fin del programa.\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	} while (opcion != 8);
	
	return 0;
}

struct Imagen *agregarNodo(struct Imagen *nodo, int cant){
	
	struct Imagen *nuevoNodo = (struct Imagen *) malloc(sizeof(struct Imagen));
	
	printf("Ingrese el CODIGO de la imagen.\n");
	scanf("%d",&(nuevoNodo)->codigo);
	
	printf("Ingrese el NOMBRE de la imagen.\n ");
	fgets((nuevoNodo)->nombre,49,stdin);
	
	printf("Ingrese la EXTENSION de la imagen (tipo de archivo 'png, jpg, tiff').\n");
	fgets((nuevoNodo)->extension,9,stdin);
	
	printf("Ingrese el TAMANO en BYTES de la imagen.\n");
	scanf("%d",&(nuevoNodo)->tamano);
	fflush(stdin);
	
	printf("Ingrese el PRECIO de la imagen.\n");
	scanf("%f",&(nuevoNodo)->precio);
	fflush(stdin);
	while( nodo->siguiente != NULL){
		nodo = nodo->siguiente;
	}
	nodo->siguiente = nuevoNodo;
	nuevoNodo->siguiente = NULL;
	
	return nuevoNodo;
}
struct Imagen *eliminarNodo(struct Imagen *nodo, int cant){
	
	int selec, i;
	struct Imagen *temp, *aux = nodo;
	
	do {
		printf("Que nodo desea elminiar? (de 0 a %d) ", cant-1);
		scanf("%d",&selec);
		fflush(stdin);
	} while (selec > cant);
	
	if(selec == 0){//si queremos borrar el primer nodo...
		temp = nodo;//apuntamos al primer nodo
		nodo = nodo->siguiente;//desplazamos el nodo al segundo
		free(temp);
		return nodo;//devolvemos el nuevo inicio
	}
	if(selec == cant){//si queremos borrar al final...
		while( nodo->siguiente->siguiente != NULL){//el siguiente del siguiente de los nodos
			nodo = nodo->siguiente;
		}
		nodo->siguiente = NULL;//no liberamos memoria por si queremos agregar otro nodo
		return aux;
	}
	
	for(i=0; i<(selec-1) ; i++){//posicionamos el nodo anterior al que queremos eliminar
		nodo = nodo->siguiente;
	}
	
	temp = nodo->siguiente;//temporal apunta al que queremos eliminar
	nodo->siguiente = temp->siguiente;
	//el nodo anterior al que queremos eliminar apunta al nodo siguiente del que queremos eliminar
	
	free(temp);//liberamos memoria
	
	printf("\nNodo [%d] se borró correctamente",selec);
	return aux;
}
void guardarArchivo(struct Imagen *nodo, int cant, FILE *archivo){
	
	archivo = fopen("Imagenes.bin","ab");
	if(archivo != NULL){
		printf("\nApertura exitosa\n");
	}
	else{
		printf("\nError al abrir o crear archivo");
		exit(1);
	}
	while(nodo != NULL) {
		fwrite(nodo, sizeof(struct Imagen), 1, archivo);
		nodo = nodo->siguiente;
	}
	printf("Archivo guardado con exito!!\n");
	fclose(archivo);
}

void mostrarArchivo(struct Imagen *nodo, int cant, FILE *archivo){
	
	int i=0;
	const int leer = 1;
	struct Imagen stockBinario;
	/** se declaran las imagenes binarias con la cant equivalente al tamano del archivo**/
	
	archivo= fopen("Imagenes.bin", "rb");
		
	if(archivo == NULL){
		printf("\nError al abrir archivo");
		return;
	}
	
	else{
		rewind(archivo);
		while( (fread(&stockBinario, sizeof(struct Imagen), leer, archivo)) == leer){
			/*fread devuelve la cantidad de elementos leidos con exito, si el numero devuelto es 
			distinto al numero entero ingresado en la funcion fread significa que hay un error
			para encontrar el feof (size_t fread...)  */
			printf("\nNombre imagen [%d]: %s",i+1, stockBinario.nombre);
			printf("Codigo imagen [%d]: %s",i+1, stockBinario.codigo);
			printf("Tipo de imagen [%d]: %s",i+1, stockBinario.extension);
			printf("Tamano imagen [%d]: %d\n",i+1, stockBinario.tamano);
			printf("Precio imagen [%d]: %f\n",i+1, stockBinario.precio);
			i++;
		}
	}
	fclose(archivo);
}

void mostrarLista(struct Imagen *nodoActual){		
	do {
		printf("\nNombre imagen:%s", nodoActual->nombre);
		printf("Codigo imagen:%s", nodoActual->codigo);
		printf("Tipo de imagen:%s",nodoActual->extension);
		printf("Tamano de imagen:%d\n",nodoActual->tamano);
		printf("Precio Imagen=%f\n", nodoActual->precio);
		nodoActual = nodoActual->siguiente; 
	} while (nodoActual != NULL);
}

void busqueda(struct Imagen *nodo, int cant){
	
	char nombreAux[20],extensionAux[6];
	int codigoAux,busqueda=0, tamanoAux, precioAux, i=0, validador = 0, seleccion;
	
	do {
		printf("\nINFO: \n [1]: Buscar por NOMBRE\n [2]: Buscar CODIGO\n [3]: Buscar TIPO\n [4]: Buscar TAMANO\n [5]: Buscar PRECIO	");
		scanf("%d", &busqueda);
		fflush(stdin);
		} while (busqueda < 1 || busqueda > 5 );
	
	switch(busqueda){
	case 1:
	printf("Ingrese el nombre para la busqueda ");
		fgets(nombreAux,19,stdin);
		validador = 0;
		
			while(validador == 0 && nodo != NULL) {
		if(strcmp(nombreAux,(nodo)->nombre) == 0){
				printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
					validador = 1;
				break;
			}
			else{
				printf("\nNo se encontro la imagen.");
				nodo = nodo->siguiente;
			i++;
			}
			}
		break;
	
	case 2:
		printf("Ingrese el codigo para la busqueda ");
		scanf("%d",&codigoAux);
		fflush(stdin);
		validador = 0;
		
		while(validador == 0 && nodo != NULL) {
			if(codigoAux == (nodo)->codigo){
				printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
				validador = 1;
				break;
			}
			else{
				printf("\nNo se encontro la imagen.");
				nodo = nodo->siguiente;
				i++;
			}
		}
		break;
		
	case 3:
		printf("Ingrese la extension para la busqueda ");
		fgets(extensionAux,19,stdin);
		validador = 0;
		
		while(validador == 0 && nodo != NULL) {
			if(strcmp(extensionAux,(nodo)->extension) == 0){
				printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
				break;
			}
			else{
				printf("\nNo se encontro la imagen.");
				nodo = nodo->siguiente;
				i++;
			}
		}
		break;
		
	case 4://tamano cambiar a v2
		printf("\nINFO: \n [1]: Buscar MAYOR A X(tamano)\n [2]: Buscar MENOR a X(tamano) ");
		scanf("%d", &seleccion);
		fflush(stdin);
		switch(seleccion){
			
		case 1:
			printf("Ingrese el parametro a definir ");
			scanf("%d", &tamanoAux);
			while( nodo != NULL){
				if( nodo->tamano > tamanoAux){
					printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
				nodo = nodo->siguiente;
					i++;
				}
				else{
					i++;
					nodo = nodo->siguiente;
				}
			}
			break;
		case 2:
			printf("Ingrese el parametro a definir ");
			scanf("%d", &tamanoAux);
			while( nodo != NULL){
				if( nodo->tamano < tamanoAux){
					printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
					nodo = nodo->siguiente;
					i++;
				}
				else{
					i++;
				nodo = nodo->siguiente;
				}
			}
			break;	  
		}
		break;
		
	case 5:
		printf("Ingrese el precio para la busqueda ");
		scanf("%d" ,&precioAux);
		fflush(stdin);
		validador = 0;
		
		while(validador == 0 && nodo != NULL) {
			if( precioAux == (nodo)->precio){
				printf("\nLa imagen fue encontrada en la imagen [%d]",i+1);
				validador = 1;
				break;
			}
			else{
				printf("\nNo se encontro la imagen.");
				nodo = nodo->siguiente;
				i++;
			}
			
		}
		break;
	}	
}
void mostrarListaOrdenada(struct Imagen *nodoActual, int cant){
	
	
	
	struct Imagen *nodo[cant], *aux;
	int i = 0, repeticiones=0;
	
	while(nodoActual != NULL){
		nodo[i] = nodoActual;
		nodoActual = nodoActual->siguiente;
		i++;
	}
	
	for( repeticiones=0 ; repeticiones< cant ; repeticiones++){
		for( i = 0 ; i < cant-1 ; i++){
			if( strcmp(nodo[i]->nombre/*str1*/, nodo[i+1]->nombre/*str2*/) > 0){
				aux = nodo[i];
				nodo[i] = nodo[i+1];	//ahora el primero es el menor
				nodo[i+1] = aux;	//el segundo ahora es el mayor
				
			}
		}
	}
	/*if Return value > 0 then it indicates str2 is less than str1.*/
	for( i = 0; i < cant ; i++){
		printf("\nNombre imagen:%s", nodo[i]->nombre);
		printf("Codigo imagen:%s", nodo[i]->codigo);
		printf("Tipo de imagen:%s",nodo[i]->extension);
		printf("Tamano de imagen:%d\n",nodo[i]->tamano);
		printf("Precio Imagen=%f\n", nodo[i]->precio);
	}
}
	
