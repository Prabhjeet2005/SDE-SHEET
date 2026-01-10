class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> arr1(256, -1), arr2(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (arr1[s[i]] != arr2[t[i]])
                return false;
            arr1[s[i]] = i ;
            arr2[t[i]] = i ;
        }
        return true;
    }
};