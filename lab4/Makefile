CLASS=Board
MAIN=sudoku
EXEC=solve
FLAG=-std=c++14

$(EXEC): $(MAIN).o $(CLASS).o
	g++ -o $(EXEC) $(MAIN).o $(CLASS).o $(FLAG)

$(MAIN).o: $(MAIN).cpp
	g++ -c $(MAIN).cpp $(FLAG)

$(CLASS).o: $(CLASS).cpp
	g++ -c $(CLASS).cpp $(FLAG)

clean:
	rm $(EXEC) *.o
