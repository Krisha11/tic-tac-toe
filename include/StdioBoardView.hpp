#ifndef STDIO_BOARD_VIEW_HPP
#define STDIO_BOARD_VIEW_HPP

#include "Board.hpp"

class StdioBoardView {
public:
	StdioBoardView(Board& board);
	~StdioBoardView();
	void doGameCycle(bool isSilent);

private:
	Board& _board;

	void printBoard();
	void makeMove();
	void printMakeMove(); 
};

#endif
