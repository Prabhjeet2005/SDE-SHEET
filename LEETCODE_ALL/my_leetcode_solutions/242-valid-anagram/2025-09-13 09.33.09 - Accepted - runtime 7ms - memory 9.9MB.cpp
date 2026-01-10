class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>freq;

        for(int i=0 ;i <s.size();i++){
            freq[s[i]]++;
        }
        for(int i=0 ;i <t.size();i++){
            freq[t[i]]--;
        }
        for(auto &element:freq){
            if(element.second != 0 ){
                return false;
            }
        }
        return true;
    }
};