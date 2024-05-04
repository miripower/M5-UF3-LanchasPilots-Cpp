#include "Lancha.h"

int Lancha::getSpeed() {
	return speed;
}

void Lancha::setSpeed(int pSpeed) {
	speed = pSpeed;
}

int Lancha::getDistance() {
	return distance;
}

void Lancha::setDistance(int pDistance) {
	distance = pDistance;
}

int Lancha::getNitro() {
	return nitro;
}

void Lancha::setNitro(int pNitro) {
	nitro = pNitro;
}

std::string Lancha::getName() {
	return name;
}

void Lancha::setName(std::string pName) {
	name = pName;
}

void Lancha::getParameters() {
	std::cout << "Name: \x1B[32m" << name << "\x1B[37m \nSpeed: " << speed << "\nNitro:" << nitro << "\nDistance: " << distance << std::endl;
}

Lancha::Lancha() {

}

Lancha::Lancha(int pSpeed, int pDistance, int pNitro, std::string pName) {
	setSpeed(pSpeed);
	setDistance(pDistance);
	setNitro(pNitro);
	setName(pName);
}

void Lancha::throwDice() {
	int dice;
	char kbInput;

	std::cout << "\x1B[32m" << name << "\x1B[37m presiona el \033[1m\033[34m'espacio'\033[37m para lanzar el dado...\n" << std::endl;

	do {
		while (true) {
			Sleep(700);
			if (_kbhit) {
				kbInput = tolower(_getch());
				break;
			}
		}

		if (kbInput == ' ')
		{
			std::cout << "\x1B[32m" << name << "\x1B[37m se dispone a lanzar el dado...\n" << std::endl;
			Sleep(1000);

			const int numFrames = 10;
			for (int i = 0; i < numFrames; ++i) {
				dice = rand() % 6 + 1;
				std::cout << "\r\x1B[32m" << name << "\x1B[37m ha lanzado el dado y ha obtenido un \x1B[35m" << dice << "\x1B[37m...";
				std::cout.flush();
				Sleep(300);
			}

			speed += dice;
			std::cout << "\r\x1B[32m" << name << "\x1B[37m ha lanzado el dado y ha obtenido un \x1B[35m" << dice << "\x1B[37m. Su velocidad actual es: \x1B[35m" << speed << "\x1B[37m\n" << std::endl;
			Sleep(500);
		}
	} while (kbInput != ' ');
}

void Lancha::useNitro() {
	std::string askNitro = "n";
	char kbInput;

	std::cout << "\x1B[32m" << name << "\x1B[37m, quieres usar el nitro ? (S / N) : ";

	do {
		while (true) {
			Sleep(700);
			if (_kbhit) {
				kbInput = tolower(_getch());
				break;
			}
		}

		if (kbInput == 'S' || kbInput == 's' && nitro > 0) {
			nitro--;
			int randNum = rand() % 2;
			if (randNum == 0) {
				std::cout << "\nEl nitro ha \033[31mexplotado\033[37m rompiendo el motor, la velocidad de \x1B[32m" << name << "\x1B[37m se reduce a la mitad\n" << std::endl;
				speed = speed / 2;
			}
			else if (randNum == 1) {
				std::cout << "\nEl nitro ha funcionado \033[32mperfectamente\033[37m, la velocidad de \x1B[32m" << name << "\x1B[37m se ha duplicado\n" << std::endl;
				speed = speed * 2;
			}
		}
		else if (kbInput == 'S' || kbInput == 's' && nitro <= 0) {
			std::cout << "\n\x1B[32m" << name << "\x1B[37m, no puedes usar el nitro, no te quedan usos\n" << std::endl;
		}
		else if (kbInput == 'N' || kbInput == 'n') {
			std::cout << "\n\x1B[32m" << name << "\x1B[37m no usa el nitro esta ronda\n" << std::endl;
		}
	} while (kbInput != 'N' && kbInput != 'n' && kbInput != 'S' && kbInput != 's');
}

void Lancha::calculateDistance() {
	distance += speed * 100;
	std::cout << "\nCalculando la distanica recorrida por el piloto \x1B[32m" << name << "\x1B[37m";
	Sleep(1000);
	std::cout << ". ";
	Sleep(1000);
	std::cout << ". ";
	Sleep(1000);
	std::cout << "." << std::endl;
	Sleep(1000);
	std::cout << "El piloto \x1B[32m" << name << "\x1B[37m ha recorrido una distancia de \x1B[34m" << distance << "\033[37m metros" << std::endl;
	Sleep(1000);
}

void Lancha::gameMenu() {
	std::cout << "/-----------------------------------------------------------------------------\\" << std::endl;
	std::cout << "|Pilot Name: \x1B[32m" << name << "\x1B[37m Actual Speed: \x1B[35m" << speed << "\x1B[37m Distance traveled: \x1B[34m" << distance << "\x1B[37m Nitro uses: " << nitro << "\x1B[37m|" << std::endl;;
	std::cout << "\\-----------------------------------------------------------------------------/\n" << std::endl;
}

void Lancha::initScreen() {
	std::cout << " _               _   _  _____ _    _           _____ " << std::endl;
	std::cout << "| |        /\\   | \\ | |/ ____| |  | |   /\\    / ____|" << std::endl;
	std::cout << "| |       /  \\  |  \\| | |    | |__| |  /  \\  | (___  " << std::endl;
	std::cout << "| |      / /\\ \\ | . ` | |    |  __  | / /\\ \\  \\___ \\ " << std::endl;
	std::cout << "| |____ / ____ \\| |\\  | |____| |  | |/ ____ \\ ____) |" << std::endl;
	std::cout << "|______/_/__ _\\_\\_|_\\_|\\_____|_|__|_/_/    \\_\\_____/ " << std::endl;
	std::cout << "|  __ \\_   _| |    / __ \\__   __/ ____|              " << std::endl;
	std::cout << "| |__) || | | |   | |  | | | | | (___                " << std::endl;
	std::cout << "|  ___/ | | | |   | |  | | | |  \\___ \\               " << std::endl;
	std::cout << "| |    _| |_| |___| |__| | | |  ____) |              " << std::endl;
	std::cout << "|_|   |_____|______\\____/  |_| |_____/               " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "		               __/___            " << std::endl;
	std::cout << "		         _____/______|           " << std::endl;
	std::cout << "		 _______/_____\\_______\\_____     " << std::endl;
	std::cout << "		 \\              < < <       |    " << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "- Selecciona una de las siguientes opciones -" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "1.- INICIAR JUEGO -" << std::endl;
	std::cout << std::endl;
	std::cout << "0.- SALIR -" << std::endl;
	std::cout << std::endl;
}