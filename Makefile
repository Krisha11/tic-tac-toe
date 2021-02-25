flags = -Werror -Wall -Wextra -Wpedantic
all: hw_02

hw_02: obj/ obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o obj/main.o
	g++ obj/Board.o obj/StdioBoardView.o obj/NcursesBoardView.o obj/main.o -o hw_02 -lncurses
obj/Board.o:
	g++ -c $(flags) src/Board.cpp -o obj/Board.o -I include/
obj/StdioBoardView.o:
	g++ -c $(flags) src/StdioBoardView.cpp -o obj/StdioBoardView.o -I include/
obj/NcursesBoardView.o:
	g++ -c $(flags) src/NcursesBoardView.cpp -o obj/NcursesBoardView.o -I include/ -lncurses
obj/main.o:
	g++ -c $(flags) src/main.cpp -o obj/main.o -I include/
obj/:
	mkdir obj

test: obj/ obj/Board.o obj/Test.o obj/BoardTest.o obj/test.o
	g++ obj/Board.o obj/Test.o obj/BoardTest.o obj/test.o -o test
obj/BoardTest.o:
	g++ -c $(flags) tst/BoardTest.cpp -o obj/BoardTest.o -I include/
obj/Test.o:
	g++ -c $(flags) tst/Test.cpp -o obj/Test.o -I include/
obj/test.o:
	g++ -c $(flags) tst/test.cpp -o obj/test.o -I include/

clean:
	rm obj/*.o hw_02 test -rf obj/
