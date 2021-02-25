#include "StdioBoardView.hpp"
#include "NcursesBoardView.hpp"
#include "Board.hpp"
#include "string.h"

int main(int argc, char** argv) {
	Board my;
	if (argc == 1) {
		StdioBoardView stdioBoardView = StdioBoardView(my);
		stdioBoardView.doGameCycle(false);
	}
	else if (argc == 2 && strcmp(argv[1], "silent") == 0) {
		StdioBoardView stdioBoardView = StdioBoardView(my);
		stdioBoardView.doGameCycle(true);
	}
	else if (argc == 2 && strcmp(argv[1], "curses") == 0) {
		NcursesBoardView ncursesBoardView = NcursesBoardView(my);
		ncursesBoardView.doGameCycle();
	}

	return 0;  
}
