
/*
Gridopolis Critical Blocks
Problem Statement:
In the city of Gridopolis, the city is arranged in a block formation with 2 parallel streets and n
intersections (blocks) along each street.
Some blocks are open and accessible (represented by '.') while others are closed for
construction (represented by 'x').
A block is accessible if it has a free passage on at least one of the streets.
Residents of Gridopolis want to ensure that their neighborhoods remain connected.
Two blocks are part of the same neighborhood if:
●​ they are accessible, and
●​ they can be reached through adjacent blocks either horizontally or vertically.
Your task is to identify critical blocks in the city grid:
●​ a block is critical if closing it would divide the city into exactly 3 separate
neighborhoods.
Input Format:
●​ First line contains an integer n (1 <= n <= 200000)
●​ Next two lines contain strings of length n
●​ Each character is either:
○​ '.' → open block
○​ 'x' → blocked cell
Output Format:​
Print a single integer representing the number of blocks that, if closed, would split the city
into exactly 3 connected neighborhoods.
Additional Constraint:​
Initially, there is at most one connected neighborhood in the grid.
Sample Input:​
8​
.....x..​
.x.xx...
Sample Output:​
1
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int calculate_critical_blocks(string &s1, string &s2){
    int critical = 0;

    for(int i=1; i<s1.size()-1; i++){
        bool row1_open = s1[i-1] == '.' && s1[i]=='.' && s1[i+1]=='.';
        bool row2_pinch = s2[i-1] == 'x' && s2[i]=='.' && s2[i+1]=='x';
        bool row2_open = s2[i-1] == '.' && s2[i]=='.' && s2[i+1]=='.';
        bool row1_pinch = s1[i-1] == 'x' && s1[i]=='.' && s1[i+1]=='x';

        if((row1_open && row2_pinch) || (row1_pinch && row2_open))critical++;
    }

    return critical;
}

int main(){
    string s1 = ".....x..";
    string s2 = ".x.xx...";
    cout <<"\n"<<calculate_critical_blocks(s1,s2)<<"\n";
}