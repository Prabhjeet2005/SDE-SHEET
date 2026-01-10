class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxLength = 0;

        for(int i=0; i<nums.size();i++){
            unordered_set<int>odd;
            unordered_set<int>even;

            for(int j=i;j<nums.size();j++){
                int currNumber = nums[j];

                if(currNumber % 2 == 0){
                    even.insert(currNumber);
                }else{
                    odd.insert(currNumber);
                }

                if(even.size() == odd.size()){
                    int currSize = j-i+1;
                    maxLength = max(maxLength,currSize);
                }
            }
            
        }
        return maxLength;
    }
};