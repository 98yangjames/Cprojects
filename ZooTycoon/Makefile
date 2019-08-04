CC = g++ -g
exe_file = zootycoon
head_files = animal.h zoo.h monkey.h seaotter.h sloth.h
$(exe_file): animal.o zoo.o monkey.o seaotter.o sloth.o main.o
	$(CC) animal.o zoo.o monkey.o seaotter.o sloth.o main.o -o $(exe_file)

animal.o: animal.cpp $(head_files)
	$(CC) -c animal.cpp
zoo.o: zoo.cpp $(head_files)
	$(CC) -c zoo.cpp
monkey.o: monkey.cpp $(head_files)
	$(CC) -c monkey.cpp
seaotter.o: seaotter.cpp $(head_files)
	$(CC) -c seaotter.cpp
sloth.o: sloth.cpp $(head_files)
	$(CC) -c sloth.cpp
main.o: main.cpp $(head_files)
	$(CC) -c main.cpp


clean:
	rm -f *.out *.o $(exe_file)
