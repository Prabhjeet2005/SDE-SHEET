class Solution {
private:
    void keypad(vector<string>& ans, string output, string mapping[], int index,
                string ques) {
        if (index >= ques.size()) {
            if (output.size() > 0) {
                ans.push_back(output);
            }
            return;
        }
        int num = ques[index] - '0';
        string alphabets = mapping[num];
        for (int i = 0; i < alphabets.size(); i++) {
            output.push_back(alphabets[i]);
            keypad(ans, output, mapping, index + 1, ques);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            cout << "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string output = "";
        int index = 0;
        keypad(ans, output, mapping, index, digits);
        return ans;
    }
};