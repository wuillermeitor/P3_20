#include <iostream>
#include <string>
#include <fstream>
#include "Renderer.hh"
#include "ClashofEntios.hh"

//Declaración de variables.
std::ifstream file;
Map map;
std::vector<Entio>EntioPA;
std::vector<Entio>EntioPB;
std::vector<Entio>CurrentPlayer;
std::vector<Entio>NextPlayer;
enti::InputKey tecla;
bool game = false;

//Función que cambia de jugador en el bucle del juego.
void swapPlayer(std::vector<Entio>&Player1, std::vector<Entio>&Player2) {
	std::vector<Entio>aux = Player1;
	Player1 = Player2;
	Player2 = aux;
}

//Función que ordena los entios en función de su fatiga.
void ordenarPorFatiga(std::vector<Entio>&Entios) {
	std::vector<Entio> tmp;
	for (int i = 1; i < Entios.size(); i++) {
		for (int j = 0; j < Entios.size() - 1; j++) {
			if (Entios[j].fatiga > Entios[j + 1].fatiga) {
				tmp.push_back(Entios[j]);
				Entios[j] = Entios[j + 1];
				Entios[j + 1] = tmp.back();
			}
		}
	}
}

//Función del menú principal del juego. Gracias a enti::systempause, el juego no comenzará hasta que el jugador pulse alguna tecla.
void mainmenu() {
	enti::cout << enti::Color::YELLOW << "CLASH OF ENTIOS" << enti::endl << enti::endl;

	enti::cout << enti::Color::WHITE << "- Each player has 6 entios." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use WASD to move each entio." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use Z to undo a movement." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each entio has 2 weapons: 1 sword and 1 bow." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Press the SPACEBAR to use a weapon." << enti::endl;
	enti::cout << enti::Color::WHITE << "- The sword can instantly kill an enemy if it is placed in a cell next door." << enti::endl;
	enti::cout << enti::Color::WHITE << "- The bow can damage an enemy within a maximum distance of 10 cells." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each character has only 10 arrows." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each turn the less fatigued entio will play first." << enti::endl;
	enti::cout << enti::Color::WHITE << "- To play with the next entio press ENTER." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each player can do 10 of these actions per turn." << enti::endl << enti::endl;

	enti::cout << enti::Color::LIGHTMAGENTA << "Press any key to begin the game!" << enti::endl;

	enti::cout << enti::cend;

	enti::systemPause();
	game = true;
 }

//Función que vacía el stack de cada entio al final de turno.
void vaciarStack(std::vector<Entio>&Entios) {
	for (int i = 0; i < Entios.size(); i++) {
		while (Entios[i].lastRow.size() > 0 && Entios[i].lastCol.size() > 0) {
			Entios[i].lastRow.pop();
			Entios[i].lastCol.pop();
		}
	}
}

int main() {
	//Primero viene el menú principal, que aparecerá en pantalla hasta que el jugador pulse alguna tecla.
	mainmenu();

	//Una vez el jugador ha pulsado una tecla, se leerá el mapa, se llamará al constructor de la clase player y se le asignará
	//a los vectores CurrentPlayer y NextPlayer los vectores correspondientes.
	map.ReadMap(file, "default.cfg");
	Player player(&map, EntioPA, EntioPB);
	CurrentPlayer = EntioPA;
	NextPlayer = EntioPB;

	//Mientras el juego esté en marcha, se le irá pidiendo al jugador que pulse una tecla. Si el movimiento del player devuelve true,
	//significará que su turno ha acabado. Un ese caso, se vaciará el stack de los movimientos que han realizado los entios para que
	//en el turno siguiente no pueda pulsar z desde el principio. También se ordenarán los entios en función de su fatiga para que al
	//cambiar de jugador empieces con el entio con menor fatiga. Una vez hayan acabado los preparativos, se cambiarán los vectores
	//de los entios, se pondrá el booleano del jugador 1 a false (o true si ha acabado el turno del jugador 2) y se empezará a jugar
	//con el entio de la posición 0.
	while (game) {
		if (player.PlayerMovement(tecla, CurrentPlayer, NextPlayer)) {
			vaciarStack(CurrentPlayer);
			ordenarPorFatiga(CurrentPlayer);
			swapPlayer(CurrentPlayer, NextPlayer);
			player.player1torn = !player.player1torn;
			player.currentEntio = 0;
		}
		//Además, se imprimirá continuamente el mapa así como el hud, y se esperará a que el jugador pulse una tecla.
		map.drawMap(player.player1torn, CurrentPlayer, player.currentEntio);
		map.drawHUD(player.acciones, player.currentEntio, CurrentPlayer, NextPlayer, player.hit, player.attack, player.sword, player.bow);
		tecla = enti::getInputKey();
		//Finalmente, se comprobará si alguno de los vectores está vacío, y cuando el jugador pulse alguna tecla, terminará el juego.
		if (CurrentPlayer.size() == 0 || NextPlayer.size() == 0) {
			game = false;
			enti::systemPause();
			return 0;
		}
		//También podrá finalizar el juego si el jugador pulsa esc.
		if (tecla == enti::InputKey::ESC) {
			return 0;
		}
	}
}