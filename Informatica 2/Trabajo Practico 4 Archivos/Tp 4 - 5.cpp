#include <stdio.h>
#include <string.h>

struct estructura{
	char marca[30];
	char tipo[30];
	char unidad[30];
}sensores[4];

struct estructura2{
	char fecha[30];
	char hora[30];
	struct estructura sensor;
	int valor;
	char comentarios[500];
	int sindice;
}medicion[5];

void nuevo(int indice, char fecha[], char hora[], int sindice, int valor, char comentarios[]){
	strcpy(medicion[indice].fecha, fecha);
	strcpy(medicion[indice].hora, hora);
	strcpy(medicion[indice].sensor.marca, sensores[sindice].marca);
	strcpy(medicion[indice].sensor.tipo, sensores[sindice].tipo);
	strcpy(medicion[indice].sensor.unidad, sensores[sindice].unidad);
	medicion[indice].valor = valor;
	medicion[indice].sindice=sindice;
	strcpy(medicion[indice].comentarios, comentarios);
}
	
void modificar(int indice, int f){
	char fecha[30], hora[30], comentarios[500];
	int sindice, valor;
	switch(f){
	case 1: 
		printf("Ingrese la fecha nueva\n");
		gets(fecha);
		strcpy(medicion[indice].fecha, fecha);
		break;
	case 2: 
		printf("Ingrese la hora nueva\n");
		gets(hora);
		strcpy(medicion[indice].hora, hora);
		break;
	case 3: 
		printf("Ingrese el sensor nuevo\n");
		scanf("%d", &sindice);
		fflush(stdin);
		strcpy(medicion[indice].sensor.marca, sensores[sindice].marca);
		strcpy(medicion[indice].sensor.tipo, sensores[sindice].tipo);
		strcpy(medicion[indice].sensor.unidad, sensores[sindice].unidad);
		break;
	case 4:
		printf("Ingrese el valor nuevo\n");
		scanf("%d", &valor);
		fflush(stdin);
		medicion[indice].valor = valor;
		break;
	case 5: 
		printf("Ingres comentarios nuevos\n");
		gets(comentarios);
		strcpy(medicion[indice].comentarios, comentarios);
		break;
	}	
}
		
void buscar(int f){
	char fecha[30];
	int sindice, valor, i, resultado=0;;
	switch(f){
	case 1: 
		printf("Ingrese una fecha:\n");
		fgets(fecha, 30, stdin);
		for(i=0;i<5;i++){
			if(strcmp(medicion[i].fecha, fecha)==0){
				printf("\nFecha: ");
				puts(medicion[i].fecha);
				printf("Hora: ");
				puts(medicion[i].hora);
				printf("Marca del sensor: ");
				puts(medicion[i].sensor.marca);
				printf("\nTipo: ");
				puts(medicion[i].sensor.tipo);
				printf("\nValor medido: %d ", medicion[i].valor);
				puts(medicion[i].sensor.unidad);
				printf("\nComentarios: ");
				puts(medicion[i].comentarios);
				resultado=1;
			}
		}
		break;
	case 2:
		printf("Ingrese un sensor:\n");
		scanf("%d", &sindice);
		fflush(stdin);
		for(i=0;i<5;i++){
			if(medicion[i].sindice==sindice){
			printf("\nFecha: ");
			puts(medicion[i].fecha);
			printf("\nHora: ");
			puts(medicion[i].hora);
			printf("\nMarca del sensor: ");
			puts(medicion[i].sensor.marca);
			printf("\nTipo: ");
			puts(medicion[i].sensor.tipo);
			printf("\nValor medido: %d %s", medicion[i].valor, medicion[i].sensor.unidad);
			printf("\nComentarios: ");										
			puts(medicion[i].comentarios);
			resultado=1;
			}
		}
		break;
	case 3: 
		printf("Ingrese un valor:\n");
		scanf("%d", &valor);
		fflush(stdin);
		for(i=0;i<5;i++){
			if(medicion[i].valor==valor){
				printf("\nFecha: ");
				puts(medicion[i].fecha);
				printf("\nHora: ");
				puts(medicion[i].hora);
				printf("\nMarca del sensor: ");
				puts(medicion[i].sensor.marca);
				printf("\nTipo: ");
				puts(medicion[i].sensor.tipo);
				printf("\nValor medido: %d ", medicion[i].valor);
				puts(medicion[i].sensor.unidad);
				printf("\nComentarios: ");
				puts(medicion[i].comentarios);
				resultado=1;
			}
		}
		break;
	}
	if(resultado==0){
		printf("No hay mediciones que coincidan con el criterio de busqueda\n");
	}
}
void eliminar(int indice){
	strcpy(medicion[indice].fecha, "\0");
	strcpy(medicion[indice].hora,  "\0");
	strcpy(medicion[indice].sensor.marca, "\0");
	strcpy(medicion[indice].sensor.tipo, "\0");
	strcpy(medicion[indice].sensor.unidad, "\0");
	strcpy(medicion[indice].comentarios, "\0");
	medicion[indice].valor=0;
	printf("Medicion eliminada\n");
}
void guardarMedicionesEnArchivo(const char *nombreArchivo) {
		FILE *archivo = fopen(nombreArchivo, "wb"); // Abre el archivo en modo binario
		
		if (archivo == NULL) {
			printf("No se pudo abrir el archivo para guardar las mediciones.\n");
			return;
		}
		
		// Escribir el arreglo de mediciones en el archivo
		fwrite(medicion, sizeof(struct estructura2), 5, archivo);
		
		fclose(archivo);
		printf("Mediciones guardadas exitosamente en el archivo.\n");
	}
	
	// Función para cargar el arreglo de mediciones desde un archivo binario
