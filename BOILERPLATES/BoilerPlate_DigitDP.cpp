#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
The Problem: Count Numbers with a Target Sum
Count how many numbers from 0 to R have a digit sum exactly equal to target. (For example, if R = 25 and target = 5, the valid numbers are 05, 14, 23).
*/

// [total digits/index][tight][leading_zero][property(sum)]
// sum -> 9*18 so make 200 as max sum
int dp[20][2][2][200];

int solve(string& num,int target_sum,int index,bool tight, bool lz, int sum){
  if(index == num.size()){
    return sum == target_sum;
  }

  if(dp[index][tight][lz][sum]!=-1)return dp[index][tight][lz][sum];

  // If still on edge then go till curr_number other place 0 to 9
  int limit = tight ? (num[index]-'0'): 9;  
  int count = 0;

  for(int digit = 0; digit <= limit; digit++ ){

    bool new_tight = (tight && (digit == limit) );
    bool new_lz = (lz && (digit == 0));

    int new_sum = sum;
    if(!new_lz){
      new_sum += digit;
    }

    count += solve(num,target_sum,index+1,new_tight,new_lz,new_sum);

  }
  return dp[index][tight][lz][sum] = count;
}

int main(){
  string R = "25";
  int target_sum = 5;

  for(int i=0; i<20;i++)
    for(int j=0; j<2;j++)
      for(int k=0; k<2; k++)
        for(int l=0; l<200;l++)
          dp[i][j][k][l]=-1;
  
  cout<<"Count: "<<solve(R,target_sum,0,true,true,0);

}