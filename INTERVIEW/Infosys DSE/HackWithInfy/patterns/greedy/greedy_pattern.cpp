#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
  int start_time;
  int end_time;
};

// SORT BY: end times (free up machine ASAP)
bool static custom_compare(Job a,Job b){
  return a.end_time < b.end_time;
}


class Solution{
  public:
  void solution(vector<Job>&jobs){
    sort(jobs.begin(),jobs.end(),custom_compare);

    int total_jobs = 0;
    int curr_end_time = 0;
    for(int i=0; i<jobs.size(); i++){
      if(jobs[i].start_time >= curr_end_time){
        total_jobs++;
        curr_end_time = jobs[i].end_time;
      }
    }
    cout<<"Jobs: "<<total_jobs;
  }
};

int main(){
  Solution sol = Solution();
  int N = 4;
  vector<Job> jobs = {{1, 10}, {2, 4}, {3, 6}, {5, 8}};

  cout<<"\n";
  sol.solution(jobs);
  cout<<"\n";
}