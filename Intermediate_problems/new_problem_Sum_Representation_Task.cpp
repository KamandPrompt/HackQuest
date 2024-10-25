/*
Problem Statement:
Given an integer N, find the minimum array A = [a1, a2, a3, ..., ak] such that every integer from 1 to N 
can be represented as a sum of elements in A, where each element can be used at most two times.

Input:
- A single integer N (1 ≤ N ≤ 1000)

Output:
- Print the array A with the minimum number of elements such that every integer from 1 to N can be formed 
  using elements of A, where each element is used at most twice.

Example:
Input:
6
Output:
1 2
Explanation:
1:1
2:2
3:2+1
4:2*2
5:2*2+1
6:2*2+1*2


Analysis:
- In a binary representation, we typically use powers of 2 (1, 2, 4, 8, ...) to represent numbers. Each power 
  of 2 can only appear atmost once in a binary number. However, in this problem, each element in array A can appear 
  at most twice, which gives us more flexibility.
- We can achieve this by using powers of 3 instead of powers of 2, effectively allowing a ternary-like 
  representation where each power can be used up to two times. 
- This approach enables us to cover the range from 1 to N with fewer elements, compared to the binary method.

Approach:
1. Start with 1 and continue adding powers of 3 to array A.
2. For each power, calculate 3^i and add it to A until 2 * 3^i exceeds N.
3. By using powers of 3 up to this limit, we ensure that all integers from 1 to N can be covered, as each 
   element can appear up to two times.

Correctness: you can represent any number in ternary-like representaion now u observe every digit is either 0,1 or 2 
and now try to change it into decimal means you multiply with pawer base of 3.
Time Complexity: O(log(N)), as we only calculate powers of 3 up to a point where twice the sum covers N.
Space Complexity: constant space .

*/

#include <iostream>
using namespace std;


int main() {
    int N;
    cin >> N;
    int power = 1;
    
    // Add powers of 3 until twice the power exceeds N
    while (power <= N) {
        cout<<power<<" ";
        power *= 3;
    }
    
    cout<<'\n';
   
    
   
    
    return 0;
}
