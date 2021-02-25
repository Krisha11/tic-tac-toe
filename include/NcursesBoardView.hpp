#ifndef NCURSES_BOARD_VIEW_HPP
#define NCURSES_BOARD_VIEW_HPP

#include "Board.hpp"
#include <ncurses.h>

class NcursesBoardView {
public:
	NcursesBoardView(Board& board);
	void doGameCycle();

private:
	Board& _board;
	int _row, _col;
	void printBoard();
	int makeMove();
	char getCurC();
};

#endif
