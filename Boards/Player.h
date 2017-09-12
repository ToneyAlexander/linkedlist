#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

//Player object is a type of entity
class Tile;
class Player: public Entity{
public:
	Player(Tile *pt);
	void move(char n);
};

#endif