CC = g++ -g
exe_file = gofish
$(exe_file): game.o card.o deck.o player.o hand.o main.o
	$(CC) game.o card.o deck.o player.o hand.o main.o -o $(exe_file)
game.o: game.cpp
	$(CC) -c game.cpp
card.o: card.cpp
	$(CC) -c card.cpp
player.o: player.cpp
	$(CC) -c player.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
main.o: main.cpp
	$(CC) -c main.cpp


clean:
	rm -f *.out *.o $(exe_file)
