#include "Dungeon.hh"
#include "Queue.hh"
#include <iostream>
#include <cstring>
#include <queue>

void Dungeon::printMap(){
	cout << endl << "Dungeon Map:" << endl << endl;
	for(int i = 0; i < roomCap; i++){
		for(int j = 0; j < roomCap; j++){
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}
}
