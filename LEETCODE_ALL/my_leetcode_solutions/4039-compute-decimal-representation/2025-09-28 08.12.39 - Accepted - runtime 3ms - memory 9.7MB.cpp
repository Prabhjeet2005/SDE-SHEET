class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        if(n>=1 && n<=9)return {n};
        int power = 0;
        vector<int>ans;
        while(n!=0){
            int remainder = n%10;
            if(remainder != 0){
                if(power == 0){
                    ans.push_back(remainder);
                }else{
                    int pushArr = remainder * (pow(10,power));
                    ans.push_back(pushArr);
                }
            }
            power++;
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};