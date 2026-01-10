class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size=piles.size(),maxElement = INT_MIN,ans=-1;

        for(int i=0; i<size;i++)maxElement = max(maxElement,piles[i]);
        int start = 1,end = maxElement;
        while(start <= end){
            int mid = start + (end - start)/2;
            long long currentSum=0;
            for(auto &element:piles){
                currentSum += ceil((double(element)/double(mid)));
            }
            if(currentSum <= h){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};