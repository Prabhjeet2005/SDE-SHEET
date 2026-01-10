class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack; // colder_to_warmer
        vector<int> ans(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (stack.empty()) {
                stack.push(i);
                ans[i] = 0;
                continue;
            }
            while (!stack.empty() && temperatures[stack.top()] <= temperatures[i]) {
                // colder day at stack.top() will never be required anymore
                // because current is more warmer
                stack.pop();
            }
            if(!stack.empty())ans[i] = stack.top() - i;
            else ans[i]=0;
            stack.push(i);
        }
        return ans;
    }
};