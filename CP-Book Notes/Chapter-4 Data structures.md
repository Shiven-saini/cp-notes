
> Choosing data structures are important, because each comes with it's own set of advantages & disadvantages.

## Dynamic array (or Vector)

`vector<datatype> name;`
- Add/remove the element dynamically at runtime.
- `push_back(), size(), back(), pop_back()`
- For more information, check out [Cpp-Reference](https://en.cppreference.com/w/cpp/container/vector)
- **Careful:** When the vector gets full in memory, new double the size will be allocated, which is costly.
- `vector<int> vi(5, 0);` : Initializes the vector vi with length of 5 elements, all values 0.

## String : Dynamic array

`string name = "shiven saini";`
- Same functionality as an array.
- Special **+** operator for *concatenation* of strings.

```cpp
string name = "shiven";
string name2 = name + name;        // shivenshiven
name[2] = 'u';                     // shuven

string substring = name.substr(0, 3)    //substr(index, len), shi

```


## Set : set() | O(log n) & unordered_set() | O(1)

`set<int> s;` or `unordered_set<int> s2;`
- Cannot iterate through it.
- `[]` concept of index is not present.
- Only one unique occurrence of an element can exist.

```cpp
set<int> s;
s.insert(2);                   
s.insert(3);                   
s.size();                      // size = 2
s.count(2);                    // 1, either 0 or 1 (set property)

// Unique element can exist in a set.
s.insert(2);                  
s.size();                      // still, size = 2

s.erase(2);                    // Removes the '2'.
```

### Multiset & unordered multiset

- Can contain multiple occurrence of a single element.
- `erase` method removes all the occurrence of the given element.
- To remove only one occurrence : `s.erase(s.find(elem_to_remove));`


## Map & unordered_map

`map<string, int> m;    //map<key, value> name;`

- Map Contains key-value pair.
- Function `map.count(key)` checks for presence of key in a map.
- To access key/value pair in a loop, `x.first` & `x.last` can be used respectively.

```cpp
map<string, int> week;
week["Sunday"] = 0;
week["Monday"] = 1;

cout << week["Monday"] << '\n';              // returns the value associated.
cout << week["Thursday"] << '\n';            // returns '0' for empty value key.
```

## Iterators & Ranges

An **Iterator** is a variable that points to an element in a data structure.
- `begin()` & `end()` are two most used iterators.
- `begin()` returns the address of first element.
- `end()` returns the address of the position 1 next to last element.
![[Pasted image 20231112072129.png]]

- Functionalities of common iterators.
```cpp
// To sort the array.
sort(v.begin(), v.end());

// To reverse the array.
reverse(v.begin(), v.end());

// To shuffle the array.
random_shuffle(v.begin(), v.end());
```

*When used with primitive arrays, they are given pointers to the first and last element.*

## Other important Data Structures.

> They are rarely used, but should be known that they can be used in rare circumstances too.

### Bitset
`bitset<10> s;  // bitset<size> name;` 
- Bitset : special type of array with elements being **only 0, 1.**
- It is more **memory efficient**, since only 1 bit is required to store one element.
- To quickly create a bitset : `bitset<10> s(string("000111001"))` remember *right-->left.*
- Logical operators like `&, |, ~, ^` can be used directly between 2 or more bitsets.

### Deque : Dynamic array
`deque<int> d;`
- Special type of array, where element can be removed from both ends, *back as well as front.*
- `push_back(), pop_back(), push_front(), pop_front()`
- Functionality of adding element at front is not available in **vectors**.
- **Slower** in comparison to vectors.

### Priority Queue
`priority_queue<int> q;`
- Similar to set, by default stores the inserted elements in a descending order.
- Faster than set, due to *heap structure* resulting in lower *constant factors*.
- `push(), pop(), top()` : some common methods available.
- To store in ascending order : `priority_queue<int,vector<int>,greater<int>> q;`