class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int orn = 0;
        for(auto &el:nums){
            if(el%2==0){
                orn = orn | el;
            }
        }
        return orn;
    }
};