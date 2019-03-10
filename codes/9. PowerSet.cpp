#include <bits/stdc++.h>
using namespace std;

// BaseCase and Build (03/10)

vector<vector<int>> ANS;

// Top-Down Recursion
// What's the runtime / space complexity for this solution?
// TC: O(2^n) where n is num of elements 
// SC: O(2^n)
// Correct! Do you want to try bottom up as well?
// Also it would be interesting to see if you can solve this with one vector only
// You're currently using both curr & ans correct? You can further simplify it :) [Done]
void getPowerSet_TopDown(int idx, vector<int>&nums, vector<int>& curr) {
    if(idx == nums.size()) {
        ANS.push_back(curr);
        return;
    }
    
    // exclusion of element at curr idx
    getPowerSet_TopDown(idx+1, nums, curr);
    
    // inclusion of element at curr idx
    curr.push_back(nums[idx]);
    getPowerSet_TopDown(idx+1, nums, curr);
    curr.pop_back(); // backtrack
}


// Bottom-Up Recursion
vector<vector<int>> getPowerSet_BottomUp(int idx, vector<int>& nums) {
    if(idx == nums.size()) {
        return {{}};
    }
    
    vector<vector<int>> nextSets = getPowerSet_BottomUp(idx+1,nums);
    vector<vector<int>> ans;
    
    for(auto V:nextSets) {
        // exclusion
        ans.push_back(V);
        // inclusion
        V.push_back(nums[idx]);
        ans.push_back(V);
    }
    
    return ans;
}


int main() {
    vector<int> nums = {1, 2, 3}; 
    
    /*
    vector<int> curr = {};  
    getPowerSet_TopDown(0,nums,curr);
    
    for(auto V:ANS) {
        for(int i=0;i<V.size();i++) 
            cout<<V[i]<<" ";
        cout<<endl;
    }
    */
    
    vector<vector<int>> ANS2 = getPowerSet_BottomUp(0,nums);
    
    for(auto V:ANS2) {
        for(int i=0;i<V.size();i++) 
            cout<<V[i]<<" ";
        cout<<endl;
    }
    return 0;
}
