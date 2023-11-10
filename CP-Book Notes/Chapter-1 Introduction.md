Cha
> Competitive programming is all about solving a given problem in the least amount of time possible. Hence, tips & tricks are necessary to shorten the amount of time taken.
# Basics
#### C++ Boilerplate
```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "Hello CP" << endl;
}
```

The first line `#include <bits/stdc++.h` is a gcc exclusive feature, this header file contains all the sorting, Data structures & other required files. No need to import them individually.

#### Input and Output

`cin >> a >> b` can take any number of inputs, the **limiter** is a white space(tab, enter, space).

```cpp
Input : 0, 2, 3, 5
for(int i=0; i<arr.size(); i++){
	cin >> arr[i];
}
```

Since, cin is limited by whitespace, what if we need to get an input (say full name) ?
`getline(cin, name)`
Any whitespace will be nonetheless included in the variable value.

Also, avoid using `std::endl` instead use `\n` for newline.

### Integers & numbers

`long long - 64 bit, suffixed with LL` and size(bytes) of any type can be checked by using 
`sizeof(<dataType>)`

#### Modulo operation

```matlab
(a + b) % m = (a % m + b % m) % m 
(a − b) % m = (a % m − b % m) % m 
(a · b) % m = (a % m · b % m) % m
```

#### Fraction numbers & precision

Generally, due to memory constraints precision is lost which in some cases may make 2 generally equivalent numbers not equal.

```cpp
double ans = 0.3*3 + 0.1; 
printf("%.20f", ans); // 0.9999999898
```

To compare them we will check if their diff is less than say e, (very small number 10^-9)

```cpp
if (abs(a-b) < 1e-9){
	cout << "Equal\n"; 
}
```


---

# Shortening codes

#### Typedef

`typedef long long ll;`

It can be used to shorten the code like in following example,
```cpp
typedef long long ll;
ll num1;
ll num2;
```

#### Macros

Macros is a vast topic and consists of many useful stuff and tools. But in *code shortening*, `#define` is used extensively.

```cpp
#define Print(X) cout << X << endl

int main(){
	Print("Hello Universe!");
}
```

It basically just, replaces the keyword before compiling stage, known as *preprocessing.*
*Use of Macros like lot of other stuff commonly used in CP is considered a bad practice in actual dev.*



