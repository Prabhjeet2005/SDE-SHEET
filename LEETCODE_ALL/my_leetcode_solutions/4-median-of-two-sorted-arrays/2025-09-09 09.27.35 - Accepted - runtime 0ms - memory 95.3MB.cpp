class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        if(n1 > n2)return findMedianSortedArrays(nums2,nums1);

        int leftHalfSize = (n1 + n2 + 1)/2;

        int start = 0, end = n1;

        while(start <= end){
            int mid1 = start + (end - start)/2; // No. Array1 Elements in Left Half
            int mid2 = leftHalfSize - mid1;// No. Array2 Elements in Left Half

            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1-1>=0 && mid1-1 < n1 )l1 = nums1[mid1-1];
            if(mid2-1 >=0 && mid2-1 < n2 )l2 = nums2[mid2-1];
            if(mid1>=0 && mid1 < n1 )r1 = nums1[mid1];
            if(mid2>=0 && mid2 < n2 )r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1 ){
                if((n1+n2)%2==0){
                    //EVEN
                    long double ans = (long double)(max(l1,l2) + min(r1,r2))/(long double)2;
                    return ans;
                }else{
                    // Odd
                    long double ans = (long double)(max(l1,l2));
                    return ans;
                }
            }
            else if(l1 > r2){
                end = mid1-1;
            }else{
                start = mid1+1;
            }
        }
        return -1;
    }
};