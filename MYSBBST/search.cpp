#include "MySBBST.hh"
#include "student.h"
/**
 * Contains methods relating to searching for items within the SBBST
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150313
 *
 */
 
template int MySBBST<int, int, intintCompare, intintCompare>::search(MySBBSTNode *, int);
template int MySBBST<int, int, intintCompare, intintCompare>::search(int);

template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::search(unsigned int);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::search(MySBBSTNode *, unsigned int);

/*
 * Searches for an element to a SBBST
 * 
 * requires  - MSBBSTNode sr is not null, and k != null
 * ensures   - An element is found in the array
 *
 * @param   Key   		The value of the element to be removed from the tree
 * @param	MSBBSTNode	location of the element to be removed
 * @return  Elem  		returns the Elem being searched for
 * 
 */
template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::search(Key k) 
{
	return search(root, k);
}

template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::search(MySBBSTNode *sr, Key k) 
{
	if(sr == NULL){ 
		return zero; 
	}
	if (KEComp::eq(k, sr->e)){
		return sr->e; 
	}
	if (KEComp::lt(k, sr->e)){
		return search(sr->lc, k); 
	}
	return search(sr->rc, k); 
}