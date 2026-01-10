class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size() % k != 0){
            return false;
        }
        sort(nums.begin(),nums.end());

        int countDuplicates=1;
        int maxCountDuplicate = 0;
        for(int i=0;i<nums.size();i++ ){
            if(i==0)continue;
            if(nums[i-1] == nums[i])countDuplicates++;
            if(nums[i-1]!= nums[i])countDuplicates = 1;

            maxCountDuplicate = max(maxCountDuplicate,countDuplicates);
        }
        
        if(maxCountDuplicate == 0){
            return true;
        }
        cout<<maxCountDuplicate;

        int sizeDivideDuplicate = nums.size() / maxCountDuplicate;
        if(sizeDivideDuplicate < k){
            return false;
        }
        return true;

        
    }
};