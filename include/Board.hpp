#ifndef BOARD_HPP
#define BOARD_HPP

enum figure {NOTHING, X, O};
enum state {X_WIN, O_WIN, DRAW, CONTINUE};
const int SIZE = 10, WIN = 5;

class Board {
public:              
	Board();
	~Board(); 
	bool canMove(const int x, const int y);
	void move(const int x, const int y,  figure sign);
	state getState() const;
	figure getSign(const int x, const int y) const;
	bool onBoard(const int x, const int y) const;
	int getWidth() const;
	int getHeight() const;
	figure getCur() const;

private:
	figure** _field;
	figure _cur;
	const int _height, _width, _len_win;	
	
	state checkXO(const int x, const int y) const;
	state checkDraw() const;
};

#endif
