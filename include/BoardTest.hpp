#ifndef BOARD_TEST_HPP
#define BOARD_TEST_HPP

#include "Board.hpp"
#include "Test.hpp"

#define DO_CHECK(EXPR) check(EXPR, __FILE__, __LINE__);
	
class BoardTest : public Test {
private:
    void testIsWinNotFinished(); 
    void testIsWinO();    
    void testIsWinX();    
    void testIsWinODiagonal();
    void testMoveOnUsed();    
    void testMoveCorrect();    
    void testMoveOutOfField();
    void testGetSignO();
    void testGetSignNothing();
    void testGetSignX();
    void testGetWidth();
    void testGetHeight();
    void testGetCurFirst();
    void testGetCurSecond();
    // ...
    
public:
    void runAllTests();
    // ...
};

#endif


