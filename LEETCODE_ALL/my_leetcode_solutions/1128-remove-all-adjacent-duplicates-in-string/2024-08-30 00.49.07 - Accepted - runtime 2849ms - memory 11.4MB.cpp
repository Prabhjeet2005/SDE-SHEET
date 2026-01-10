class Solution {
public:
    string removeDuplicates(string s) {
        for(int i=0;i<s.size();i++){
            if(s.size()==1) return s;
            if(s[i]==s[i+1]){
                s.erase(i,2);
                i=-1;
            }
        }
        return s;
    }
};