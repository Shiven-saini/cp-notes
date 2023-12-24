#include <bits/stdc++.h>
using namespace std;

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
