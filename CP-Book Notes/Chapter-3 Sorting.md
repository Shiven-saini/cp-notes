> Sorting is one of the most important algorithm and parent for many more algorithms in general.



## O(n^2) Algorithms

Bubble sort is a common example with this complexity, so every consecutive element is **compared** in each iteration.

Generally, after `k` rounds, the `kth` largest element in position.

**Inversion:** refers to the pair of wrong ordered elements. More the inversions, more the work have to be done.

**Examples :-** Bubble, insertion, selection sort.

## O(nlogn) Algorithms

Merge sort is a common example with this complexity, it works on *divide and conquer* approach. Uses recursion and time complexity in recursive function `Time Complexity: single function complexity * no. of calls(log in this case, due to input getting half each iteration`

```pseudocode
Merge sort sorts a subarray array[a . . . b] as follows: 
1. If a = b, do not do anything, because the subarray is already sorted. 
2. Calculate the position of the middle element: k = b(a + b)/2c. 
3. Recursively sort the subarray array[a . . . k]. 
4. Recursively sort the subarray array[k + 1 . . . b]. 
5. Merge the sorted subarrays array[a . . . k] and array[k + 1 . . . b] into a sorted subarray array[a . . . b].
```

Lower bound possible for *comparison-based sort :-* O(nlogn)

## Counting sort

Most efficient sorting algorithm that sorts the array in O(n) complexity, but 0...c the c, should be small.

## Sort cpp implementation

> It's never a good idea to implement the sorting algorithm by yourself. use the sort already implemented in c++, which is a combination of insertion, quick, heap sort.

Syntax : `sort(vi.begin(), vi.end())` sort accepts 2 arguments, the pointer to first element and pointer to last element.

`begin() & end() are iterators, providing the address of vector elements to sort.`

**Reverse sorting:** `sort(vi.rbegin(), vi.rend())`

Optionally, sort also accepts a 3rd parameter that is a user-defined `compare` function, used for sorting user-defined datatypes or *overriding* already defined ones.