class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int,int>map;
        int nCpy = n,remainder;
        while(nCpy != 0){
           remainder = nCpy %10;
            map[remainder]++;
            nCpy /= 10;
        }

        int leastDigit=INT_MAX,leastFreq = INT_MAX;
        for(auto &it:map){
            if(it.second >= leastFreq)continue;
            
            leastFreq = min(it.second,leastFreq);
            
            leastDigit = it.first;

        }
        return leastDigit;
        
    }
};