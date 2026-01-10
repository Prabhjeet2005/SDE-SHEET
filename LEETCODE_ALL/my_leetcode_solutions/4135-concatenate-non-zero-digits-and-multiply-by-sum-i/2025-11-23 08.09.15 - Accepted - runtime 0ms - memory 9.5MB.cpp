class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>digits;
        long long sum = 0;
        string non_zero = "";
        while(n!=0){
            if(n%10 != 0){
                sum += n%10;
                non_zero += to_string(n%10);
            }
            n/=10;
        }

        if(non_zero.empty())return 0;

        reverse(non_zero.begin(),non_zero.end());

        return sum * stoll(non_zero);
    }
};