class Solution {
    void findMaxMin(vector<int>&bloomDay,int &maxi,int &mini){
        for(auto &element:bloomDay){
            maxi = max(maxi,element);
            mini = min(mini,element);
        }
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = INT_MIN,mini = INT_MAX,minDays=-1;
        findMaxMin(bloomDay,maxi,mini);
        int size = bloomDay.size();
        if(size < (long long)m*k){
            return -1;
        }

        int start = mini,end = maxi;
        while(start <= end){
            int mid = start + (end-start)/2;
            int count=0,bouquetsFormed= 0;
            for(int i=0; i<bloomDay.size();i++){
                if(bloomDay[i] <= mid)count++;
                else{
                    bouquetsFormed += count / k ;
                    count=0;
                }
            }
            bouquetsFormed += count / k ;
            if(bouquetsFormed >= m){
                minDays = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }

        }
        return minDays;
        
    }
};