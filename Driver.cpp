#include "TicTacToe.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string nameX;
	string nameO;
	int size;
	
	cout << "Please, enter the game board size: ";
	cin >> size;
	cin.get();
	cout << "Game size is set to: " << size << "x" << size << endl;

	TicTacToe game1(size);

	cout << "Player 1, enter your name: ";
	getline(cin, nameX);
	cout << "Player 2, enter your name: ";
	getline(cin, nameO);

	game1.setPlayerXName(nameX);
	game1.setPlayerOName(nameO);
	cout << "\n";

	game1.game();

}
