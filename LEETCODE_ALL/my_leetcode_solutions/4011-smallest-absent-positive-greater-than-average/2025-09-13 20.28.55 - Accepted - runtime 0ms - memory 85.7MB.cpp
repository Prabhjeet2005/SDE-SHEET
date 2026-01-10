class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sumArr = accumulate(nums.begin(),nums.end(),0);
        int avg = floor((double)sumArr /(double)nums.size() );
        if(avg <=0)avg = 0;
        for(int i = avg+1;i<=INT_MAX;i++){
            auto it = find(nums.begin(),nums.end(),i);
            if(it == nums.end()){
                return i;
            }
        }
        return 0;
    }
};