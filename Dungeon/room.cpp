/**
 *Contains methods relating to adding rooms to the dungeon
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
/*
 * Adds an room to the dungeon
 * 
 * requires  - paramters are filled out
 * ensures   - An room is added to the array
 *
 * @param   string n   name of the room
 * @param   string m   name of monster
 * @return  int num    number of rooms used
 * 
 *
 */
int Dungeon::addRoom(string n, string m, unsigned int s, unsigned int d){
	if (roomCount + 1 < roomCap){
		rooms[roomCount++] = new Room(n, m, s, d); //something is wrong with how I update this line - causes seg fault
		return roomCount;
	}
	return 0;
}