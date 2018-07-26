/**
 *Implements the Queue algorithm
 *
 *@author Zoe Millard
 *@version 1.1
 *@since 20141014
 */
//#include "Dungeon.hh"
#ifndef _Queue_H_
#define _Queue_H_
#include <iostream>
#include <cstring>
using namespace std;

class Queue{
	private:
		int loc;
		int capacity;
		int* q;
	public:
		Queue()
		{
			loc = 0;
			capacity = 100;
			q = new int[capacity];
	
		}
		Queue(int size)
		{
			if (size <= 0){
				cout << "Error: not a valid size";
				return;
			}
			loc = 0;
			capacity = size;
			q = new int[size];
		}
		/*
		int size()
		{
			return loc;
		}
		*/
		bool empty(){
			if (loc > 0){
				return false;
			}else{
				return true;
			}
		}
		void enqueue(int item)
		{
			if (loc >= capacity){
			cout << "Error";
			return;
			}    
			q[loc]=item;
			loc++;
		}
		int dequeue()
		{
			int item;
			if (empty() == false){
				item = q[0];
				for (int i = 0; i < loc; i++){
					q[i] = q[i+1];
				}
				loc--;
				return item;
			}
			cout << "Error: your Queue is empty, nothing to dequeue";
			return -1; 
		}
		int peek(){
			return q[0];
		}
		void printMyQueue(){
			for (int i = 0; i < loc; i++){
				cout << q[i];
			}
		}
		//void bfs(unsigned int s);
};
#endif