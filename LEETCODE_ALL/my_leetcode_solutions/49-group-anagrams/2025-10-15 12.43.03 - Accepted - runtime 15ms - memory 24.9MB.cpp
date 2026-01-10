class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>anagramList;

        for(int i=0; i<strs.size();i++){
            string currentString = strs[i];
            sort(strs[i].begin(),strs[i].end());
            anagramList[strs[i]].push_back(currentString);
        }
        vector<vector<string>>ans;
        for(auto &iterator:anagramList){
            ans.push_back(iterator.second);
        }
        return ans;

    }
};