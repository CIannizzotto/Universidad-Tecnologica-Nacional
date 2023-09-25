#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sensor{
	char marca[30];
	char sensores[25];
	char medicion[10];
};
struct sensor sensor1={"ABB","Calorico\n","Celsius"};
struct sensor sensor2={"HC-SR04","UltraSonico\n","m"};
struct sensor sensor3={"Siemens","Presion\n","atm"};

struct fechasMedicion{
	int dia;
	int mes;
	int anio;
};

struct mediciones{
	struct sensor stockSensores;
	struct fechasMedicion fecha;
	char hora[30];
	int valorMedido;
	char comentarios[200]; 
	struct mediciones *siguiente;
	struct mediciones *previo;
}Primera={"ABB","Calorico\n","Celsius",16,03,2021, "18:00\n", 10, "Valor correcto\n" };

struct mediciones *agregarMedicion(struct mediciones *nodo, int total);
struct mediciones *eliminarMedicion(struct mediciones *nodo, int total);
void mostrarListaOrdenada( struct mediciones *nodo, int total);
void buscarDato(struct mediciones *nodo, int total);
void imprimir(struct mediciones *nodo);
void grabarArchivo(FILE *archivo, struct mediciones *nodo, int total);
void imprimirArchivo(FILE *archivo, int total);

int main() {
	int cantidad=50, total=1, menu;
	FILE *archivoMediciones;
	struct mediciones *inicio = &Primera;
	struct mediciones *ultimo = NULL;
	
	do {									/**	LLAVE DO WHILE    **/
		printf("\nINFO: \n [1]: Agregar medicion\n [2]: Eliminar medicion\n [3]: Buscar algun dato\n [4]: Imprimir Lista\n [5]: Grabar Archivo\n [6]: Leer Archivo\n [7]: Mostrar Lista por fecha\n [8]: Salir	");
		scanf("%d", &menu);
		fflush(stdin);
		
		switch(menu){/**	LLAVE SWITCH    **/
			
		case 1:
			if(total < cantidad){
				ultimo = agregarMedicion(inicio, total);
				total++;
			}
			else{
				printf("Ya se superó la cantidad maxima de mediciones");
			}
			break;
			
		case 2:
			inicio = eliminarMedicion(inicio, total);
			total--;
			break;
		case 3:
			buscarDato(inicio, total);
			break;
		case 4:
			imprimir(inicio);
			break;
		case 5:
			grabarArchivo(archivoMediciones, inicio, total);
			break;
		case 6:
			imprimirArchivo(archivoMediciones, total);
			break;
		case 7:
			mostrarListaOrdenada(inicio, total);
			
		}
		
	} while( menu >= 1 && menu < 8);
	
	return 0;
}

struct mediciones *agregarMedicion(struct mediciones *nodo, int total){
	
	int seleccionSensor=0;
	
	struct mediciones *nuevoNodo = (struct mediciones*) malloc(sizeof(struct mediciones));
	do {
		printf("\nElija un sensor para la medicion\n[0]Sensor:Calorico\n[1]Sensor:Ultrasonico\n[2]Sensor:Presion ");
		scanf("%d", &seleccionSensor);
		fflush(stdin);
	} while (seleccionSensor < 0 || seleccionSensor > 2);
	
