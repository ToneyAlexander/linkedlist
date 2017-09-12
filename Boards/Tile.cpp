#include "Tile.h"
#include "Entity.h"

Tile::Tile():above(0), below(0), right(0), left(0), ent(0)
, symbol('_'){
}
char Tile::toCha(){
	if(ent){
		return ent->symbol;
	}else{
		return symbol;
	}
}
void Tile::setEntity(Entity *e){
	ent = e;
}