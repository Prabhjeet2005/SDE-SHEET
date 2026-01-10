class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> mpp;
        int maj=0;
        int num=nums.size();
        for(int i=0;i<num;i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(auto it : mpp){
            if(it.second>num/2){
                ans= it.first;
            }
        }
        return ans;
    }
};