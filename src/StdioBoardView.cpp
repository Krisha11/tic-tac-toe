#include "StdioBoardView.hpp"
#include "stdlib.h"
#include "stdio.h"

StdioBoardView::StdioBoardView(Board& board) : _board(board) {}

StdioBoardView::~StdioBoardView() {
	//delete _board;
}

void StdioBoardView::doGameCycle(bool isSilent) {
	while (_board.getState() == CONTINUE) {
		if (!isSilent)
			printBoard();
		makeMove();
	}
	printBoard();
	switch(_board.getState()) {
		case X_WIN:
			printf("X wins!\n");
			break;
		case O_WIN:
			printf("O wins!\n");
			break;
		case DRAW:
			printf("Draw.\n");
			break;
		default:
			break;	
	}
}

void StdioBoardView::printMakeMove() {
	if (_board.getCur() == X)
		printf("X move: ");
	else
		printf("O move: ");
}

void StdioBoardView::printBoard() {
	printf("\n");
	for (int i = 0; i < _board.getHeight(); i++) {
		for (int j = 0; j < _board.getWidth(); j++)
			if (_board.getSign(i, j) == X)
				printf("X");
			else if (_board.getSign(i, j) == O)
				printf("O");
			else
				printf(".");
		printf("\n");
	}
}

void StdioBoardView::makeMove() {
	bool flag = true;
	int x, y;
	while(flag) {
		printMakeMove();
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1)
			exit(0);		
		flag = !_board.canMove(x, y);
 		if (flag)
			printf("Bad move!\n");
	}
	_board.move(x, y, _board.getCur());
}

