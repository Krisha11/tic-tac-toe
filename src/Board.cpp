#include "Board.hpp"
#include "stddef.h"

Board::Board() : _cur(O), _height(SIZE), _width(SIZE), _len_win(WIN) {
	_field = new figure*[_height];
	for (int i = 0; i < _height; i++) 
		_field[i] = new figure[_width]();
}

Board::~Board() {
	for (int i = 0; i < _height; i++) {
		delete[] _field[i];
		_field[i] = NULL;
	}
	delete[] _field;
	_field = NULL;
}

bool Board::onBoard(const int x, const int y) const {
	return x < _height && y < _width && x >= 0 && y >= 0;
}

bool Board::canMove(const int x, const int y) {
	return onBoard(x, y) && getSign(x, y) == NOTHING;
}

void Board::move(const int x, const int y, figure sign) {
	_field[x][y] = sign;
	_cur = (_cur == X ? O : X);
}

state Board::checkXO(const int x, const int y) const{
	int dx[4] = {1, 0, 1, 1};
	int dy[4] = {0, 1, 1, -1};
	int cntx = 0, cnto = 0;	

	for (int k = 0; k < 4; k++) {
		cntx = 0, cnto = 0;
	
		for (int l = 0; l < _len_win; l++) {
			int cx = x + dx[k] * l, cy = y + dy[k] * l;
			if (!onBoard(cx, cy))
				continue;
			else if (getSign(cx, cy) == X)
				cntx++;
			else if (getSign(cx, cy) == O)
				cnto++;
		}
		if (cntx == _len_win)
			return X_WIN;
		if (cnto == _len_win)
			return O_WIN;
	}
	return CONTINUE;
}

state Board::checkDraw() const {
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++) 
			if (getSign(i, j) == NOTHING)
				return CONTINUE;
	return DRAW;
}

state Board::getState() const {
	state ans;
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++) {
			ans = checkXO(i, j);
			if (ans != CONTINUE)
				return ans;				
		}	
	if (checkDraw() == DRAW)
		return DRAW;
	
	return CONTINUE;
}
figure Board::getCur() const {
	return _cur;
}
int Board::getHeight() const {
	return _height;
}
int Board::getWidth() const {
	return _width;
}

figure Board::getSign(const int x, const int y) const{
	return _field[x][y];
}

