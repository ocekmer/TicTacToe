#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe
{
public:
	TicTacToe(int sizeIn);
	~TicTacToe();
	void printBoard() const;
	void setPlayerXName(std::string nameXIn);
	void setPlayerOName(std::string nameOIn);
	void setGameSize(int sizeIn);
	std::string getPlayerXName() const;
	std::string getPlayerOName() const;
	int getGameSize() const;
	void newTurnX(int index);
	void newTurnO(int index);
	void game();
	bool checkGame(char c) const;

private:
	int gameSize{0};
	std::vector<char> gameBoard;	
	std::string playerXName;
	std::string playerOName;
};

#endif
