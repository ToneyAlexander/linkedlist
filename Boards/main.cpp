#include <iostream>
#include <queue>
#include "Tile.h"
#include "Player.h"
#include "Entity.h"

using namespace std;

//GRAPHS
//Array linearization
//Tensors

//Fix this for all sorts of shapes...
//Maybe it needs recursion?

//ADD END TILE PARAMETER
void displayBoard(Tile *a, Tile *z){
	//Display the board
	Tile *object = a;
	Tile *start = a;
	//Flag to avoid repeats
	int flag = 0;
	while(object != NULL){
		while(object != NULL){
			if(flag && (object == start)){
				flag = 0;
				break;
			}
			cout << (*object).toCha();
			if(object == z){
				return;
			}
			object = (*object).right;
			flag = 1;
		}
		flag = 0;
		object = (*start).below;
		start = object;
		cout << "\n";
	}
}

//RECURSIVE - BAD
void displayBoardDFS(Tile *t, bool *mark, int vertex){
	//Display the board
	cout<<vertex;
	cout << t[vertex].toCha();
	mark[vertex] = true;

	int idB = t[vertex].below->id;
	int idR = t[vertex].right->id;

	if(!mark[idR]){
		displayBoardDFS(t, mark, idR);
	}
	cout << "\n";
	if(!mark[idB]){
		displayBoardDFS(t, mark, idB);
	}
}

void displayBoardBFS(Tile *t, bool *mark, int vertex){
	queue <Tile> tiles;
	tiles.push(t[vertex]);

	while(!tiles.empty()){
		Tile current = tiles.pop();
		cout << t[vertex].toCha();
		mark[vertex] = true;

		int idR = t[vertex].right->id;
		queue.push(t[idR]);
	}
}

void displayBoard


//Create an n x m board, with full linkages
void generateBoard(int n, int m, Tile t[]){
	//mc and nc are the counters
	for(int nc = 0; nc < n; nc++){
		for(int mc = 0; mc < m; mc++){
			//ROW LINKAGES
			if(nc != 0){
				//For rows such that nc != 0 (not top)
				//Can link nc*m + mc to (nc-1)*m + mc
				t[nc*m + mc].above = &t[(nc-1)*m + mc];
			}else{
				//Link bottom row and top row
				t[(n-1)*m + mc].below = &t[mc];
				t[mc].above = &t[(n-1)*m + mc];
			}
			if(nc != n-1){
				//For rows such that nc != n-1 (not bottom)
				//Can link nc*m + mc to (nc+1)*m + mc
				t[nc*m + mc].below = &t[(nc+1)*m + mc];
			}

			//COLUMN LINKAGES
			if(mc != 0){
				//For columns such that mc != 0 (not left)
				//Can link nc*m + mc to nc*m + mc - 1
				t[nc*m + mc].left = &t[nc*m + mc - 1];
			}else{
				//Error when useing dynamic memory?
				//Link left column and right column
				t[nc*m-1].right = &t[(nc-1)*m];
				t[(nc-1)*m].left = &t[nc*m-1];
			}
			if(mc != m-1){
				//For columns such that mc != m-1 (not right)
				//Can link nc*m + mc to nc*m + mc + 1
				t[nc*m + mc].right = &t[nc*m + mc + 1];
			}
		}
	}
}

int main(){
	//M is height
	int m = 8;
	//N is width
	int n = 8;

	Tile t[200];
	bool mark[200];

	for(int i = 0; i < 200; i++){
		mark[i] = false;
		t[i].id = i;
	}

	generateBoard(m, n, t);
	Player p(&t[2]);
	p.notifyTile(&p);
	Entity e(&t[5]);
	e.notifyTile(&e);

	char c = 1;

	displayBoardDFS(t, mark, 0);
	for(int i = 0; i < 200; i++){
		mark[i] = false;
	}
	cout << flush;

	//displayBoard(&t[0], &t[m*n-1]);
	cout << "\n:";
	cin >> c;
	while(c != 'q'){
		p.move(c);
		e.move();
		cout << "\n\n\n";
		//displayBoard(&t[0], &t[m*n-1]);
		displayBoardDFS(t, mark, 0);

		for(int i = 0; i < 200; i++){
			mark[i] = false;
		}
		cout << "\n:";
		cin >> c;
	}
	return 0;
}