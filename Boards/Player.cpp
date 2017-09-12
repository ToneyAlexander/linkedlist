#include <iostream>
#include "Player.h"
#include "Tile.h"
#include "Entity.h"

using namespace std;

//Constructor
Player::Player(Tile *pt) : Entity(pt){
	symbol = 'o';
	t = pt;
}
//Movement method
void Player::move(char n){
	notifyTile(NULL);
	if(n == 'a' && t->left != NULL){
		t = t->left;
		notifyTile(this);
	}else if(n == 'd' && t->right != NULL){
		t = t->right;
		notifyTile(this);
	}else if(n == 'w' && t->above != NULL){
		t = t->above;
		notifyTile(this);
	}else if(n == 's' && t->below != NULL){
		t = t->below;
		notifyTile(this);
	}
}