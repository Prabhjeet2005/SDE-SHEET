class Solution {
    int findMax(vector<int>&nums){
        int maxi = INT_MIN;
        for(auto& element:nums){
            maxi = max(maxi,element);
        }
        return maxi;
    }
    int calculateSum(vector<int>&nums,int threshold,int divisor){
        int currentSum = 0;
        for(auto &element:nums){
            currentSum += ceil((double)element / (double)divisor);
            if(currentSum > threshold)return currentSum;
        }
        return currentSum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxElement = findMax(nums);
        int start = 1,end = maxElement,finalDivisor=-1;

        while(start <= end){
            int mid = start + (end-start)/2;
            int currentSum = calculateSum(nums,threshold,mid);
            if(currentSum <= threshold){
                finalDivisor = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return finalDivisor;
    }
};