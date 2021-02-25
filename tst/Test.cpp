#include "Test.hpp"

int Test::failedNum = 0;
int Test::totalNum = 0; 

void Test::check(bool expr,/* const char *func, */const char  *filename, std::size_t lineNum) {
	if (expr) {
		printf("Test passed\n");
	}
	else {
		Test::failedNum++;
		printf("Test failed: %s %d\n"/*, func*/, filename, (int)lineNum);
	}
	Test::totalNum++;
}

void Test::showFinalResult() {
	printf("Failed: %d/%d\n", Test::failedNum, Test::totalNum);
	if (Test::failedNum == 0)
		printf("OK\n");
}

