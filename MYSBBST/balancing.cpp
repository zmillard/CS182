#include "MySBBST.hh"
#include "student.h"
/**
 * 
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150227
 *
 */
 
template void MySBBST<int, int, intintCompare, intintCompare>::LLRotation(MySBBSTNode *n);
template void MySBBST<int, int, intintCompare, intintCompare>::RRRotation(MySBBSTNode *n);

template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::LLRotation(MySBBSTNode *);
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::RRRotation(MySBBSTNode *);

/*
 * Uses the selection algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= n < the length of arr
 * ensures   - contents of the array are sorted
 *
 * @param   arr   The array of elements to be sorted
 * @param   n   The size of the data to be sorted
 * 
 *
 */
template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::LLRotation(MySBBSTNode *n) //change header sortings
{
	MySBBSTNode *d;
    d = n->lc;
    n->lc = d->rc;
	d->rc = n;
	n = d;
}

template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::RRRotation(MySBBSTNode *d) //change header sortings
{
	MySBBSTNode *n;
	n = d->lc;
    d->lc = n->rc;
	n->rc = d;
	d = n;
}


