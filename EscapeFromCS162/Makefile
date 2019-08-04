CC = g++ -g -std=c++11
exe_file = maze
head_files = MazeLocation.h Wall.h OpenSpace.h Maze.h MazePerson.h IntrepidStudent.h Ta.h instructor.h
$(exe_file): main.o Wall.o OpenSpace.o Maze.o MazePerson.o IntrepidStudent.o Ta.o instructor.o
	$(CC)  main.o Wall.o OpenSpace.o Maze.o MazePerson.o IntrepidStudent.o Ta.o instructor.o -o $(exe_file)

Wall.o: Wall.cpp $(head_files)
	$(CC) -c Wall.cpp
main.o: main.cpp $(head_files)
	$(CC) -c main.cpp
OpenSpace.o: OpenSpace.cpp $(head_files)
	$(CC) -c OpenSpace.cpp
Maze.o: Maze.cpp $(head_files)
	$(CC) -c Maze.cpp
MazePerson.o: MazePerson.cpp $(head_files)
	$(CC) -c MazePerson.cpp
IntrepidStudent.o: IntrepidStudent.cpp $(head_files)
	$(CC) -c IntrepidStudent.cpp
Ta.o: Ta.cpp $(head_files)
	$(CC) -c Ta.cpp
instructor.o: instructor.cpp $(head_files)
	$(CC) -c instructor.cpp

# MazeLevel.o: MazeLevel.cpp $(head_files)
# 	$(CC) -c MazeLevel.cpp

clean:
	rm -f *.out *.o $(exe_file)
