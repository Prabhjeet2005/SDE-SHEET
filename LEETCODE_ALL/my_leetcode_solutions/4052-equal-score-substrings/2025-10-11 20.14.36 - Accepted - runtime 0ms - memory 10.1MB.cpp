class Solution {
public:
    bool scoreBalance(string s) {
        vector<int>prefix(s.size());
        vector<int>suffix(s.size());

        for(int i=0;i<s.size();i++){
            if(i==0){
                prefix[i]=(s[i]-'a')+1;continue;
            }
            prefix[i]=((s[i]-'a')+1)+prefix[i-1];
        }
        for(int i=s.size()-1;i>=0;i--){
            if(i==s.size()-1){
                suffix[i]=(s[i]-'a')+1;
                continue;
            }
            suffix[i]=((s[i]-'a')+1)+suffix[i+1];
        }

        for(int i=0; i<s.size();i++){
            if(i==0){
                if(prefix[i]==suffix[i+1])return true;
                continue;
            }
            if(i==s.size()-1){
                if(prefix[i]==0){return true;}
                continue;
            }
            if(prefix[i]==suffix[i+1])return true;
        }

        return false;
        
    }
};