#include <stdio.h>
int tamano (char *palabra){
	int x=0;
	while(*palabra != '\0'){
		*palabra++;
		x++;
	}
	return x;
}

int main(int argc, char *argv[]) {
	char cadena1[100];
	int lon;
	printf("\nIngrese una cadena: ");
	gets(cadena1);
	lon=tamano(cadena1);
	printf("\nEl tamaño de la cadena es: %d",lon);
	return 0;
}

