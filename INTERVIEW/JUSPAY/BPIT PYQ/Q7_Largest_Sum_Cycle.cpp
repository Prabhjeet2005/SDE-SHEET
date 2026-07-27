/*
Largest Sum Cycle
Problem Statement:
You are given a maze with N cells. Each cell may have multiple entry points but not more
than one exit.
You are given an array Edge[] of N integers, where:

Edge[i] contains the cell reachable from cell i in one step
Edge[i] = -1 means the ith cell has no exit
Your task is to find the sum of the largest cycle in the maze.
The sum of a cycle is defined as the sum of node indices present in that cycle.

Note:
Cells are numbered from 0 to N-1
Constraints:
1 <= N <= 10^5

Input Format:
First line contains integer N
Second line contains N integers representing Edge[]

Output Format:
Print a single integer representing the sum of nodes forming the largest cycle.
If no cycle exists, print -1.
Sample Input:
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
Sample Output:
45
*/