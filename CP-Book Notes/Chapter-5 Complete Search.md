>General method to solve any algorithm problem, the idea is generate all possible brute force solutions then select the best solution out of those.

Complete search is a good technique, it's almost always guarranted to find the correct answer.

If complete search is too slow for a task, use *greedy* or *dynamic programming* algorithm.

# Problem-1 : Generating subsets

**Statement:** Generate all the possible subsets of an array. (2^n)

## Approach-1 :
Using the recursive approach and layout all the possible combinations of the array (2^n).
![[Pasted image 20231112101909.png]]

Function search code:

```cpp
vector<int> subset;           // To store all the element of a subset.
vector<vector<int>> subsets;  // To store all the subset.

void search(int k){
	if(k==n){
		subsets.push_back(subset);
	} else {
		search(k+1);
		subset.push_back(k);      // push_back(arr[k]), for generating subsets of arr.
		search(k+1);
		subset.pop_back();         //Idea of stack push and pop.
	}
}

// Call the function with parameter=0.
search(0);
```

## Approach-2 :
Using bit technique.

let's say for a set having 3 elements. No. of total possible combinations are 2^3 (8). write down the binary of all 8 numbers.

```cpp
000 -> 0
001 -> 1
010 -> 2
.
.
111 -> 15

Each bit representing the corresponding element presence. from right to left.
101 -> {0 2}
```

Source Code :
```cpp
// 1<<n => 1*2^n
for(int b=0; b<(1<<n); b++){
	vector<int> subset;
	for(int i=0; i<n; i++){
		if(b&(1<<i)) subset.push_back(i);
	}
	for(int x: subset){
		cout << x << " ";
	}
	cout << endl;
}       
```

---
# ~~Problem-2 : Generating Permutations~~

**Statement:** Generate all the possible permutations of a given set {0, 1, ..., n-1}  (n!)

## Approach-1 :
Using recursive function.

==Will add later after more deeper inspection of the given code.==

---


# Backtracking

A backtracking algorithm begins with an empty solution and extends the solution step by step.
Recursively goes and appends upon all the possible combinations.

To understand better, consider the popular question of **placing n queens on a board of nxn chess.**

when n=4, possible combination is:
![[Pasted image 20231112120518.png]]

Backtracking approach : placing the queen row by row, and only moving forward with correct combination. like in following illustration :-
![[Pasted image 20231112120734.png]]

In bottom, first three configurations are illegal, only the 4th one is a partial solution.

### Code implementation for the above logic:
The following consider that rows are columns are numbered from 0..n-1. 
`search(y)`, function places the queen at yth-row. When `y=n` a solution has been found and variable count is incremented by one.

```cpp
int column[50]; int diag1[50]; int diag2[50];
int count = 0, n =8;

void search(int y) { 
	if (y == n) { 
		::count++; 
		return; 
	} 
	for (int x = 0; x < n; x++) { 
		if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue; 
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1; 
		search(y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0; 
	} 
}
```

-----
# Pruning the Search

It is like adding the intelligence to a backtracking algorithm. So it can *notice* if a partial solution cannot be extended to complete solution *as soon as possible*.

## Problem statement : 
Find the no. of ways to visit all the square boxes on chess board such that each one is visited and visited exactly 1 time only. 

Like in the following image (n x n):
![[Pasted image 20231112123335.png]]

### Basic backtracking : 
Brute-forcing our way and make all the possible recursive calls.
- Running-time : 483 seconds
- Recursive calls : 76 billion

### Optimization-1 :
In any solution, starting from upper-left we either go 1 down or 1 right. There *will always be 2 paths* that are symmetric about the diagonal of grid.

![[Pasted image 20231112124137.png]]

We can decide to move only in one direction(say 1 down), and then multiply the no. of possibilities by 2.

- Running-time : 244 seconds
- Recursive calls : 38 billion

### Optimization-2:
If the path reaches the lower right cell before visiting all the other ones, then we can anyway discard the remaining possibilities.

![[Pasted image 20231112124352.png]]

- Running-time : 119 seconds
- Recursive calls : 20 billion

### Optimization-3:
If the path has hit the wall, then it can go either left or right. Which obviously won't result in visiting all the cells.

![[Pasted image 20231112124553.png]]

- Running-time : 1.8 seconds
- Recursive calls : 221 million

### Optimizaton-4:
The idea of optimization-3 can be generalized, so it can go either left or right, which again is wasting of time.

![[Pasted image 20231112124819.png]]

- Running-time : 0.6 seconds
- Recursive calls : 69 million

Now compare the before and after results in algorithm performance:

|  Algorithm  |   Run-time | Rec calls |
|:-----|---:|----:|
| Basic Backtracking | 483 seconds | 76 billion|
| Optimization-1 | 244 seconds | 38 billion|
|Optimization-2 | 119 seconds | 20 billion|
|Optimization-3 | 1.8 seconds | 221 million |
|Optimization-4 | 0.6 seconds | 69 million| 

---

# ~~Meet in the middle technique~~

Will be added later on!

----

