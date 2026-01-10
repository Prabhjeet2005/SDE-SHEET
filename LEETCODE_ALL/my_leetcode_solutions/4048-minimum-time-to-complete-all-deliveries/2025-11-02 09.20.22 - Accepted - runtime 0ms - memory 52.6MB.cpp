class Solution {
    long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        vector<vector<int>> arr = {d, r};

        long long d1 = arr[0][0];
        long long d2 = arr[0][1], r1 = arr[1][0], r2 = arr[1][1];

        long long low = d1 + d2;
        long long high = 4000000000LL; 
        long long ans = high;

        while (low <= high) {
            long long total = low + (high - low) / 2;
            long long l = lcm(r1, r2);

            long long d1_drone = (total / r2) - (total / l);
            long long d2_drone = (total / r1) - (total / l);
            long long both_drone = total - (total / r1) - (total / r2) + (total / l);

            bool can_d1 = (d1 <= d1_drone + both_drone);
            bool can_d2 = (d2 <= d2_drone + both_drone);
            bool can_total = ((d1 + d2) <= (d1_drone + d2_drone + both_drone));

            if (can_d1 && can_d2 && can_total) {
                ans = total;      
                high = total - 1; 
            } else {
                low = total + 1;  
            }
        }

        return ans;
    }
};