class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int count1 =( n1 + n2) / 2, count2 = count1 - 1,element1=-1,element2=-1;
        int i=0,j=0,ptr=0;

        while(i<n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(ptr == count1) element2 = nums1[i];
                if(ptr == count2) element1 = nums1[i];
                i++;ptr++;
            }else{
                if(ptr == count1) element2 = nums2[j];
                if(ptr == count2) element1 = nums2[j];
                j++;ptr++;
            }
        }
        while(i < n1){
                if(ptr == count1) element2 = nums1[i];
                if(ptr == count2) element1 = nums1[i];
                i++;ptr++;
        }
        while(j<n2){
                if(ptr == count1) element2 = nums2[j];
                if(ptr == count2) element1 = nums2[j];
                j++;ptr++;
        }

        if((n1 + n2) % 2 == 1){
            return (double)element2;
        }else{
            double ans = (double)(element1 + element2) / (double)2;
            return ans;
        }
    }
};