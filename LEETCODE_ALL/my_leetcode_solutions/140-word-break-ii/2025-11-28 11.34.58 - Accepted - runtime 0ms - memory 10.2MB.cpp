class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>final_ans;
        unordered_set<string>wordDictSet(wordDict.begin(),wordDict.end());
        string curr_str = "";

        find_word_break(s,wordDictSet,0,curr_str,final_ans);

        return final_ans;
    }
private:

    void find_word_break(string s,unordered_set<string>& wordDict, int index,string& curr_str,vector<string>& final_ans){
        if(index >= s.size()){
            final_ans.push_back(curr_str);
            return;
        }

        for(int i=index;i <s.size(); i++){
            string curr_substr = s.substr(index,i-index+1);

            if(wordDict.count(curr_substr)){
                int curr_str_size = curr_str.size();

                curr_str.size() == 0 ? curr_str += curr_substr : curr_str += " " + curr_substr;
                find_word_break(s,wordDict,i+1,curr_str,final_ans);
                curr_str.erase(curr_str_size);
            }
        }
    }
};