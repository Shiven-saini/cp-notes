#include <bits/stdc++.h>

using namespace std;

/*Approach-1 :
* Two-pointers technique
* Time-complexity : O(n)
* Space-complexity : O(1)
*/

vector<int> twoSum(vector<int>& nums, int target){
    int fp = 0, sum = 0;
    int lp = nums.size() - 1;

    while (fp<lp) {
        sum = nums[fp] + nums[lp];

        if (sum == target) {
            return {fp+1, lp+1};
        }
        else if (sum < target) {
            fp++;
        }
        else {
            lp--;
        }
    }
    return {};
}