/*
 *Sorts the elements 
 */
#include "Dungeon.hh"
#include <iostream>
#include <cstring>
using namespace std;
void Dungeon::mst(){
	/*
	edges();//sort or max heap all of the edges
	rooms();//set up mst with all vertices
	while(edgesExamined < edgeCount){
		if (edges[i]< curredge){//get next smallest edge
			curredge = edges[i];
		}
		//check if vertices are already connected
		//if not, 
			//add edge to mst
			//if edges used == V-1
			//return
	}*/
}
void Dungeon::minHeap(int spot){
	int small;
	int left;
	int right;
	
	left = 2 * spot + 1;
	right = 2 * spot + 2;
	
	if(left < roomCap && edges[right] < edges[small]){
		small = left;
	}
	if(small != spot){
		
	}
}