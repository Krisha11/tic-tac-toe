#include "BoardTest.hpp"

void BoardTest::testIsWinNotFinished() {
	Board b;
	b.move(0, 0, O);
	b.move(4, 5, X);
	b.move(0, 1, O);
	b.move(5, 5, X);
	b.move(1, 0, O);
	DO_CHECK(b.getState() == CONTINUE);
}

void BoardTest::testIsWinO() {
	Board b;
	b.move(0, 0, O);
	b.move(1, 0, X);
	b.move(0, 1, O);
	b.move(1, 1, X);
	b.move(0, 2, O);
	b.move(1, 2, X);
	b.move(0, 3, O);
	b.move(1, 3, X);
	b.move(0, 4, O);
	DO_CHECK(b.getState() == O_WIN);
}

void BoardTest::testIsWinX() {
	Board b;
	b.move(0, 0, O);
	b.move(1, 0, X);
	b.move(0, 1, O);
	b.move(1, 1, X);
	b.move(0, 2, O);
	b.move(1, 2, X);
	b.move(0, 3, O);
	b.move(1, 3, X);
	b.move(4, 4, O);
	b.move(1, 4, X);
	DO_CHECK(b.getState() == X_WIN);
}

void BoardTest::testIsWinODiagonal() {
	Board b;
	b.move(0, 0, O);
	b.move(9, 0, X);
	b.move(1, 1, O);
	b.move(9, 1, X);
	b.move(2, 2, O);
	b.move(9, 2, X);
	b.move(3, 3, O);
	b.move(9, 3, X);
	b.move(4, 4, O);
	DO_CHECK(b.getState() == O_WIN);
}

void BoardTest::testMoveOnUsed() {
	Board b;
	b.move(0, 0, O);
	DO_CHECK(b.canMove(0, 0) == false);
}

void BoardTest::testMoveCorrect() {
	Board b;
	b.move(0, 0, O);
	DO_CHECK(b.canMove(1, 1) == true);
}

void BoardTest::testMoveOutOfField() {
	Board b;
	b.move(0, 0, O);
	b.move(1, 1, X);
	DO_CHECK(b.canMove(-2, 2) == false);
}

void BoardTest::testGetSignO() {
	Board b;
	b.move(0, 0, O);
	DO_CHECK(b.getSign(0, 0) == O);
}

void BoardTest::testGetSignNothing() {
	Board b;
	DO_CHECK(b.getSign(0, 0) == NOTHING);
}

void BoardTest::testGetSignX() {
	Board b;
	b.move(0, 0, X);
	DO_CHECK(b.getSign(0, 0) == X);
}

void BoardTest::testGetWidth() {
	Board b;
	DO_CHECK(b.getWidth() == 10);
}

void BoardTest::testGetHeight() {
	Board b;
	DO_CHECK(b.getHeight() == 10);
}

void BoardTest::testGetCurFirst() {
	Board b;
	DO_CHECK(b.getCur() == O);	
}

void BoardTest::testGetCurSecond() {
	Board b;
	b.move(0, 0, O);
	DO_CHECK(b.getCur() == X);
}

void BoardTest::runAllTests() {
	testIsWinNotFinished(); 
	testIsWinO();    
	testIsWinX();    
	testIsWinODiagonal();
	testMoveOnUsed();    
	testMoveCorrect();    
	testMoveOutOfField();
	testGetSignO();
	testGetSignNothing();
	testGetSignX();
	testGetWidth();
	testGetHeight();
	testGetCurFirst();
	testGetCurSecond();
}
