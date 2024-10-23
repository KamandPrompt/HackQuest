//Problem link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

/*Problem Statement

Hint
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
 

Constraints:

1 <= n <= 20
1 <= k <= 2n - 1

*/

/*
# Intuition
<!-- This problem could be solved by making a copy and then revering and inverting bits in it -->

# Complexity
- Time complexity:
<!-- $$O(2^n)$$ -->

*/

/*Algorithm:
1)Initialization:

Start with the base string S initialized to "0".

2)terative Construction:

For each integer i from 2 to n, the string S is built according to a specific rule:
>>Invert: Create a copy of the current string S and invert all bits (0s become 1s and vice versa).
>>Reverse: Reverse the inverted string.
>>Concatenate: Form the new string S by concatenating the original string S, the character '1', and the inverted reversed string.

3)Finding the k-th Bit:

After constructing the string for n iterations, the 
𝑘
k-th character (1-based index) of the final string S is returned.

*/

// Code
#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string S="0";
        for(int i=2;i<=n;i++){
            string S2=S;
            //invert 
            for(int j=0;j<S2.size();j++){
                if(S2[j]=='0'){
                    S2[j]='1';
                }
                else{
                    S2[j]='0';
                }
            }
            //Reverse
            reverse(S2.begin(), S2.end());

            S=S+"1"+S2;
        }
         return S[k-1];
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    Solution ob;
    cout<<ob.findKthBit(n,k);
}