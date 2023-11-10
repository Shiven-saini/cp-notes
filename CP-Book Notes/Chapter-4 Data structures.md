
> Choosing data structures are important, because each comes with it's own set of advantages & disadvantages.

## Dynamic array (or Vector)

`vector<datatype> name;`
- Add/remove the element dynamically at runtime.
- `push_back(), size(), back(), pop_back()`
- For more information, check out [Cpp-Reference](https://en.cppreference.com/w/cpp/container/vector)
- **Careful:** When the vector gets full in memory, new double the size will be allocated, which is costly.
- `vector<int> vi(5, 0);` : Initializes the vector vi with length of 5 elements, all values 0.

## String : Dynamic array

```cpp
string name = "shiven";
string name2 = name + name;        // shivenshiven
name[2] = 'u';                     // shuven

string substring = name.substr(0, 3)    //substr(index, len), shi

```
- Same functionality as an array.
- Special **+** operator for *concatenation* of strings.


## Set : set() | O(log n) & unordered_set() | O(1)

```cpp
set<int> s;
s.insert(2);                   /
s.insert(3);                   
s.size();                      // size = 2
s.count(2);                    // 1, either 0 or 1 (set property)

// Unique element can exist in a set.
s.insert(2);                  
s.size();                      // still, size = 2

s.erase(2);                    // Removes the '2'.
```

- Cannot iterate through it.
- `[]` concept of index is not present.
- Only one unique occurrence of an element can exist.

### Multiset & unordered multiset

- Can contain multiple occurrence of a single element.
- `erase` method removes all the occurrence of the given element.
- To remove only one occurrence : `s.erase(s.find(elem_to_remove));`
