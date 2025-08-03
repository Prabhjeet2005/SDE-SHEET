SUBARRAY -> CONTINOUS

Unoptimised 1              O(N3)
Take maxi = INT_MIN
1st loop i=0 to n:
2nd loop j=i to n
int sum = 0
3rd loop i to <= j
maxi = max(sum,maxi)

return maxi


UnOptimised 2 :         O(N2)
take a loop i = 0 to n
int sum = 0
take another loop j=i to n
sum+=arr[ j ]
maxi = max(maxi,sum)

return maxi

OPTIMIZED:- O(N)
loop i=0 to n
sum += arr[ i ]
if sum > maxi:
maxi = sum

if sum < 0:   // Important to use after and if  [ NEGATIVE DISCARD SUM For FURTHER ]
sum = 0

return maxi




