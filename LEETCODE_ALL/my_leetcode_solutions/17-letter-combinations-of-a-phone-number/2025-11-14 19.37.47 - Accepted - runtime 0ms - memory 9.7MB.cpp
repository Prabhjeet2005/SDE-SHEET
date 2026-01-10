class Solution {
    void all_combo(int curr_digit_index, string digits, string& curr_string,
                   vector<string>& ans,unordered_map<char,string>&num_alpha) {
        if (curr_digit_index >= digits.size()) {
            ans.push_back(curr_string);
            return;
        }

        int curr_digit = stoi(to_string(digits[curr_digit_index]));
        for(int i=0; i<num_alpha[curr_digit].size(); i++){
            curr_string += num_alpha[curr_digit][i];
            all_combo(curr_digit_index+1, digits, curr_string, ans,num_alpha);
            curr_string.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr_string = "";
        unordered_map<char, string> num_alpha = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        all_combo(0, digits, curr_string, ans,num_alpha);

        return ans;
    }
};