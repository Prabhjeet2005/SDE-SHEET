class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefixProduct = nums[0], suffixProduct = nums[nums.size()-1],
                  maxProduct = max(prefixProduct,suffixProduct);
        bool allZero = true;
        for (int i = 1; i < nums.size(); i++) {
            if (prefixProduct == 0) {
                prefixProduct = 1;
            }
            if (suffixProduct == 0) {
                suffixProduct = 1;
            }
            allZero = false;
            prefixProduct *= nums[i];
            suffixProduct *= nums[nums.size() - i - 1];
            maxProduct = max(maxProduct, max(suffixProduct, prefixProduct));

        }


        if (allZero && nums.size() > 1) {
            return 0;
        }
        return maxProduct;
    }
};