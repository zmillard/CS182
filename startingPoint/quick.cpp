#include "sorting.hh"
/**
 * Implements the quick sort algorithm.
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150227
 *
 */
template void Sortings<int, intintCompare>::quick(int*, unsigned int);
template void Sortings<int, intintCompare>::quickRecurse(int*, unsigned int, unsigned int);
template unsigned int Sortings<int, intintCompare>::findPivot(int*, unsigned int, unsigned int);
template unsigned int Sortings<int, intintCompare>::partition(int*, unsigned int, unsigned int);


template void Sortings<char*, strstrCompare>::quick(char**, unsigned int);
template void Sortings<char*, strstrCompare>::quickRecurse(char**, unsigned int, unsigned int);
template unsigned int Sortings<char*, strstrCompare>::findPivot(char**, unsigned int, unsigned int);
template unsigned int Sortings<char*, strstrCompare>::partition(char**, unsigned int, unsigned int);


/*
 * Uses the quick sort algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= n < the length of arr
 * ensures   - calls quickRecurse
 *
 * @param   arr   The array of elements to be sorted
 * @param   n   The size of the data to be sorted
 *
 */
template <class Elem, class Comp>
void Sortings<Elem, Comp>::quick(Elem *arr, unsigned int n)
{
	if (arr != NULL && n > 1){
		if (n < (sizeof(arr)) / sizeof(Elem)){ //if n is greater than the max possible size...
			n = sizeof(arr)/sizeof(Elem); 
		}
		quickRecurse(arr, 0, n-1);
	}
}
/*
 * Uses the quick sort algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= l < length of array, 0<= & r < the length of arr
 * ensures   - contents of the array are sorted by recursively calling itself, while the l < r
 *
 * @param   arr   The array of elements to be sorted
 * @param   l   The leftmost data location
 * @param   r   The rightmost data location
 *
 */
template <class Elem, class Comp>
void Sortings<Elem, Comp>::quickRecurse(Elem *arr, unsigned int l, unsigned int r)
{
	if (l < r){
		int p = partition(arr, l, r);
		quickRecurse(arr, l, p - 1);
		quickRecurse(arr, p + 1, r);
	}
}
/*
 * Uses the quick sort algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= l < length of array, 0<= & r < the length of arr
 * ensures   - the pivot is returned
 *
 * @param   arr  The array of elements to be sorted
 * @param   l    The leftmost data location
 * @param   r    The rightmost data location
 * @return       The pivot is returned   
 *
 */
template <class Elem, class Comp>
unsigned int Sortings<Elem, Comp>::findPivot(Elem *arr, unsigned int l, unsigned int r)
{
	// << ((l +(r - l))/2) << endl;
	return (r);
	
}
/*
 * Uses the quick sort algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= l < length of array, 0<= & r < the length of arr
 * ensures   - the array is partitioned
 *
 * @param   arr   The array of elements to be sorted
 * @param   l   The leftmost data location
 * @param   r   The rightmost data location
 * @return      The partition is returned
 */
template <class Elem, class Comp>
unsigned int Sortings<Elem, Comp>::partition(Elem *arr, unsigned int l, unsigned int r)
{
	unsigned int pindex = findPivot(arr, l, r);
	//cout<<"P: "<<arr[pindex]<<endl;
	unsigned int i = l;
	unsigned int j = r;
	while (i < j){
		while(Comp::lt(arr[i], arr[pindex])){//arr[l] < pivot){ //this works
			i++;
		}
		while(Comp::gt(arr[j], arr[pindex])){//arr[r] > pivot){ //this works
			j--;
		}
		if (Comp::eq(arr[j], arr[i])){
			i++;
		}else if(i < j){
			swap(arr, i, j);		
		}
	}
	return pindex;
}