#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(int x) {
    if (x < 0) return false;
    long long a = x, b = 0;
    while (x) {
        b = b * 10 + x % 10;
        x /= 10;
    }
    return a == b;
}
