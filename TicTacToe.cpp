#include "TicTacToe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(int sizeIn) : gameSize{sizeIn}
{
	int n = getGameSize();
	n *= n;
  	for (int i = 0; i < n; i++)
    {
        gameBoard.push_back('-');
    }
}

TicTacToe::~TicTacToe() {}

void TicTacToe::printBoard() const
{
	int n = getGameSize();
    for (int i = 0; i < n*n; i++)
    {
        cout << gameBoard[i] << " ";
        if ((i + 1) % n == 0)
        {
            cout << endl;
        }
    }
}

void TicTacToe::setPlayerXName(string nameXIn)
{
	playerXName = nameXIn;
}

void TicTacToe::setPlayerOName(string nameOIn)
{
	playerOName = nameOIn;
}

void TicTacToe::setGameSize(int sizeIn)
{
	gameSize = sizeIn;
}

string TicTacToe::getPlayerXName() const
{
	return playerXName;
}

string TicTacToe::getPlayerOName() const
{
	return playerOName;
}

int TicTacToe::getGameSize() const
{
	return gameSize;
}

void TicTacToe::newTurnX(int index)
{
	gameBoard[index] = 'x';
}

void TicTacToe::newTurnO(int index)
{
	gameBoard[index] = 'o';
}

bool TicTacToe::checkGame(char c) const
{
	int counter{0};
    int index;
	int n = getGameSize();

	// Rows
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
            index = i * n + j;
			if (gameBoard[index] == c)
			{
				counter++;
			}
		}
		if (counter == n)
		{
			return 1;
		}
		else
		{
			counter = 0;
		}
	}

	// Columns
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
            index = i * n + j;
			if (gameBoard[index] == c)
			{
				counter++;
			}
		}
		if (counter == n)
		{
			return 1;
		}
		else
		{
			counter = 0;
		}
	}

	// Diagonal
	for (int j = 0; j < n; j++)
	{
        index = j * n + j;
		if (gameBoard[index] == c)
		{
			counter++;
		}
	}
	if (counter == n)
	{
		return 1;
	}
    else
    {
        counter = 0;
    }
    
	// Reverse Diagonal
	for (int i = 0; i < n; i++)
	{
        index = i * n + (n - 1 - i);
		if (gameBoard[index] == c)
		{
			counter++;
		}
	}
	if (counter == n)
	{
		return 1;
	}
    else
    {
        counter = 0;
    }
    
	return 0;
}

void TicTacToe::game()
{
    cout << "Welcome to TicTacToe game " << getPlayerXName() << " and " << getPlayerOName() << endl;
    printBoard();

	int n = getGameSize();
    int counter{-1};
	int row{1};
	int column{1};
    int index{0};
	bool checkEnd{0};

	while (checkEnd == 0 && counter < n*n)
	{
		counter++;

		if (counter % 2 == 0)
		{
			cout << "\n" << getPlayerXName() << ", please give the coordinates (row & column) with a space between them: ";
			cin >> row >> column;
            row--;
            column--;
            index = row * n + column;
			while (gameBoard[index] != '-' || row > n-1 || column > n-1)
			{
				cout << "\nThe coordinates you entered is not available! Please try again:\n";
				cin >> row >> column;
                row--;
                column--;
                index = row * n + column;
			}
			newTurnX(index);
			checkEnd = checkGame('x');
			if (checkEnd == 1)
			{
				cout << "\n" << getPlayerXName() << " wins!!!\n";
			}
		}
		else
		{
			cout << "\n" << getPlayerOName() << ", please give the coordinates (row & column) with a space between them: ";
			cin >> row >> column;
            row--;
            column--;
            index = row * n + column;
			while (gameBoard[index] != '-' || row > n-1 || column > n-1)
			{
				cout << "\nThe coordinates you entered is not available! Please try again:\n";
				cin >> row >> column;
                row--;
                column--;
                index = row * n + column;
			}
			newTurnO(index);
			checkEnd = checkGame('o');
			if (checkEnd == 1)
			{
				cout << "\n" << getPlayerOName() << " wins!!!\n";
			}
		}
		printBoard();
        if (counter == n*n-1 && checkEnd == false)
        {
            cout << "Tie!" << endl;
            checkEnd = true;
        }
        
	}
}
