/*
Parcel Count Maximization
Problem Statement:
Mike is a logistics manager at a parcel delivery company. There are n delivery stops, each
initially assigned a number of parcels represented by an array p.
The company allows the vans to load additional parcels at each stop using a permutation of
the delivery stops from 1 to n.
Mike may choose exactly one permutation q = [q1, q2, ..., qn], and then update each stop's
parcel count using:
p[i] := p[i] + q[i]
Mike's goal is to maximize the number of delivery stops that end up with the same number of
parcels after this operation.
Constraints:

1 <= n <= 200000
1 <= p[i] <= 10^9
q is a permutation of numbers from 1 to n
Input Format:
First line contains integer n
Second line contains n integers representing array p
Output Format:
Print a single integer representing the maximum number of stops having equal parcel count
after applying the permutation.
Sample Input:
6
1 1 1 1 1 2
Sample Output:
2
*/