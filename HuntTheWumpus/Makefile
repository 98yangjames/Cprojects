CC = g++ -g -std=c++11
exe_file = wumpus
head_files = game.h bats.h event.h gold.h wumpus.h pits.h room.h nothing.h
$(exe_file): game.o bats.o main.o gold.o wumpus.o pits.o room.o nothing.o
	$(CC) game.o bats.o main.o gold.o wumpus.o pits.o room.o nothing.o -o $(exe_file)

game.o: game.cpp $(head_files)
	$(CC) -c game.cpp
bats.o: bats.cpp $(head_files)
	$(CC) -c bats.cpp
main.o: main.cpp $(head_files)
	$(CC) -c main.cpp
gold.o: gold.cpp $(head_files)
	$(CC) -c gold.cpp
wumpus.o: wumpus.cpp $(head_files)
	$(CC) -c wumpus.cpp
pits.o: pits.cpp $(head_files)
	$(CC) -c pits.cpp
room.o: room.cpp $(head_files)
	$(CC) -c room.cpp
nothing.o: nothing.cpp $(head_files)
	$(CC) -c nothing.cpp


clean:
	rm -f *.out *.o $(exe_file)
