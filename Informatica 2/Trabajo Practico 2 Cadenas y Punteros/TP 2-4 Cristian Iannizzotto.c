#include <stdio.h>
int tamano (char *palabra){
	int x=0;
	while(*palabra != '\0'){
		*palabra++;
		x++;
	}
	return x;
}
void alreves (int lon, char *palabra){
	char cadena[100],aux;
	int i=0,f,g;
	cadena[lon]='\0';
	while(*palabra != '\0'){
		cadena[i]=*palabra;
		*palabra++;
		i++;
	}
	for (g=0;g<lon;g++){
	for (f=0;f<lon-g;f++){
		if (cadena[f]<cadena[f+1]){
			aux=cadena[f];
			cadena[f]=cadena[f+1];
			cadena[f+1]=aux;
		}
	}
	}
	printf("\nLa cadena es: \"%s\"",cadena);
}
int main(int argc, char *argv[]) {
	char cadena1[100];
	int lon;
	printf("\nIngrese una cadena: ");
	gets(cadena1);
	lon = tamano(cadena1);
	alreves(lon,cadena1);
	return 0;
}

//zapato
