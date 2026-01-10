class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max1 = 0, max2 = 0, min = 0;
        // case 1
        int size = nums.size();
        long long product1 = (long long)nums[size-1] * nums[size-2];
        long long product2 = (long long)nums[0] * nums[1];
        long long max_product = (long long)INT_MIN;
        int index1=0,index2=0;
        if(abs(product1) > abs(product2)){
            max_product = product1;
            index1 = size-1;
            index2 = size-2;
        }else{
            max_product = product2;
            index1 = 0;
            index2 = 1;
        }

        int i=0,j=size-1;
        while(i<j){
            if(abs((long long)nums[i] * nums[j]) > abs(max_product)){
                index1 = i;
                index2 = j;
                max_product = (long long)nums[i]*nums[j];
            }
            if(nums[i] < nums[j]){
                i++;
            }else{
                j--;
            }
        }

        if(max_product < 0){
            return (long long)max_product * -1e5;
        }else{
            return (long long)max_product * 1e5;
        }
    }
};