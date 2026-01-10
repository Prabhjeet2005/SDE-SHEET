class Solution {
    static bool customOperator(pair<char, int>& s1, pair<char, int>& s2) {
        if (s1.second > s2.second)
            return true;
        if (s1.second < s2.second)
            return false;
        return s1.first < s2.first; // Return smaller Occuring Character
    }

public:
    string frequencySort(string s) {
        if(s.size() <=2)return s;
        vector<pair<char, int>> frequency(256, {NULL, 0});
        for (auto& ch : s) {
            frequency[ch - '0'].first = ch;
            frequency[ch - '0'].second += 1;
        }
        sort(frequency.begin(), frequency.end(), customOperator);
        string ans = "";
        for (auto& element : frequency) {
            if (element.second != 0) {
                for (int i = 0; i < element.second; i++)
                    ans += element.first;
            }
        }
        return ans;
    }
};