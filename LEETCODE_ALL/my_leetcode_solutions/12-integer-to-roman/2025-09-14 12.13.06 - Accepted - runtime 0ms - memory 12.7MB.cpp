class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mapArr = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        int justSmallerNumberIndex = mapArr.size()-1;
        string ans = "";
        while(num > 0 && justSmallerNumberIndex >= 0){
            if(num >= mapArr[justSmallerNumberIndex].first){
                ans += mapArr[justSmallerNumberIndex].second;
                num -= mapArr[justSmallerNumberIndex].first;
            }else{
                // Move to lesser roman number
                justSmallerNumberIndex--;
            }
        }
        return ans;
    }
};