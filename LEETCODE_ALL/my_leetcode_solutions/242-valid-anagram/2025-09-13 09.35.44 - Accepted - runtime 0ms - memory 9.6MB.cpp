class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[256]={0};

        for(int i=0 ;i <s.size();i++){
            freq[s[i]]++;
        }
        for(int i=0 ;i <t.size();i++){
            freq[t[i]]--;
        }
        for(auto &element:freq){
            if(element != 0 ){
                return false;
            }
        }
        return true;
    }
};