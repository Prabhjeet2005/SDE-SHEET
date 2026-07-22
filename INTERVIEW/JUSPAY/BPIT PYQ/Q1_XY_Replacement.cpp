/*
Problem Statement: A sorcerer has discovered a magical sequence of runes, represented as
a string made up of two types of runes: X and Y. The sorcerer wants to maximize their
magical power by transforming the sequence into more potent forms. They can perform the
following transformations:
1. Pick a substring "XY"
, transform it into "YZ"
, and gain one unit of magical power.
2. Pick a substring "YX"
, transform it into "ZY"
, and gain one unit of magical power.
Your task is to find out the maximum magical power the sorcerer can accumulate by
performing these transformations optimally. Constraints:
1 <= |s| <= 200000
The string contains only characters X and Y
Input Format:
A single line containing the string s.
Output Format:
Print a single integer representing the maximum magical power obtainable.
Sample Input:
YXYYXY
Sample Output:
2
*/

#include<iostream>
#include<vector>
using namespace std;

int solution(string s){
  int ans = 0;
  int count_segment_X=0;
  int count_segment_Y = 0;
  int min_segement_X = 1e9;
  bool continous_Y = false;
  int count_X = 0;
  int count_Y=0;

  for(int i=0; i<s.size(); i++){
    // Count Segment X
    if(s[i]=='X'){
      int length_segment_X=0;
      while(i<s.size() && s[i] == 'X'){
        count_X++;
        length_segment_X++;
        i++;
      }
      
      // Reduce i for Outer For Loop
      i--;
      count_segment_X++;
      min_segement_X = min(min_segement_X,length_segment_X);
    }
    else{

      int length_segment_Y = 0;
      while(i < s.size() && s[i]=='Y'){
        count_Y++;
        length_segment_Y++;
        i++;
      }
      
      i--;
      count_segment_Y++;
      if(length_segment_Y > 1)continous_Y=true;
    }
  }

  // 3 Conditions
  // Condn 1: Count_Segment_X <= Count_Segment_Y -> All X can be converted
  // Condn 2: (else if continous_Y == true) -> Go in Both Direction, All X can be converted 
  // Condn 3: Sacrifice the Smallest Segment of X as not go in both direction

  if(count_segment_X <= count_segment_Y)return count_X;
  else if(continous_Y)return count_X;
  else return count_X - min_segement_X; // Sacrifice

}

int main(){
  int ans = solution("YXYYXY"); // 2
  cout<<endl<<ans<<endl;
}