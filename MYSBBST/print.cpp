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
 
template void MySBBST<int, int, intintCompare, intintCompare>::printout();
template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::printout();

//template void MySBBST<int, int, intintCompare, intintCompare>::inorder();
//template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::inorder();

//template void MySBBST<int, int, intintCompare, intintCompare>::inorder(SBBSTNode *sr);
//template void MySBBST<student, unsigned int, studentStudentComp, uintStudentComp>::inorder(SBBSTNode *sr);

/*
 * Prints SBBST
 * 
 * requires  - root != null
 * ensures   - MySBBST is printed
 *
 */
template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::printout()
{
	if (root != NULL){
		cout<<" "<< root;
	}
	//inorder();
}
/*
template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::inorder()
{
	//if (root != null){
		
	//}
}
*/
/*
template <class Elem, class Key, class EEComp, class KEComp>
void MySBBST<Elem, Key, EEComp, KEComp>::inorder(SBBSTNode *sr)
{
	//if (sr != NULL){
		//inorder(sr->left);
		//cout<<r->e<<" ";
		//inorder(sr->right);
	//}
}
*/