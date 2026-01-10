class Solution {

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int c=0;
        vector <int> finals;
        while(c<k){
            int min=nums[0],mul=1,ans=0;
            int i=0;
            while(i<nums.size()){
                if(nums[i]<min){
                    min=nums[i];
                    ans=i;
                }
                    i++;
                
                
            }
            mul=multiplier*min;
            nums[ans]=mul;
            for(int i=0; i<nums.size(); i++){
                cout<<nums[i]<<" ";
            }cout<<endl;
            int j=0;
            while(j<nums.size() && c==k-1){
                if(j==ans){
                    finals.push_back(mul);
                }else{
                    finals.push_back(nums[j]);
                }j++;
            }
            c++;
        }
        return finals;
    }
};
    
