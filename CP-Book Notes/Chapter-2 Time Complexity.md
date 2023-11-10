
> Actual challenge in competitive programming is to develop **fast** algorithm. Slower algos will get only partial points or no points.

**Time complexity :** Estimates the amount of time, the algorithm will use for some input. Generally, shown as a function with the input as a parameter commonly *n, no. of elements/inputs.*

## Calculation Rules
#### Loops

The more nested loops the alogrithm contains, slower it becomes. If there are *k* no. of nested loops, the time complexity is **O(n^k).**

Examples :- 

**O(n):**
```cpp
for (int i = 1; i <= n; i++) {
	// code 
}
```

**O(n^2):**
```cpp
for (int i = 1; i <= n; i++) { 
	for (int j = 1; j <= n; j++) {
		 // code 
	} 
}
```

#### Phases

If the algorithm consists of multiple time-complexities, the slowest one is the prominent one and hence the *rate-determining* step.

```cpp
for (int i = 1; i <= n; i++) {
	// O(n)
} 
for (int i = 1; i <= n; i++) { 
	for (int j = 1; j <= n; j++) {
		 // O(n^2)
	} 
} 
for (int i = 1; i <= n; i++) { 
	// O(n)
}

// Time-complexity is O(n^2).
```

#### Several variables

But whatif, the nested loops contains different number of iterations.

```cpp
for (int i = 1; i <= n; i++) { 
	for (int j = 1; j <= m; j++) { 
	// code 
	} 
}
```

**Time-complexity is O(n.m).**

#### Recursion

Time-complexity of a recursive function depends on number of calls and complexity of each call. The total time-complexity is the **product of number of calls & time-complexity of each cell.**

```cpp
void f(int n) { 
	if (n == 1) return; 
	f(n-1); 
}
```

**Time-complexity is O(nx1).**

----

## Complexity classes

![[Pasted image 20231103222436.png]]

#### Polynomial complexity

If time-complexity is of type **O(n^k)**, it is called polynomial algorithms. An algorithm with a polynomial complexity is considered *efficient.*

**NP-Hard:** Set of hard problems, for which no polynomial complexity(or efficient) algorithms is known to exist.

---

## Popular problem : Maximum subarray sum

A popular problem that explain how there can be more than one or even *faster* algorithm for a given problem.

#### Problem Statement:

Given an array of n numbers, find the largest possible sum of subarrays (i.e. consecutive values). The array might contains *-ve numbers* too.
![[Pasted image 20231103224329.png]]
Find a subarray like this :
![[Pasted image 20231103224358.png]]

**Algorithm-1:** O(n^3)
```cpp
int best = 0;
for (int a = 0; a < n; a++) {
    for (int b = a; b < n; b++) {
        int sum = 0;
        for (int k = a; k <= b; k++) {
            sum += array[k];
        }
        best = max(best,sum);
    }
}

cout << best << "\n";
```

**Algorithm-2:** O(n^2)
```cpp
int best = 0; 
for (int a = 0; a < n; a++) { 
	int sum = 0; 
	for (int b = a; b < n; b++) { 
		sum += array[b]; 
		best = max(best,sum); 
	} 
} 
cout << best << "\n";
```

**Algorithm-3:** O(n) | *Kadane's Algorithm*
```cpp
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
    sum = max(array[k],sum+array[k]);
    best = max(best,sum);
}
cout << best << "\n";
```
