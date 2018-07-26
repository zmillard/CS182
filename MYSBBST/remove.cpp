#include "MySBBST.hh"
#include "student.h"
/**
 * Contains methods relating to removing items from the SBBST
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150315
 *
 */
 
template int MySBBST<int, int, intintCompare, intintCompare>::remove(int);
template int MySBBST<int, int, intintCompare, intintCompare>::remove(MySBBSTNode *&, int);
template int MySBBST<int, int, intintCompare, intintCompare>::removeMin(MySBBSTNode *&);

template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::remove(unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::remove(MySBBSTNode *&, unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::removeMin(MySBBSTNode *&);

//template student MySBBST<student, unsigned int, studentStudentComp, uiStudentComp>::removeMin(MySBBST *&);
/*
 * Removes an element from a SBBST
 * 
 * requires  - MSBBSTNode sr is not null, and k != null
 * ensures   - An element is from the array
 *
 * @param   Key   		The value of the element to be removed from the tree
 * @param	MSBBSTNode	location of the element to be removed
 * @return  Elem  		returns the value that was removed
 *
 */
template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::remove(MySBBSTNode *&sr, Key k) //change header sortings
{
	Elem temp;
	MySBBSTNode *deleteme = NULL;
	if (sr == NULL){
		return zero;
	}
	if (KEComp::eq(k, sr->e)){
		temp = sr->e;
		if(KEComp::lt(k, sr->e)){
			return remove(sr->lc, k);
		}
		return remove(sr->rc, k);
	}	
	return zero;
}

template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::removeMin(MySBBSTNode *&sr) 
{
	Elem temp;
	MySBBSTNode *deleteme;
	if(sr == NULL){
		return zero;
	}
	if(sr->lc == NULL){
		temp = sr->e;
		deleteme = sr;
		sr = sr->rc;
		delete deleteme; 
		return temp;
	}
	return removeMin(sr->lc);
}
template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::remove(Key k) 
{
	return remove(root, k);
}