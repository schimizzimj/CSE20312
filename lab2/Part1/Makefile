CLASS1=CardDeck
MAIN=deckMain
EXEC=playcards

$(EXEC): $(MAIN).o $(CLASS1).o
	g++ -o $(EXEC) $(MAIN).o $(CLASS1).o

$(MAIN).o: $(MAIN).cpp
	g++ -c $(MAIN).cpp

$(CLASS1).o: $(CLASS1).cpp
	g++ -c $(CLASS1).cpp

clean:
	rm $(EXEC) *.o
