/*

### Problem: The Traveling Illusionist

You are an illusionist traveling through N consecutive cities to perform your magic show. In each city, the potential audience is willing to pay a certain amount of gold. You are given an integer array `A` of size N, where `A[i]` is the total gold available in the i-th city.

For each city, you must choose exactly one of three actions:

1. You can perform a Grand Illusion. This mesmerizes the entire audience, and you earn the full `A[i]` gold coins. However, this act is physically exhausting. If you perform a Grand Illusion, you are too tired to perform anything the next day and are forced to rest in the very next city.

2. You can perform a Basic Trick. This earns you exactly floor( A[i] / 2) gold coins (integer division by 2). This is less tiring, so you can perform Basic Tricks in as many consecutive cities as you like. However, you cannot step up to a Grand Illusion immediately after a Basic Trick. To have enough focus for a Grand Illusion, you must have rested the previous day.

3. You can rest. You earn 0 gold coins, but resting clears all fatigue and leaves you fully prepared to perform any act in the next city.

Assume you start your journey completely rested. Find the maximum total gold coins you can collect by the end of your tour.

**Constraints:**
* 1 <= N <= 10^5
* 1 <= A[i] <= 10^4

**Input Format:**
The first line contains an integer N, the number of cities.
The next N lines each contain an integer representing A[i].

**Sample Input:**

5
10
20
15
30
5


**Sample Output:**

50


***
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{

  public:
  void solution(int N, vector<int>&arr){
    // A Day Could be either of Following
    long long grand = 0;
    long long basic = 0;
    long long rest = 0;

    for(int i=0; i<N; i++){
      // if grand today then previously i must rest
      long long new_grand = rest + arr[i] ; 
      // basic today then previous basic and rest allowed
      long long new_basic = max(basic,rest) + floor(arr[i]/2) ; 
      // rest today then previously i could rest, grand or basic
      long long new_rest = max({grand,rest,basic}) + 0 ; 

      grand = new_grand;
      basic = new_basic;
      rest = new_rest;

    }
    cout<< max({grand,rest,basic});
  }
};

int main(){
  Solution sol = Solution();
  int N;
  cin>>N;
  vector<int>arr;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    arr.push_back(a);
  }
  cout<<"\n";
  sol.solution(N,arr);
  cout<<"\n";
}



