#include <stdio.h>
void busquedaporparametro (char *palabra,int con){
	char cadena[150];
	int x=1,j=0;
	*palabra++;
	while(*palabra != '-'){
		if (con == 1){
		cadena[j]=*palabra;
		j++;
		}
		*palabra++;
		x++;
	}
	*palabra++;
	while(*palabra != '-'){
		if (con == 2){
			cadena[j]=*palabra;
			j++;
		}
		*palabra++;
		x++;
	}
	*palabra++;
	while(*palabra != '-'){
		if (con == 3){
			cadena[j]=*palabra;
			j++;
		}
		*palabra++;
		x++;
	}
	cadena[j]='\0';
	printf("\n\"%s\"",cadena);
}
int main(int argc, char *argv[]) {
	char matriz[6][150];
	int i,m,x,max,min,maxpos,minpos,espe=0,espepos;
	printf("\nIngrese 6 cadenas de longitud maxima 150, indicando -marca-modelo-n°serie-:");
	for(i=0;i<6;i++){
		printf("\nIngrese la cadena %d:",i);
		gets(matriz[i]);
	};
	while(m!=4){
	printf("\nIngrese al menú: \n1)Marcas. \n2)Modelo. \n3)N°serie. \n4)Salir.");
	scanf("%d",&m);
	switch (m){
	case 1:
		for (i=0;i<6;i++){
			busquedaporparametro(matriz[i],m);
		}
		break;
	case 2:
		for (i=0;i<6;i++){
			busquedaporparametro(matriz[i],m);
		}
		break;
	case 3:
		for (i=0;i<6;i++){
			busquedaporparametro(matriz[i],m);
		}
		break;
	default:
		printf("\nFin del programa.");
		break;
	}
	}
	return 0;
}

//-samsung-s23-44231-
//-motorola-G stylus-08977-
//-Samsung-S20-S8493874-
//-FIAT-Palio-5234523-
//-Platinum-Biblioteca tres estantes-BP435-//-xiaomi-redmi note 8-56489215-

