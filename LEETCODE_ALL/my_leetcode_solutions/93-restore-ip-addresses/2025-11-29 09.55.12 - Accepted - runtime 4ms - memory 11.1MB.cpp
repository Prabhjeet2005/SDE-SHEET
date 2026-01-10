class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> final_ans;
        int curr_index = 0, curr_segments = 0;
        string curr_str = "";

        solve(s, curr_index, curr_segments, curr_str, final_ans);
        return final_ans;
    }

private:
    void solve(string& s, int curr_index, int& curr_segments, string& curr_str,
               vector<string>& final_ans) {
        if (curr_segments >= 4 && curr_index >= s.size()) {
            final_ans.push_back(curr_str);
            return;
        }
        if (curr_segments >= 4 || curr_index >= s.size()) {
            return;
        }
        // Only 3 length each sub IP Address
        for (int i = curr_index; i < s.size() && i < curr_index+3; i++) {
            string ip_substr = s.substr(curr_index, i - curr_index + 1);

            if (is_valid(ip_substr)) {
                int size = curr_str.size();
                if (curr_str.size() > 0) {
                    curr_str += "." + ip_substr;
                } else {
                    curr_str += ip_substr;
                }
                curr_segments++; // This incremented regardless
                solve(s, i+1, curr_segments, curr_str, final_ans);
                curr_segments--;
                curr_str.erase(size);
            }
        }
    }

    bool is_valid(string& str) {
        if (str.size() > 1 && str[0] == '0')
            return false;
        if (stoi(str) < 0 || stoi(str) > 255)
            return false;

        return true;
    }
};