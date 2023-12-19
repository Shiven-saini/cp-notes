#include <bits/stdc++.h>

using namespace std;


/* Approach-1
* Brute-force 
* Time-complexity : O(n^2)
*/

vector<int> twoSum(vector<int>& nums, int target){
    int sum = 0;

    for (int i=0; i<nums.size()-1; i++){
        for (int j = i+1; j<nums.size(); j++){
            sum = nums[i] + nums[j];
            if(sum == target) return {i, j};
        }
    }
    return {};
}

int main(){
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> solution = twoSum(nums, target);
    for (auto i: solution) {
        cout << i << " ";
    }
}