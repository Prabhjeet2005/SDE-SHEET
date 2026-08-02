/*
Data Server Storage Consolidation
Problem Statement:
In a data center, servers are arranged in a rack with n server slots. However, due to varying
server installations, the servers are spread out across different slots.
You want to consolidate the servers into consecutive slots to improve data access efficiency.
Find the minimum number of moves required to place all the servers into consecutive slots.
In one move, you can move one server to any arbitrary position.
Function Description:​
Complete the solve function.
Parameters:
●​ n → number of servers
●​ a[] → array containing unique integers representing current server positions
Return:​
Return an integer representing the minimum number of moves required to make all server
positions consecutive.
Constraints:
●​ 1 <= n <= 10^5
●​ 1 <= a[i] <= 10^9
Input Format:
●​ First line contains integer n
●​ Next n lines contain integers representing server positions
Sample Input 1:​
5​
1​
2​
3​
5​
6
Sample Output 1:​
1
Explanation:​
Move server from position 6 to 4.Sample Input 2:​
4​
3​
5​
7​
9
Sample Output 2:​
2
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min_moves(vector<int>&arr){
    int n = arr.size();
    
    sort(arr.begin(),arr.end());
    

    int j=0;
    int max_window =-1;
    for(int i=0; i<n; i++){
        int curr_max_window = 0;
        while(j+1 < n && arr[j+1]-arr[i] < n){
            j++;
        }
        max_window = max(max_window,curr_max_window);
    }
    return max_window;
}

int main(){
    vector<int>arr = {3,5,7,9};
    cout<<min_moves(arr)<<"\n";

}