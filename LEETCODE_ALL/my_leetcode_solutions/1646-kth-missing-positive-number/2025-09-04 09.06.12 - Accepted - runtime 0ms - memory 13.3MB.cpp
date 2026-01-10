class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int arrSize = arr.size();
        int start = 0,end = arrSize-1;

        while(start <= end){
            int mid = start + (end - start)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k)start = mid+1;
            else end = mid-1;
        }
        if(end <= -1)return k;
        return (k + (end +1));
    }
};