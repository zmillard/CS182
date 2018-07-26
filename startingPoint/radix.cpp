#include "sorting.hh"
/**
 * Implements the radix algorithm.
 * 
 * @author    Zoe Millard
 * @version   1.1
 * @since     20150227
 *
 */
template void Sortings<int, intuival>::radix(int*, unsigned int); //second is intuival 

template <class Elem, class Comp>
/*
 * Uses the radix algorithm to sort the elements of the array 
 * 
 * requires  - arr != null && 0 <= n < the length of arr
 * ensures   - contents of the array are sorted
 *
 * @param   arr   The array of elements to be sorted
 * @param   n   The size of the data to be sorted
 */
void Sortings<Elem, Comp>::radix(Elem *arr, unsigned int n)
{ 
	if(arr != NULL && n > 1){
		Elem *temp;
		unsigned int RADIX = 16;
		unsigned int count[RADIX]; // = new int[RADIX];
		unsigned int b[n]; 
		unsigned int max, exp, i;
	
		for(i = 1, max = arr[0]; i < n; i++){
			if(arr[i] > max){
				max = arr[i];
			}
		}
		for(i = 0; i < n; i++){
			temp[i] = Comp::uintVal(arr[i]);
		}
		for(exp = 1; max/exp > 0; exp *= RADIX){
			for(i = 0; i < RADIX; i++){
				count[i]= 0;
			}
			for(i = 0; i < n; i++){
				count[(temp[i] / exp) % RADIX]++;
			}
			for(i = 1; i < RADIX; i++){
				count[i] += count[i - 1];
			}
			for(i = n - 1; i >= 0; i--){
				b[--count[(temp[i] / exp) % RADIX]] = temp[i];
			} 
			for(i = 0; i < n; i++){
				arr[i] = b[i];
			}
		}
	}
}