	switch(seleccionSensor){
	case 0:
		(nuevoNodo)->stockSensores = sensor1;
		
		printf("Escriba la fecha: Dia de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.dia));;
		getchar();
		
		printf("Escriba la fecha: Mes de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.mes));;
		getchar();
		
		printf("Escriba la fecha: Anio de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.anio));;
		getchar();
		
		printf("Escriba la hora de la medicion ");
		fgets( (nuevoNodo)->hora, 20, stdin);
		
		printf("Escriba el valor medido de la medicion ");
		scanf("%d", &((nuevoNodo)->valorMedido));
		getchar();
		
		printf("Escriba los comentarios de la medicion ");
		fgets( (nuevoNodo)->comentarios, 200, stdin);
		
		
		while(nodo->siguiente != NULL){
			nodo = nodo->siguiente;
		}
		nodo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		nuevoNodo->previo = nodo;
		break;
	case 1:
		(nuevoNodo)->stockSensores = sensor2;
		
		printf("Escriba la fecha: Dia de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.dia));;
		getchar();
		
		printf("Escriba la fecha: Mes de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.mes));;
		getchar();
		
		printf("Escriba la fecha: Anio de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.anio));;
		getchar();
		
		printf("Escriba la hora de la medicion ");
		fgets( (nuevoNodo)->hora, 20, stdin);
		
		printf("Escriba el valor medido de la medicion ");
		scanf("%d", &((nuevoNodo)->valorMedido));
		getchar();
		
		printf("Escriba los comentarios de la medicion ");
		fgets( (nuevoNodo)->comentarios, 200, stdin);
		
		while(nodo->siguiente != NULL){
			nodo = nodo->siguiente;
		}
		
		nodo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		nuevoNodo->previo = nodo;
		break;
	case 2:
		(nuevoNodo)->stockSensores = sensor3;
		
		printf("Escriba la fecha: Dia de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.dia));;
		getchar();
		
		printf("Escriba la fecha: Mes de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.mes));;
		getchar();
		
		printf("Escriba la fecha: Anio de la medicion ");
		scanf("%d", &((nuevoNodo)->fecha.anio));;
		getchar();
		
		printf("Escriba la hora de la medicion ");
		fgets( (nuevoNodo)->hora, 20, stdin);
		
		printf("Escriba el valor medido de la medicion ");
		scanf("%d", &((nuevoNodo)->valorMedido));
		getchar();
		
		printf("Escriba los comentarios de la medicion ");
		fgets( (nuevoNodo)->comentarios, 200, stdin);
		
		while(nodo->siguiente != NULL){
			nodo = nodo->siguiente;
		}
		
		nodo->siguiente = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		nuevoNodo->previo = nodo;
		break;
	}
	return nuevoNodo;
}
	
struct mediciones *eliminarMedicion (struct mediciones *nodo, int total){
	
	int seleccion;
	struct mediciones *aux = nodo;
	struct mediciones *temp;
	
	do {
		printf("¿Que medicion desea eliminar? (0 a %d) ", total-1);
		scanf("%d", &seleccion);
		fflush(stdin);
	} while (seleccion > total);
	
	if(seleccion == 0){
		aux = nodo->siguiente;
		aux->siguiente->previo = aux;
		free(nodo);
		return aux;
	}
	
	if(seleccion == total-1){
		
		while(nodo->siguiente->siguiente != NULL){
			nodo = nodo->siguiente;
		}
		nodo->siguiente = NULL;
		return aux;
	}
	
	for(int i = 0; i<seleccion-1 ; i++){
		nodo = nodo->siguiente;
	}
	
	temp = nodo->siguiente;//apunta al qu queremos eliminar
	nodo->siguiente = temp->siguiente;//apunta alsiguiente del que queremos eliminar
	
	temp->siguiente->previo = nodo;
	free(temp);
	return aux;
}
		
void mostrarListaOrdenada(struct mediciones *nodo, int total){
	
	int repeticiones = 0, i=0;
	struct mediciones *nodos[total], *aux;
	
	while(nodo != NULL){
		nodos[i]=nodo;
		nodo = nodo->siguiente;
		i++;
	}
	
	for(repeticiones = 0 ; repeticiones < total ; repeticiones++){
		for(i = 0 ; i < total-1 ; i++){
			
			if ( nodos[i]->fecha.anio > nodos[i+1]->fecha.anio ){
				aux=nodos[i];
				nodos[i]=nodos[i+1];
				nodos[i+1] = aux;
			}
			else if(nodos[i]->fecha.anio == nodos[i+1]->fecha.anio){//si se cumple que son iguales...
				
				if(nodos[i]->fecha.mes > nodos[i+1]->fecha.mes) {
					aux = nodos[i];
					nodos[i] = nodos[i + 1];
					nodos[i+1] = aux;
				}
				else if(nodos[i]->fecha.mes == nodos[i+1]->fecha.mes){
					
					if(nodos[i]->fecha.dia > nodos[i+1]->fecha.dia){
						aux = nodos[i];
						nodos[i] = nodos[i + 1];
						nodos[i+1] = aux;
					}
				}
			}
		}
	}
	/*si el anio del sig es menor, ordeno, si no ,debo preguntar si son iguales
	si son iguales los anios entonces pregunto si el 	mes del sig es menor, ordeno
	si no pregunto si son iguales
	si los meses y los anios son iguales entonces solo queda comparar dias
	si el dia del sig es menor ordeno*/
	
	for(i=0; i<total ; i++){
		printf("\nMedicion[%d]: ",i);
		printf("\nMarca:%s\nTipo:%sUnidad:%s", nodos[i]->stockSensores.marca,  nodos[i]->stockSensores.sensores,  nodos[i]->stockSensores.medicion);
		printf("\nFecha: %d/%d/%d\n", nodos[i]->fecha.dia, nodos[i]->fecha.mes, nodos[i]->fecha.anio);
		printf("Hora: %s", nodos[i]->hora);
		printf("Valor: %d", nodos[i]->valorMedido);
		printf("\nComentarios: %s", nodos[i]->comentarios);
	}
}
			
void buscarDato(struct mediciones *nodo, int total){
	
	int aux, i=0, menu, valorMedidoAux;
	char sensorAux[30];
	
	do {
		printf("\nINFO: \n [1]: Buscar por SENSOR\n [2]: Buscar por VALOR MEDIDO	");
		scanf("%d", &aux);
		getchar();
	} while (aux < 1 || aux > 3 );
	
	switch(aux){
		
	case 1:
		printf("Ingrese el sensor a buscar POR TIPO ");
		fgets(sensorAux, 30 , stdin);
		while(nodo != NULL){
			if(strcmp(sensorAux, nodo->stockSensores.sensores) == 0){
				printf("\nLa medicion ha sido encontrada en la medicion [%d]\n", i);
				i++;
				nodo=nodo->siguiente;
			}
			else{
				i++;
				nodo = nodo->siguiente;
			}
		}
		break;
	case 2:
		printf("[1]: Buscar MAYOR a X valor\n[2]: Buscar MENOR a X valor ");
		scanf("%d", &menu);
		getchar();
		switch(menu){
		case 1:
			printf("Ingrese el valor de referencia ");
			scanf("%d", &valorMedidoAux);
			getchar();
			
			while(nodo != NULL){
				if( nodo->valorMedido > valorMedidoAux){
					printf("\nLa medicion se encontro en la medicion [%d]\n", i);
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
			printf("Ingrese el valor de referencia ");
			scanf("%d", &valorMedidoAux);
			getchar();
			
			while(nodo != NULL){
				if( nodo->valorMedido < valorMedidoAux){
					printf("\nLa medicion se encontro en la medicion [%d]\n", i);
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
	}	
}
				
void imprimir(struct mediciones *nodoactual){
	
	int i=0;
	while(nodoactual != NULL){
		printf("\nMedicion[%d]: ",i);
		printf("\nMarca:%s\nTipo:%sUnidad:%s", nodoactual->stockSensores.marca,  nodoactual->stockSensores.sensores,  nodoactual->stockSensores.medicion);
		printf("\nFecha: %d/%d/%d\n", nodoactual->fecha.dia, nodoactual->fecha.mes, nodoactual->fecha.anio);
		printf("Hora: %s", nodoactual->hora);
		printf("Valor: %d", nodoactual->valorMedido);
		printf("\nComentarios: %s", nodoactual->comentarios);
		i++;
		nodoactual = nodoactual->siguiente;
	}
}
	
void grabarArchivo(FILE *archivo, struct mediciones *nodo, int total){

	archivo = fopen("Mediciones.bin","ab");
	if(archivo == NULL){
		printf("\nError al abrir el archivo");
	}
	else{
	printf("\nArchivo abierto correctamente!");	
		while(nodo != NULL) {
			fwrite(nodo, sizeof(struct mediciones), 1, archivo);
			nodo=nodo->siguiente;
		}
	}
	printf("\nArchivo Guardado correctamente!!");
	fclose(archivo);
}
	
void imprimirArchivo(FILE *archivo, int total){
	
	int i=0;
	const int leer = 1;
	struct mediciones nodoBin;
	archivo = fopen("Mediciones.bin","rb");
	if(archivo == NULL){
		printf("\nError al abrir el archivo");
	}
	else{
		rewind(archivo);
		while( (fread(&nodoBin, sizeof(struct mediciones), leer, archivo)) == leer){
			/*fread devuelve la cantidad de elementos leidos con exito, si el numero devuelto es 
			distinto al numero entero ingresado en la funcion fread significa que hay un error
			para encontrar el feof (size_t fread(...))  */
			
			printf("\nMedicion[%d]: ",i);
			printf("\nMarca:%s\nTipo:%sUnidad:%s", nodoBin.stockSensores.marca,  nodoBin.stockSensores.sensores,  nodoBin.stockSensores.medicion);
			printf("\nFecha: %d/%d/%d\n", nodoBin.fecha.dia, nodoBin.fecha.mes, nodoBin.fecha.anio);
			printf("Hora: %s", nodoBin.hora);
			printf("Valor: %d", nodoBin.valorMedido);
			printf("\nComentarios: %s", nodoBin.comentarios);
			i++;
		}
	}
	fclose(archivo);
}

