#include<bits/stdc++.h>
class Solution {
    static bool customOperator(int &a,int &b){
        return a>b;
    }
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),customOperator);
        int currK = 0;
        if(k==1)return {nums[0]};
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i])continue;
            ans.push_back(nums[i]);
            if(ans.size() == k)break;
        }
        return ans;
    }
};