#include "MySBBST.hh"
#include "student.h"
/**
 *Contains methods relating to adding Elems to the SBBST 
 *
 * @author    Zoe Millard
 * @version   1.1
 * @since     201503137
 *
 */
template bool MySBBST<int, int, intintCompare, intintCompare>::add(int);
template bool MySBBST<int, int, intintCompare, intintCompare>::add(MySBBSTNode *, int);

template bool MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::add(student);
template bool MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::add(MySBBSTNode *, student);

/*
 * Adds an element to a SBBST
 * 
 * requires  - Elem != null and is either a student or an int
 * ensures   - An element is added to the array
 *
 * @param   Elem   The elements to be added to the tree
 * @return  bool   always true
 * 
 *
 */
template <class Elem, class Key, class EEComp, class KEComp>
bool MySBBST<Elem, Key, EEComp, KEComp>::add(Elem e) 
{
	if(root == NULL){ 
		root = new MySBBSTNode(e); 
	}else{
		if(EEComp::lt(e, root->e)){
			return add(root->lc, e);
		}
		return add(root, e);
	}
	return true;
}
template <class Elem, class Key, class EEComp, class KEComp>
bool MySBBST<Elem, Key, EEComp, KEComp>::add(MySBBSTNode *sr, Elem e) 
{
	
	if(sr == NULL){ 
		sr = new MySBBSTNode(e); 
	}else if (EEComp::lt(e, sr->e)){
		//add(sr->lc, e);//???
	}else if (EEComp::gt(e, sr->e)){
		//add(sr->rc, e);//???
	}
	//balance(sr);
	return true;
}