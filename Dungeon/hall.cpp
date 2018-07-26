/**
 *Contains methods relating to adding halls to the dungeon
 *
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150417
 *
 */
#include "Dungeon.hh"
#include <iostream>
#include <cstring>
using namespace std;

void Dungeon::showHalls(){
	for (int i = 0; i < roomCount; i++){
		for(int j = 0; j < roomCount; j++){
			if(i != j){
				cout << i << "--" << j << "-->" << edges[i][j] << endl;
			}
		}
	}
}
/*
 * Adds hall to the dungeon
 * requires  -   hall parameters be filled out
 * ensures   - An hall is added to the dungeon
 *
 * @param   int src    source of vec
 * @param	int dst 	destination of vec 
 * @param 	int cap		capacity of hall
 * @return  bool   		True if it can be added
 */
bool Dungeon::setHall(unsigned int src, unsigned int dst, unsigned int cap){
	edges[src][dst] = cap;
	edgeCount++;
	return true;
}