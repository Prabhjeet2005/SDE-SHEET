class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>count;
        int i = nums.size()-1;
        while(i>=0){
            if(nums[i]==0){
                count[0]++;
            }
            else if(nums[i]==1){
                count[1]++;
            }
            else if(nums[i]==2){
                count[2]++;
            }
            i--;
        }
        vector<int> ans;
        for(int i=0; i<3; i++){
            int size = count[i];
            for(int j=0; j<size;j++){
                ans.push_back(i);
            }
        }
        nums=ans;
    }
};