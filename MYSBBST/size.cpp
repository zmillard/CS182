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
 
template int MySBBST<int, int, intintCompare, intintCompare>::height(MySBBSTNode *sr);
template int MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::height(MySBBSTNode *sr);

template int MySBBST<int, int, intintCompare, intintCompare>::max(int left, int right);
template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::max(student left, student right);

//template int MySBBST<int, int, intintCompare, intintCompare>::countNodes(MySBBSTNode *sr);

//template student MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::countNodes(MySBBSTNode *sr);

template <class Elem, class Key, class EEComp, class KEComp>
int MySBBST<Elem, Key, EEComp, KEComp>::height(MySBBSTNode *sr){
	if(sr == NULL){
		return -1;
	}
	sr->height;
}
template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::max(Elem left, Elem right){
	if (EEComp::gt(left,right)){
		return left;
	}
	return right;
}
/*
template <class Elem, class Key, class EEComp, class KEComp>
Elem MySBBST<Elem, Key, EEComp, KEComp>::countNodes(SBBSTNode *sr)
{
	if (sr == NULL){
		return 0;
	}else{
        int l = 1;
        l += countNodes(sr->lc);
        l += countNodes(sr->rc);
        return l;
    }
}
*/
/*
template <class Elem, class Key, class EEComp, class KEComp>
int MySBBST<Elem, Key, EEComp, KEComp>::countNodes()
{
     return countNodes(root);
}
*/