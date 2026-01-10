class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peak = 0,valley = 0, wavy = 0;

        for(int i=num1; i<=num2; i++){
            wavy += find_peak_valley(i);
        }
        return wavy;
    }
    private:
    int find_peak_valley(int num){
        vector<int>peak_arr;
        int count_peak = 0,count_valley=0;
        while(num!=0){
            peak_arr.push_back(num%10);
            num/=10;
        }

        for(int i=1;i<peak_arr.size()-1; i++){
            if(peak_arr[i] > peak_arr[i-1] && peak_arr[i] > peak_arr[i+1])count_peak++;
            else if(peak_arr[i] < peak_arr[i-1] && peak_arr[i] < peak_arr[i+1])count_valley++;
        }
        return count_peak + count_valley;
        
    }
};