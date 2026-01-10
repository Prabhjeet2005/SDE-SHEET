class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mpp;
        int maj=0;
        int num=nums.size()/2;
        for(auto a:nums){
            mpp[a]++;
        }
        int ans=0;
        for(auto it : mpp){
            if(it.second>num){
                ans= it.first;
            }
        }
        return ans;
    }
};