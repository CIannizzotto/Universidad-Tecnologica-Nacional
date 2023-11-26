#include <iostream>
#include <ctime>

class Cronometro {
private:
	clock_t inicio;
	clock_t fin;
	bool corriendo;
	
public:
	Cronometro() : corriendo(false) {}
	
	// Iniciar el temporizador
	void iniciar() {
		if (!corriendo) {
			inicio = clock();
			corriendo = true;
		}
	}
	
	// Detener el temporizador
	void detener() {
		if (corriendo) {
			fin = clock();
			corriendo = false;
		}
	}
	
	// Regresar la cantidad de tiempo transcurrido en milisegundos
	double tiempoTranscurridoEnMilisegundos() const {
		if (corriendo) {
			clock_t tiempoActual = clock();
			return static_cast<double>(tiempoActual - inicio) / CLOCKS_PER_SEC * 1000.0;
		} else {
			return static_cast<double>(fin - inicio) / CLOCKS_PER_SEC * 1000.0;
		}
	}
	
	// Resetear el temporizador
	void resetear() {
		inicio = 0;
		fin = 0;
		corriendo = false;
	}
};

int main() {
	Cronometro cronometro;
	int menu = 0;
	
	do{
		std::cout << "Seleccione la opción: \n1).Iniciar el temporizador \n2).Detener el temporizador \n3).Tiempo transcurrido \n4).Resetear \n5).Salir \n";
		std::cin >> menu;	
		
		switch(menu){
		case 1:
			cronometro.iniciar();
			break;
		case 2:
			cronometro.detener();
			break;
		case 3:
		{
			double tiempoMillisegundos = cronometro.tiempoTranscurridoEnMilisegundos();
			std::cout << "Tiempo transcurrido en milisegundos: " << tiempoMillisegundos << " ms" << std::endl;
			break;
		}
		case 4:
		{
			cronometro.resetear();
			break;
		}
		case 5:
		{
			std::cout << "Fin del programa.";
			break;
		}
		default:
			std::cout << "Opción incorrecta.";
			break;
		}
	} while (menu!=5);
	return 0;
}
