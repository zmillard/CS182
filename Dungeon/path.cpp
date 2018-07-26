#include "Dungeon.hh"
#include "Queue.hh"
#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

/*
 * max distance
 * 
 * requires  -  int* and bool*
 * ensures   - the max index is returned
 */
int Dungeon::maxDistance(int* dist, bool* path){
	int max = INT_MAX;
	int maxIndex;
	for (int i = 0; i < roomCap; i++){
		if (path[i] == false && dist[i] < max){ //this is now a max index
			max = dist[i];
			maxIndex = i;
		}
	}
   return maxIndex;
}
/*
 * Finds the most lucrative path 
 * 
 * requires  -  unsigned int start
 * ensures   - the path that allows the most pizzas is printed
 */
void Dungeon::lucrativePath(unsigned int start){
	int* shorty = new int[roomCap];
	bool* inPath = new bool[roomCap];
	
	for(int i=0; i < roomCap; i++){ 
		shorty[i] = 0;
		inPath[i] = false;
	}
	shorty[start] = rooms[start]->cash - rooms[start]->mStrength;
	for(int count = 0; count < roomCap - 1; count++){
		int max = maxDistance(shorty, inPath);
		inPath[max] = true;
		for(int v = 0; v < roomCap; v++){
			if(!inPath[v] && edges[max][v] && shorty[max] != INT_MAX && shorty[max] + edges[max][v] < shorty[v]){
				shorty[v]= rooms[v]->cash - rooms[v]->mStrength;
				cout << rooms[v]->ro << " would have a loot ratio of " << rooms[v]->cash - rooms[v]->mStrength << endl;
			}
		}
	}
}
/*
 * Finds the most lucrative path at different starting points
 * 
 * requires  -  
 * ensures   - the path that allows the most pizzas is printed for different start values
 */
void Dungeon::lucrativePaths(){
	for(int i = 0; i < roomCap - 1; i++){
		lucrativePath(i);
	}
}
/*
 * Determines the path that the pizza should take 
 * 
 * requires  -  unsigned int start, unsigned int target, unsigned int budget
 * ensures   - the path that allows the most pizzas is printed
 */
unsigned int Dungeon::pizzaParty(unsigned int start, unsigned int target, unsigned int budget){ //ford-fulkerson
	int i, k;
	aRoom = new Room* [roomCap];
	
	for(i = 0; i < roomCap; i++){
		for(k = 0; k < roomCap; k++){
			aRoom[i][k] = rooms[i][k];
		}
	}
	
	int* parent = new int [roomCap];//array filled by bfs
	
	int maxFlow = 0;
	
	while(visited[target]){
		int pFlow = INT_MAX;
		for(i = start; i != target; i = parent [i]){
			k = parent[i];
			pFlow = min(pFlow, aRoom[i][k]); //need this method
		}
		for(i = start; i != target; i = parent[i]){
			k = parent[i];
			aRoom[i][k].mStrength -= pFlow;
			aRoom[k][i].mStrength += pFlow;
		}
		maxFlow += pFlow;
	}
}
/*
 * Finds the most lucrative path 
 * 
 * requires  -  int size, Room r
 * ensures   - the smaller value is returned
 */
int Dungeon::min(int size, Room r){
	if(size < r.mStrength){
		return size;
	}
	return r.mStrength;
}