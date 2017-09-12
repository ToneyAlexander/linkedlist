#ifndef TILE_H
#define TILE_H

class Entity;
class Tile{
public:
	Tile *above;
	Tile *below;
	Tile *left;
	Tile *right;
	Entity *ent;
	char symbol;
	int id;
	Tile();
	char toCha();
	void setEntity(Entity *e);
	void update();
};

#endif