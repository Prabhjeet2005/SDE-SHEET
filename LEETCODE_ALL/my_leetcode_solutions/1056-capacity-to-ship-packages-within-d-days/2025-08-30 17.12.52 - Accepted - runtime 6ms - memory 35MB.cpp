class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int  sumArr = accumulate(weights.begin(),weights.end(),0);
        int maxi = *max_element(weights.begin(),weights.end());
        int start = maxi,end = sumArr,finalCapacity=-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int currentDays = 1, currentPackageWeight = 0;
            for(auto &package : weights){
                if(currentPackageWeight + package > mid){
                    currentDays++;currentPackageWeight = package;
                }else{
                    currentPackageWeight += package;
                }
            }

            if(currentDays <= days){
                finalCapacity = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return finalCapacity;
    }
};