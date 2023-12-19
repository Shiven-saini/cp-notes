#include <bits/stdc++.h>
using namespace std;

/*Approach-1 : Brute force with higher space complexity.
* Time-complexity : O(n)
* Space-complexity : O(n)
*/

// vector<int> shuffle(vector<int>& nums, int n) {
//     vector<int> a, b, result;
//     for(int i=0; i<2*n; i++) {
//         if(i<n) a.push_back(nums[i]);
//         else b.push_back(nums[i]);
//     }
//     for (int i=0; i<n; i++){
//         result.push_back(a[i]);
//         result.push_back(b[i]);
//     }
//     return result;
// }

vector<int> shuffle(vector<int>& nums, int n) {
    int i=0, j=n;
    vector<int> result;
    while (i<n && j<2*n){
        result.push_back(nums[i]);
        result.push_back(nums[j]);
        i++; j++;
    }
    return result;
}


int main() {
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> output = shuffle(nums, 3);
    for(auto elem: output) {
        cout << elem << " ";
    }
}