#include<iostream>
#include<vector>
using namespace std;
class Solution{
  private:
  int nCr(int n,int r){
    // n! / r!*(n-r)!
    int nfact = 1;
    int rfact = 1;
    for(int i=1;i<=n;i++){
      nfact = nfact * i ;
    }
    for(int i=1;i<=r;i++){
      rfact = rfact * i ;
    }
    int nminusr = n-r;
    int nrfact=1;
    for (int i = 1; i <= nminusr; i++)
    {
      nrfact *= i;
    }
    return nfact / (rfact * nrfact);
  }
  public:
    void pascalTriangle(int row,int col){
      int rowAns = row-1;
      int colAns = col-1;
      cout<<nCr(rowAns,colAns)<<endl;
    }
};
int main(){
  Solution s = Solution();
  int row = 7;
  int col = 4;
  s.pascalTriangle(row,col);
}