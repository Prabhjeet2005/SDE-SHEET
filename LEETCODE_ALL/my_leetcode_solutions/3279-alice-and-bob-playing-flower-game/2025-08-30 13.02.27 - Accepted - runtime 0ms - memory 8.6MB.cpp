class Solution {
public:
    long long flowerGame(int n, int m) {
        int nOdd = (n+1)/2,nEven = n/2,mOdd=(m+1)/2,mEven=m/2;
        return 1ll*nOdd*mEven + 1ll*mOdd*nEven;
    }
};