#include "NcursesBoardView.hpp"
#include "stdlib.h"
#include "stdio.h"
#include <ncurses.h>

NcursesBoardView::NcursesBoardView(Board& board) : _board(board), _row(0), _col(0) {}

void NcursesBoardView::doGameCycle() {
	initscr();
	noecho();
	keypad(stdscr, TRUE);

	printBoard();
	move(_row, _col);
	while (_board.getState() == CONTINUE) {
		if (makeMove() != 0) {	
			endwin();
			return;
		}	
	}	

	move(_board.getHeight(), 0);
	switch(_board.getState()) {
		case X_WIN:
			printw("X wins!\n");
			break;
		case O_WIN:
			printw("O wins!\n");
			break;
		case DRAW:
			printw("Draw.\n");
			break;
		default:
			break;	
	}

	getch();
	endwin();
}

void NcursesBoardView::printBoard() {
	for (int i = 0; i < _board.getHeight(); i++) {
		for (int j = 0; j < _board.getWidth(); j++)
			if (_board.getSign(i, j) == X)
				printw("X");
			else if (_board.getSign(i, j) == O)
				printw("O");
			else
				printw(".");
		printw("\n");
	}
}

char NcursesBoardView::getCurC() {
	if (_board.getCur() == X)
		return 'x';
	else	
		return 'o';
}


int NcursesBoardView::makeMove() {
	bool flag = true;
	while(flag) {
		int ch = getch();
	        switch (ch) {
                	case KEY_UP: 
				if (_board.onBoard(_row - 1, _col))
					_row--;
				move(_row, _col);
				break;
                	case KEY_DOWN: 
				if (_board.onBoard(_row + 1, _col))
					_row++;
				move(_row, _col);
				break;
			case KEY_LEFT:
				if (_board.onBoard(_row, _col - 1))
					_col--;
				move(_row, _col);
				break;
			case KEY_RIGHT:
				if (_board.onBoard(_row, _col + 1))
					_col++;
				move(_row, _col);
				break;
			case 'x':
				return -1;
				break;
			case ' ':
				flag = !_board.canMove(_row, _col);
				break;
                }
	}
	addch(getCurC());
	move(_row, _col);
	_board.move(_row, _col, _board.getCur());
	return 0;
}
