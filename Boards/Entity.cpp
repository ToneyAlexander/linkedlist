#include <iostream>
#include "Entity.h"
#include "Tile.h"

using namespace std;

Entity::Entity(Tile *pt){
	symbol = 'e';
	t = pt;
}
//Tell the tile that I am on it
void Entity::notifyTile(Entity *e){
	t->setEntity(e);
}
void Entity::move(){
	notifyTile(NULL);
	t = t->left;
	notifyTile(this);
}