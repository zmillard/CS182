/**
 *Contains methods relating to adding Heroes to the dungeon
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
 * Adds hero to the dungeon
 * requires  -   Hero parameters be filled out
 * ensures   - An hero is added to the dungeon if there is space
 *
 * @param   String n   Hero name
 * @param	int s 	   Strength 
 * @param 	int hp		Health
 * @return  bool   		True if hero can be added
 */
bool Dungeon::addHero(string n, unsigned int s, unsigned int hp){
	if (heroCount + 1 < heroCap){
		heroes[heroCount] = new Hero(n, s, hp); 
		heroCount += 1;
		return true;
	}
	return false;
}
/*
 * Displays heroes
 * 
 * requires  - at least one hero is present
 * ensures   - information is displayed
 *
 */
void Dungeon::showHeroes(){
	for (int i = 0; i < heroCount; i++){
		cout << "Hero: " + heroes[i]->name << ", Strength: " << heroes[i]->strength << ", Health: " << heroes[i]->healthPower << endl;
	}
	cout << "HeroBucks: " << heroGold << endl;
}