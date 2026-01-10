class Solution {
public:
    string majorityFrequencyGroup(string s) {
        if(s.size() == 1)return s;
        int freq[26] = {0};
        for(int i=0; i<s.size(); i++){
            freq[s[i] - 'a']++;
        }
        string ans = "";
        map<int,string>map;
        for(int i=0; i<26; i++){
            if(freq[i] == 0)continue;
            map[freq[i]]+= (char)(i+'a');
        }
        unsigned maxLen = 0;
        for(auto &it: map){
            if(it.second.size() >= maxLen ){
                maxLen = it.second.size();
                ans = it.second;
            }
        }

        
        return ans;
        
    }
};