void cargarMedicionesDesdeArchivo(const char *nombreArchivo) {
		FILE *archivo = fopen(nombreArchivo, "rb"); // Abre el archivo en modo binario
		
		if (archivo == NULL) {
			printf("No se pudo abrir el archivo para cargar las mediciones.\n");
			return;
		}
		
		// Leer el arreglo de mediciones desde el archivo
		fread(medicion, sizeof(struct estructura2), 5, archivo);
		
		fclose(archivo);
		printf("Mediciones cargadas exitosamente desde el archivo.\n");
	}
	
	int main(){
	char fecha[30], hora[30], comentarios[500];
	int indice, sindice, valor, e, f, ocupado[5]={0, 0, 0, 0, 0};
	strcpy(sensores[1].marca,"SIEMENS");
	strcpy(sensores[1].tipo, "Temperatura");
	strcpy(sensores[1].unidad,"Kelvin");
	strcpy(sensores[2].marca,"Arduino");
	strcpy(sensores[2].tipo, "Corriente");
	strcpy(sensores[2].unidad,"Amperes");
	strcpy(sensores[3].marca,"Arduino");
	strcpy(sensores[3].tipo, "Voltaje");
	strcpy(sensores[3].unidad,"Volts");
	
	while(e!=5){
		printf("Elija una opcion:\n1. Agregar una medicion nueva\n2. Eliminar una medicion\n3. Modificar una medicion\n4. Buscar una medicion\n5. Salir\n");
		scanf("%d",&e);
		fflush(stdin);
		switch(e){
		case 1:
			printf("Ingrese un espacio 0-4, la fecha, hora, el sensor utilizado 1-3, el valor medido y comentarios o ingrese 5 para volver al menu\n");
			do{
				scanf("%d",&indice);
				fflush(stdin);
				if(ocupado[indice]==1){
					printf("Ese espacio ya esta ocupado, ingrese uno nuevo, o ingrese 5 para volver al menu\n");
				}
			}while(ocupado[indice]==1);
			if(indice!=5){
				fgets(fecha, 30, stdin);
				fgets(hora, 30, stdin);
				scanf("%d",&sindice);
				fflush(stdin);
				scanf("%d",&valor);
				fflush(stdin);
				gets(comentarios);
				nuevo(indice, fecha, hora, sindice, valor, comentarios);
				ocupado[indice]=1;
			}
			break;
		case 2:
			printf("Ingrese el espacio 0-4 de la medicion que desea eliminar\n");
			do{
				scanf("%d",&indice);
				fflush(stdin);
				if(ocupado[indice]==0){
					printf("Esa medicion no existe, ingrese una nueva, o ingrese 5 para volver al menu\n");
				}
			}while(ocupado[indice]==0);
			if(indice!=5){
				eliminar(indice);
			}
			break;
		case 3:
			printf("Ingrese el espacio de la medicion 0-4, y que elemento desea modificar:\n1. Fecha\n2. Hora\n3. Sensor\n4. Valor\n5. Comentarios\nO ingrese 6 para volver al menu\n");
			do{
				scanf("%d",&indice);
				fflush(stdin);
				if(ocupado[indice]==0){
					printf("Esa medicion no existe, ingrese una nueva, o ingrese 6 para volver al menu\n");
				}
			}while(ocupado[indice]==0);
			if(indice!=6){
				scanf("%d", &f);
				fflush(stdin);
				modificar(indice, f);
			}
			break;
		case 4: 
			printf("\n1. Buscar por fecha\n2. Buscar por sensor\n3. Buscar por valor\n");
			scanf("%d", &f);
			fflush(stdin);
			buscar(f);
			break;
		case 5:
			guardarMedicionesEnArchivo("mediciones.dat");
			printf("Fin del programa.\n");
			break;
		default:
			printf("Opción no válida.\n");
			break;
		}
	}
}
