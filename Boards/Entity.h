#ifndef ENTITY_H
#define ENTITY_H

//Entity class definition
class Tile;
class Entity{
public:
	//What the entity looks like
	char symbol;
	//What tile it is on
	Tile *t;
	//Constructor
	Entity(Tile *pt);
	//Methods for board interaction
	void notifyTile(Entity *e);
	void move();
};

#endif