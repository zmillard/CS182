/*
*Zoe Millard
*"I pledge my honor that I have abided by the Stevens Honor System" -ZM
*
*/

#ifndef _SORTING_H_
#define _MySBBST_H_

#include <iostream>
#include <cstring>
using namespace std;

template <class Elem, class Key, class EEComp, class KEComp>
class MySBBST
{
	private:
		class MySBBSTNode
		{
			public:
				MySBBSTNode *lc;
				MySBBSTNode *rc;
				Elem e;
				int height;
				MySBBSTNode(Elem a)
				{
					lc = NULL; 
					rc = NULL; 
					e = a; 
					height = 0;
				}
		};
		Elem zero;
		MySBBSTNode *root;
		bool add(MySBBSTNode *sr, Elem e);
		Elem search(MySBBSTNode *sr, Key k);
		Elem remove(MySBBSTNode *&sr, Key k);
		void inorder();
		void inorder(MySBBSTNode *sr);
		int height(MySBBSTNode *sr);
		Elem max(Elem left, Elem right);
		void LLRotation(MySBBSTNode *n);
		void RRRotation(MySBBSTNode *d);
		Elem removeMin(MySBBSTNode *&sr);
		//Elem countNodes(MySBBSTNode *sr);
		//Elem countNodes();
	public:
		//MySBBSTNode(){root = NULL};
		bool add(Elem e);
		Elem search(Key k);
		Elem remove(Key k);
		void printout();
		MySBBST(Elem e){root = NULL;}
};
class intintCompare
{
 public:
  static bool lt(int, int);
  static bool gt(int, int);
  static bool eq(int, int);
};
#endif