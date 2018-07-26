#include "sorting.hh"
/**
 * Implements the selection algorithm.
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150227
 *
 */
 
template void Sortings<int, intintCompare>::select(int*, unsigned int);
template void Sortings<char*, strstrCompare>::select(char**, unsigned int);

template <class Elem, class Comp>
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
void Sortings<Elem, Comp>::select(Elem *arr, unsigned int n)
{
	int i, j, low;
	if (arr != NULL && n > 1){
		if (n < (sizeof(arr)) / sizeof(Elem)){ //if n is greater than the max possible size...
			n = sizeof(arr)/sizeof(Elem); 
		}
		for(i = 0; i < 6; i++){		
			low = i;
			for(j = i + 1; j < n; j++){
				if(Comp::lt(arr[j], arr[low])){ 
					low = j;
				}
			}
			if(low != i){
				swap(arr, i, low);
			}
		}
	}
}