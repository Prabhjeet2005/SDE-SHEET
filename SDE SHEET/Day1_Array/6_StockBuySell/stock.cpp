class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mini) {
                mini = prices[i];
            } else {
                int difference = prices[i] - mini;
                maxi = max(maxi, difference);
            }
        }
        if (maxi <= 0) {
            return 0;
        }
        return maxi;
    }
};