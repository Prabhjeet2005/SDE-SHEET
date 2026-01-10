class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        for(int i=0; i<order.size();i++){
            if(find(friends.begin(),friends.end(),order[i]) != friends.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};