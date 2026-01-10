class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int,int>,int>fo;
        fo[{0,0}]=-1;
        int cx = 0,cb=0,ml=0;

        for(int i=0; i<nums.size();i++){
            cx ^= nums[i];
            if(nums[i] % 2 != 0)cb+=1;
            else cb-=1;

            if(fo.count({cx,cb})){
                int prev = fo[{cx,cb}];
                ml = max(ml,i-prev);
            }else fo[{cx,cb}] = i;
    }
    

        return ml;
    }
};