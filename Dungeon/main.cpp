#include "Dungeon.hh"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	Dungeon *d= new Dungeon();
	d->addHero("MelanieCat", 2, 5);
	//d->showHeroes();
	d->addRoom("1","1",5,1);
	d->addRoom("2","2",6,2);
	d->addRoom("3","3",9,3);
	d->addRoom("4","4",7,4);
	d->setHall(0, 1, 1);
	d->setHall(1, 2, 1);
	//d->setHall(2, 3, 3);
	d->setHall(2, 3, 1);
	d->setHall(0, 3, 30);
	//d->setHall(0, 3, 3);
	//d->setHall(1, 3, 3); //wtf??
	//d->setHall(3, 0, 1); 
	//d->showHalls();
	//d->unvisitAll();
	//cout << d->visited[0];
	//d->visited(1);
	//d->depthRooms();
	//d->breadthRooms();
	//d->showHalls();
	d->lucrativePath(0);
	d->lucrativePaths();
	//d->pizzaParty(0,1,2);
	//d->printMap();
	delete d;
	return 0;
}