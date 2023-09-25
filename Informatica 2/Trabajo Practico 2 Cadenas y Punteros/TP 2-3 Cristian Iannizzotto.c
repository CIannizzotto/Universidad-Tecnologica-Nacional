#include <stdio.h>
void analisisdecadena (char *puntero){
	int cantidad = 1, digitos = 0, especiales = 0;
	while (*puntero != '\0'){
		if (*puntero == ' '){
			cantidad++;
		}
		if (*puntero >= '0' && *puntero <= '9' ){
			digitos++;
		}
		if (!((*puntero <= 'z' && *puntero>='a')||(*puntero <= 'Z' && *puntero>='A')||(*puntero >= '0' && *puntero <= '9' ))){
			especiales++;
		}
		*puntero++;
	}
	printf("\nCantidad de palabras: %d", cantidad);
	printf("\nDígitos: %d", digitos);
	printf("\nCaracteres especiales: %d", especiales);
}
int main(int argc, char *argv[]) {
	char cadena1[100];
	printf("\nIngrese una cadena: ");
	gets(cadena1);
	analisisdecadena(cadena1);
	return 0;
}

//BZRP Music Sessions #36
