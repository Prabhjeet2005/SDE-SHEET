class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int currentIndex = 0;
        int positiveIndex = 0;
        int negativeIndex = 0;

        while(positiveIndex < nums.size() && negativeIndex < nums.size()){
            while(positiveIndex < nums.size() && nums[positiveIndex] <= 0 ){
                positiveIndex++;
            }   
            while(negativeIndex < nums.size() && nums[negativeIndex] > 0 ){
                negativeIndex++;
            } 

            if(currentIndex %2 == 0){
                ans.push_back(nums[positiveIndex]);
                positiveIndex++;
                currentIndex++;
            }  else{
                ans.push_back(nums[negativeIndex]);
                negativeIndex++;
                currentIndex++;
            }
        }

        while(positiveIndex < nums.size() && nums[positiveIndex] >= 0){
            ans.push_back(nums[positiveIndex]);
            positiveIndex++;
            currentIndex++;
        }
        while(negativeIndex < nums.size() && nums[negativeIndex] < 0){
            ans.push_back(nums[negativeIndex]);
            negativeIndex++;
            currentIndex++;
        }
        return ans;
    }
};