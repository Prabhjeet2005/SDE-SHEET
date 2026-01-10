class Solution {
public:
    int minimumFlips(int n) {
        string reversed = "";
        while(n!=0){
            string rem = to_string(n%2);
            n/=2;
            reversed += rem;
        }
        string original = reversed;
        reverse(original.begin(),original.end());
        int ans = 0;
        for(int i = 0; i<reversed.size(); i++){
            if(reversed[i] != original[i])ans++;
        }
        return ans;
        
    }
};