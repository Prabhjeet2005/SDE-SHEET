class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i=0,n=nums.size();
        vector <int> temp(n);
        while(i<n){
            int s=(i+k)%n;
            temp[s]=nums[i++];
            
        }
        nums=temp;
    }
};