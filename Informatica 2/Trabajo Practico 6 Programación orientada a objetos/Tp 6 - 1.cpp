/*
Desarrollar una clase �Cadena� para el manejo de cadenas de caracteres.
Adem�s del constructor debe implementar como m�nimo 5 m�todos con
funcionalidades referidas a la manipulaci�n de cadenas: longitud, Concatenar,
Copiar, Buscar coincidencias por car�cter o por subcadena, etc. Demostrar el
funcionamiento de dicha Clase Cadena en el programa principal.*/
#include <iostream>
#include <cstring>

class Cadena {
private:
	char* cadena;
	
public:
	// Constructor
	Cadena(const char* str) {
		cadena = new char[strlen(str) + 1];
		strcpy(cadena, str);
	}
	
	// Destructor
	~Cadena() {
		delete[] cadena;
	}
	
	// M�todo para obtener la longitud de la cadena
	int longitud() const {
		return strlen(cadena);
	}
	
	// M�todo para concatenar dos cadenas
	void concatenar(const char* str) {
		char* temp = new char[strlen(cadena) + strlen(str) + 1];
		strcpy(temp, cadena);
		strcat(temp, str);
		delete[] cadena;
		cadena = temp;
	}
	
	// M�todo para copiar la cadena
	Cadena copiar() const {
		return Cadena(cadena);
	}
	
	// M�todo para buscar coincidencias por car�cter
	int buscarCaracter(char caracter) const {
		char* ptr = strchr(cadena, caracter);
		if (ptr != nullptr) {
			return ptr - cadena;
		} else {
			return -1;  // No se encontr� el car�cter
		}
	}
	
	// M�todo para buscar coincidencias por subcadena
	int buscarSubcadena(const char* subcadena) const {
		char* ptr = strstr(cadena, subcadena);
		if (ptr != nullptr) {
			return ptr - cadena;
		} else {
			return -1;  // No se encontr� la subcadena
		}
	}
	
	// M�todo para obtener la cadena como arreglo de caracteres
	const char* obtenerCadena() const {
		return cadena;
	}
};

int main() {
	// Ejemplo de uso de la clase Cadena
	std::cout<< "Ingrese una cadena: ";
	int menu=0;
	char input[100], agregar[100];
	std::cin.getline(input, sizeof(input));
	Cadena miCadena(input);
	do{
	std::cout << "Seleccione la opci�n: \n1).Longitud \n2).Concatenar \n3).Copiar \n4).Buscar coincidencias por car�cter \n5).Buscar coincidencias por subcadena \n6).Salir";
	std::cin >> menu;	
	
	switch(menu){
	case 1:
		std::cout << "Longitud de la cadena: " << miCadena.longitud() << std::endl;
		break;
	case 2:
		std::cout<< "Ingrese una cadena para concatenar: ";
		std::cin.ignore();
		std::cin.getline(agregar, sizeof(agregar));
		miCadena.concatenar(agregar);
		std::cout << "Cadena concatenada: " << miCadena.obtenerCadena() << std::endl;
		break;
	case 3:
		{
		Cadena copia = miCadena.copiar();
		std::cout << "Copia de la cadena: " << copia.obtenerCadena() << std::endl;
		break;
		}
	case 4:
		{
		char caracter;
		std::cout << "Ingrese un car�cter para buscar: ";
		std::cin.ignore();
		std::cin.get(caracter);
		int posCaracter = miCadena.buscarCaracter(caracter);
		if (posCaracter != -1) {
			std::cout << "Posici�n del car�cter '" << caracter << "': " << posCaracter << std::endl;
		}else {
			std::cout << "El car�cter '" << caracter << "' no se encontr� en la cadena." << std::endl;
		}
		}
		break;
	case 5:
		{
		std::cout << "Ingrese la subcadena que desea buscar: ";
		std::cin.ignore();
		std::cin.getline(agregar, sizeof(agregar));
		int posSubcadena = miCadena.buscarSubcadena(agregar);
		if (posSubcadena != -1) {
			std::cout << "Posici�n de la subcadena '" << agregar << "': " << posSubcadena << std::endl;
		} else {
			std::cout << "La subcadena '" << agregar << "' no se encontr� en la cadena." << std::endl;
		}
		}
		break;
	case 6:
		{
		std::cout << "Fin del programa.";
		break;
		}
	default:
		std::cout << "Opci�n incorrecta.";
		break;
	}
	} while (menu!=6);
	return 0;
}
