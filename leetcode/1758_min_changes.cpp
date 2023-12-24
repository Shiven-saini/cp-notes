#include <bits/stdc++.h>
using namespace std;


int minOperations(string s) {
    int ctr = 0;
    int str_len = s.length();
    for(int i=0; i<str_len; i++) {
        if (i%2){
            ctr += s[i]=='0' ? 1 : 0;
        } else {
            ctr += s[i]=='1' ? 1 : 0;
        }
    }
    return ctr < str_len - ctr ? ctr : str_len - ctr;
}

int main() {
    string name = "001";
    int output = minOperations(name); 
    cout << output << endl;
}