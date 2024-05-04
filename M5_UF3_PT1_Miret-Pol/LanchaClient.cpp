#include "Lancha.h"

int main() {
	srand(time(0));
	char kbInput = 0;
	const int maxNumOfRounds = 5;
	std::string player1Name;
	std::string player2Name;


	do {
		Lancha::initScreen();

		while (true) {
			Sleep(700);
			if (_kbhit) {
				kbInput = tolower(_getch());
				break;
			}
		}
		system("cls");

		if (kbInput == '1') {
			std::cout << "Numero de jugadores: 2\n" << std::endl;
			std::cout << "Elige el nombre de tu piloto Jugador 1:\x1B[32m ";
			std::getline(std::cin, player1Name);

			std::cout << "\n\033[37mElige el nombre de tu piloto Jugador 2:\x1B[32m ";
			std::getline(std::cin, player2Name);

			std::cout << "\n\033[37mPreparaos para la carrera..." << std::endl;

			std::cout << "\nLa carrera empieza en: " << std::endl;
			std::cout << "\n\033[31m...3...\033[37m" << std::endl;
			Sleep(1000);
			std::cout << "\n\033[1m\033[31m ..2..\033[37m" << std::endl;
			Sleep(1000);
			std::cout << "\n\033[33m  .1.\033[37m" << std::endl;
			Sleep(1000);
			std::cout << "\n\033[32m START\033[37m" << std::endl;
			Sleep(1000);

			system("cls");

			Lancha lancha1 = Lancha(0, 0, 1, player1Name);
			Lancha lancha2 = Lancha(0, 0, 1, player2Name);

			int countNumOfRounds = 0;
			while (countNumOfRounds < maxNumOfRounds) {

				lancha1.gameMenu();
				lancha2.gameMenu();

				std::cout << "Turno " << countNumOfRounds + 1 << "/" << maxNumOfRounds << "\n" << std::endl;

				lancha1.throwDice();
				lancha1.useNitro();

				lancha2.throwDice();
				lancha2.useNitro();

				lancha1.calculateDistance();
				lancha2.calculateDistance();

				countNumOfRounds++;
				Sleep(1000);

				system("pause");
				system("cls");
			}

			std::cout << "- RESULTADOS DE LA CARRERA -\n" << std::endl;
			std::cout << "\x1B[32m" << lancha1.getName() << "\x1B[37m ha recorrido una distancia de \x1B[34m" << lancha1.getDistance() << "\x1B[37m metros\n" << std::endl;
			std::cout << "\x1B[32m" << lancha2.getName() << "\x1B[37m ha recorrido una distancia de \x1B[34m" << lancha2.getDistance() << "\x1B[37m metros\n" << std::endl;
			
			if (lancha1.getDistance() > lancha2.getDistance()) {
				std::cout << "\x1B[32m" << lancha1.getName() << "\x1B[37m ha ganado" << std::endl;
			}
			else if (lancha1.getDistance() < lancha2.getDistance()) {
				std::cout << "\x1B[32m" << lancha2.getName() << "\x1B[37m ha ganado" << std::endl;
			}
			else {
				std::cout << "Empate..." << std::endl;
			}
			
			std::cout << "\n\n- Selecciona una de las siguientes opciones -" << std::endl;
			std::cout << "\n2.- VOLER A JUGAR -" << std::endl;
			std::cout << "\n0.- SALIR -" << std::endl;

			do {
				while (true) {
					Sleep(700);
					if (_kbhit) {
						kbInput = tolower(_getch());
						break;
					}
				}
			} while (kbInput != '0' && kbInput != '2');

			if (kbInput == '2') {
				system("cls");
				continue;
			}

			system("cls");
		}

	} while (kbInput != '0');

	std::cout << "Espramos que vuelvas a jugar pronto a LANCHAS PILOTS <3\n" << std::endl;

	return 0;
}