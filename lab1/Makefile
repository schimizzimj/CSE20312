CLASS1=C4Col
CLASS2=C4Board
MAIN=C4Main
EXEC=playC4

$(EXEC): $(MAIN).o $(CLASS1).o $(CLASS2).o
	g++ -o $(EXEC) $(MAIN).o $(CLASS1).o $(CLASS2).o

$(MAIN).o: $(MAIN).cpp
	g++ -c $(MAIN).cpp

$(CLASS1).o: $(CLASS1).cpp
	g++ -c $(CLASS1).cpp

$(CLASS2).o: $(CLASS2).cpp
	g++ -c $(CLASS2).cpp

clean:
	rm $(EXEC) *.o
