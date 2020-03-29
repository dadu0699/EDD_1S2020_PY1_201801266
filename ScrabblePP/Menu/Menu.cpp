#include "Menu.h"
#include <iostream>
#include <fstream>
// #include <typeinfo>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

Menu::Menu()
{
	readJSON("");
}

Menu::~Menu()
{
}

void Menu::principal()
{
	board = new SparseMatrix();
	dictionary = new CircularDoubleList();
	letters = new Queue();
	players = new BinarySearchTree();
	scoreBoard = new SortedSimpleList();

	int option;
	bool loop = true;
	while (loop)
	{
		cout << endl
			 << "\tMenu Principal";
		cout << endl
			 << "\t1. Iniciar";
		cout << endl
			 << "\t2. Escoger / Agregar / Reporte Jugadores";
		cout << endl
			 << "\t3. Tablero de puntuaci�n";
		cout << endl
			 << "\t4. Salir";
		cout << endl
			 << "\t >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			startGame();
			break;
		case 2:
			choosePlayer();
			break;
		case 3:
			scoreBoard->report();
			break;
		case 4:
			cout << endl
				 << "\tSALIENDO!!!!!!!!!!!!!!";
			loop = false;
			break;
		default:
			cout << endl
				 << "\tOPCION INCORRECTA";
			cout << endl;
			break;
		}
		system("CLS");
	}
}

void Menu::choosePlayer()
{
	string namePlayerOne;
	bool flagPlayerOne = false;
	DoubleList lettersPlayerOne;

	string namePlayerTwo;
	bool flagPlayerTwo = false;
	DoubleList lettersPlayerTwo;

	int option;
	bool loop = true;

	while (!flagPlayerOne || !flagPlayerTwo)
	{
		cout << endl
			 << "\t1. Escoger jugador";
		cout << endl
			 << "\t2. Agregar Jugador";
		cout << endl
			 << "\t3. Reporte Jugadores";
		cout << endl
			 << "\t >> ";
		cin >> option;

		switch (option)
		{
		case 1:
			if (!flagPlayerOne)
			{
				cout << endl
					 << "\t >> Jugador 1: ";
				cin >> namePlayerOne;
				playerOne = players->search(namePlayerOne);
				if (playerOne == nullptr)
				{
					cout << "\t El juador " << namePlayerOne << " no se ha registrado previamente";
				}
				else
				{
					playerOne->setTurn(true);
					flagPlayerOne = true;
				}
			}

			if (!flagPlayerTwo)
			{
				cout << endl
					 << "\t >> Jugador 2: ";
				cin >> namePlayerTwo;
				playerTwo = players->search(namePlayerTwo);
				if (playerTwo == nullptr)
				{
					cout << "\t El juador: " << namePlayerTwo << " no se ha registrado previamente";
				}
				else
				{
					flagPlayerTwo = true;
				}
			}
			break;
		case 2:
			if (!flagPlayerOne)
			{
				playerOne = new Player("", true);
				cout << endl
					 << "\t >> Jugador 1: ";
				cin >> namePlayerOne;
				playerOne->setName(namePlayerOne);
				flagPlayerOne = players->addNode(playerOne);
				if (!flagPlayerOne)
				{
					cout << "\t El juador " << namePlayerOne << " se ha registrado previamente";
				}
			}

			if (!flagPlayerTwo)
			{
				playerTwo = new Player("", false);
				cout << endl
					 << "\t >> Jugador 2: ";
				cin >> namePlayerTwo;
				playerTwo->setName(namePlayerTwo);
				flagPlayerTwo = players->addNode(playerTwo);
				if (!flagPlayerTwo)
				{
					cout << "\t El juador: " << namePlayerTwo << " se ha registrado previamente";
				}
			}
			break;
		case 3:
			players->report();
			return;
		default:
			cout << endl
				 << "\tOPCION INCORRECTA";
			cout << endl;
			break;
		}

		if (playerOne == playerTwo)
		{
			flagPlayerOne = false;
			flagPlayerTwo = false;
			cout << endl
				 << "\t No se puede escoger dos veces el mismo jugador";
		}
		cout << endl;
	}
	system("CLS");
}

void Menu::startGame()
{
	DoubleList lettersPlayerOne;
	DoubleList lettersPlayerTwo;
	for (int i = 0; i < 7; i++)
	{
		lettersPlayerOne.addLastNode(letters->pop()->getLetter());
		lettersPlayerTwo.addLastNode(letters->pop()->getLetter());
	}

	/*lettersPlayerOne.report();
	lettersPlayerTwo.report();*/
}

void Menu::readJSON(string route)
{
	ifstream jsonFile("properties.json");
	if (jsonFile.is_open())
	{
		json jsonData;
		jsonFile >> jsonData;

		cout << "Dimension: " << jsonData.at("dimension") << endl;
		cout << "Casillas: " << endl;
		cout << "\tDobles: " << endl;
		for (size_t i = 0; i < jsonData.at("casillas").at("dobles").size(); i++)
		{
			cout << "\t\tX: " << jsonData.at("casillas").at("dobles")[i].at("x") << endl;
			cout << "\t\tY: " << jsonData.at("casillas").at("dobles")[i].at("y") << endl;
		}
		cout << "\tTriples: " << endl;
		for (size_t i = 0; i < jsonData.at("casillas").at("triples").size(); i++)
		{
			cout << "\t\tX: " << jsonData.at("casillas").at("triples")[i].at("x") << endl;
			cout << "\t\tY: " << jsonData.at("casillas").at("triples")[i].at("y") << endl;
		}

		cout << "Diccionario: " << endl;
		for (size_t i = 0; i < jsonData.at("diccionario").size(); i++)
		{
			cout << "\tPalabra: " << jsonData.at("diccionario")[i].at("palabra") << endl;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}
