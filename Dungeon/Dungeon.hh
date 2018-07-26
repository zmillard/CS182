/*
*Zoe Millard
*"I pledge my honor that I have abided by the Stevens Honor System" -ZM
*Implements a number of algorithms to simulate a dungeon
*
*/


#ifndef _Dungeon_H_
#define _Dungeon_H_
#include "Queue.hh"
#include <iostream>
#include <cstring>
using namespace std;

class Dungeon{
	private: 
		class Hero
		{
			public:
				string name;
				unsigned int healthPower;
				unsigned int strength;
				
				
				Hero()
				{
					name = "Zo";
					healthPower = 5;
					strength = 5;
					Hero(name, healthPower, strength);
				}
				Hero(string n, unsigned int s, unsigned int hp)
				{
					name = n;
					strength = s;
					healthPower = hp;
				}
			private:
		};
		class Room
		{
			public:
				string monster;
				int mStrength;
				
				string ro;
				int cash;
				
				Room(){
					Room("Kitten shack","cat", 9, 1);
				}
				Room(string r, string m, unsigned int s, unsigned int c){
					ro = r;
					monster = m;
					mStrength = s;	
					cash = c;
				}
			private:
		};
		void dfs(unsigned int s);
		void bfs(unsigned int s);
	public:
		int roomCap;
		int heroCap;
		int heroCount;
		int roomCount;
		unsigned int heroGold;
		
		Dungeon()
		{
			heroGold = 0;
			heroCount = 0;
			roomCount = 0;
			roomCap = 5; 
			heroCap = 5; 
			edgesExamined = 0;
			edgeCount = roomCap*roomCap;
			edges[roomCap][roomCap];
			
			visited = new bool [roomCap];
			rooms = new Room* [roomCap];
			heroes = new Hero* [heroCap];
            edges = new int* [roomCap];
			
            for (int i = 0; i < roomCap; i++)
                edges[i] = new int[roomCap];
			for (int i = 0; i < roomCap; i++){
				for (int j = 0; j < roomCap + 1; j++){
					edges[i][j] = 0;
				}
			}
			
			for (int i = 0; i < roomCap; i++){
				visited[i] = false;
			}
		}
		Dungeon(unsigned int r, unsigned int h){ //adjacency matrix
			heroCount = 0;
			edgesExamined = 0;
			edgeCount = 0;
			if(r < 5){
				roomCap = 5;
			} else{
				roomCap = r;
			}
			if(h < 5){
				heroCap = 5;
			}else{
				heroCap = h;
			}
			visited[roomCap];
			rooms = new Room* [roomCap];
			heroes = new Hero* [heroCap];
            edges = new int* [roomCap];
            for (int i = 0; i < roomCap; i++)
                edges[i] = new int[roomCap];
			for (int i = 0; i < roomCap; i++){
				for (int j = 0; j < roomCap + 1; j++){
					edges[i][j] = 0;
				}
			}/*
			for (int i = 0; i < roomCap; i++){
				visited[i] = false;
			}*/
		}
		bool* visited;
		Room** rooms;
		Room** aRoom;
		Hero** heroes;
		int** edges;
		int* shorty; //shortest distance from the source
		bool* inPath;
		int edgesExamined;//how many have I looked at
		int edgeCount;//how many are there in total?
		int nextNeighbor(unsigned int p, unsigned int t);
		
		void visit(unsigned int i);
		void unvisitAll();
		//bool visited(int i);
		int addRoom(string n, string m, unsigned int s, unsigned int d);
		bool setHall(unsigned int src, unsigned int dst, unsigned int cap);//
		bool addHero(string n, unsigned int s, unsigned int hp);//
		void depthRooms(); //done
		void breadthRooms(); //done
		void listRooms();
		void showHalls();//
		void showHeroes();//
		void mst();
		void minHeap(int spot);
		
		//Part 3
		void lucrativePath(unsigned int start);
		void lucrativePaths();
		unsigned int pizzaParty(unsigned int start, unsigned int target, unsigned int budget);
		int maxDistance(int* dist, bool* path);
		void printMap();
		int min(int size, Room r);
};

#endif