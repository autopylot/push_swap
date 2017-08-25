# Sorting

## In-place sorting

The sorting takes place within the array itself.

**Bubble Sort**

*	Time Complexity: O(n^2)
*	Adaptive: O(n) when nearly sorted

	**Pseudocode**
		1. Compare adjacent elements
		2. Swap elements if not sorted
		3. Each iteration sorts one element, therefore compare up to n - sorted
		4. Iterate length of array
		5. If no swap if performed array is sorted

**Insertion Sort**

Maintains a sub-list of sorted elements in lower part of array and searches for next sorted element to insert into sub-list.

*	Time Complexity: O(n^2)
*	Low overhead
*	Adaptive: O(n) when nearly sorted

	**Pseudocode**
		1. Compare adjacent elements
		2. Swap elements if not sorted
		3. Pick next element
		4. Insert element
		5. Compare element to sorted sub-list
		6. Shift elements in sorted sub-list that are greater

**Selection Sort**

Divides list into two parts, sorted (lower) and unsorted (upper). Search and select the smallest element from the unsorted list and insert into sorted list.

*	Time Complexity: O(n^2)
*	Minimize number of swaps, useful when cost of swap is high

	**Pseudocode**
		1.	Set `MIN` to location `0`
		2.	Search minimum element in unsorted
		3.	Swap element to location `MIN`
		4.	Increment `MIN`

**Shell Sort**

Based on insertion sort, but avoids large shifts in sub-list when inserting. Sorts wideley spread elements then less widely spread.  Sorts element using an interval: `h = h * 3 + 1 => (h -1) / 3`

*	Time Complexity: O(n^3/2), varies
*	Low overhead
*	Adaptive: O(n log n) when nearly sorted

	**Pseudocode**
		1.	Divide list into sub-lists at `h` interval
		2.	Sort sub-lists using insertion sort

**Quick Sort**

Parition list into two lists based on pivot element.  Recursively partition each list with pivot element until list of one element. Best sorting algorithm in general, because it requires no extra space and has best average complexity.

*	Time Complexity: O(n^2), but best average complexity O(n log n)

	**Pseudocode**
		1.	Set right-most index as pivot element
		2.	Parition list using pivot
			1.	Left pointer is low index, right pointer (exclude pivot) is high index
			2.	While left pointer < pivot move left pointer right
			3.	While right pointer > pivot move right pointer left
			4.	If exit while loops, swap left and right
			5.	If left pointer >= right pointer, index is new pivot
			6.	Recurse left with ind - 1
			7.	Recurse right with ind + 1
		3.	Quicksort each parition recursively

## Not-in-place sorting

The sorting requires more space than itself.

**Merge Sort**

*	Time Complexity: O(n log n)
*	Does not require random access to data, efficient with linked lists

	**Pseudocode**
		1.	Return list if one element
		2.	Divide list into two halves
		3.	Recurse each half until it cannot be divided
		4.	Merge smaller lists in a sorted order
