/**
 *Contains methods relating to searching within the dungeon
 *
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150417
 *
 */

#include "Dungeon.hh"
#include "Queue.hh"
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
/*
 * all rooms are marked as unvisited
 *
 */
void Dungeon::unvisitAll(){
	//visited[roomCap];
	for (int i = 0; i < roomCap; i++){
		visited[i] = false;
	}
}
/*
 * a room is visited
 * 
 * requires  - int i holds the location of an integer on the array
 * ensures   - the location is marked as visited
 */
void Dungeon::visit(unsigned int i){
	visited[i] = true;
}
/*
 * depth first search
 * 
 * requires  - multiple rooms
 * ensures   - the rooms are sorted according to dfs
 *
 */
void Dungeon::depthRooms(){
	unsigned int r;
	unvisitAll();
	for(r = 0; r < roomCap; r++){
		if(!visited[r]){
			cout << endl;
			dfs(r);
		}
	}
}
int Dungeon::nextNeighbor(unsigned int current, unsigned int v){
	int i;
	
	if (current < roomCap && v == roomCap){
		for (int i = 0; i < roomCap; i++){
			if (edges[current][i] != 0){
				return i;
			}
		}
	}
	for (int i = v + 1; i < roomCap; i++){
		if(edges[current][i] != 0 ){
			return i;
		}
	}
	return roomCap;
}

void Dungeon::dfs(unsigned int s){
	unsigned int r;
	if(s < roomCap && !visited[s]){
		//cout << endl << rooms[s]->monster<< " Monster with strength " << rooms[s]-> mStrength << " in " << rooms[s]->ro;
		visited[s] = true;
		for(r = nextNeighbor(s, roomCap); r < roomCap; r = nextNeighbor(s,r)){ 
			if(!visited[r]){
				dfs(r);
			}
		}
	}
}
/*
 * breadth first search
 * 
 * requires  -  
 * ensures   - rooms are organized by bfs
 */
void Dungeon::breadthRooms(){
	int v;
	unvisitAll();
	for(v = 0; v < roomCap; v++){
		if(!visited[v]){
			bfs(v);
			cout << endl;
		}
	}
}
void Dungeon::bfs(unsigned int s){
	Queue* z = new Queue(); // = new Queue()
	if(!visited[s]){
		z->enqueue(s);
		visit(s);
		while(!z->empty()){
			int v = z->dequeue();
			//cout << v;
			for(int n = nextNeighbor(v, roomCap); n < roomCap; n = nextNeighbor(v, n)){
				if (!visited[n]){
					z->enqueue(n);
					visit(n);
				}
			}
		}
	}
}