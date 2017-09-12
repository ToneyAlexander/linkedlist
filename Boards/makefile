all: board

board: main.o Entity.o Player.o Tile.o
	g++ -g main.o Entity.o Player.o Tile.o -o board

main.o: main.cpp Tile.h Player.h Entity.h
	g++ -c main.cpp

Entity.o: Entity.cpp
	g++ -c Entity.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Tile.o: Tile.cpp
	g++ -c Tile.cpp

clean:
	rm *o board
