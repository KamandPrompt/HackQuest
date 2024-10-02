/*
This problem is part of  AlgoUniversity Technology Fellowship: Stage 2 Important Questions.
Problem link:https://thejoboverflow.com/problem/291/

Problem Statement:-

The next greater element of some element x in an array is the first greater element that is to the right 
of x in the same array.

You are given an integer array A containing n integers. Your task is to find the next greater element for 
every element in the array A.

Input
The first line of input contains an integer t(1≤t≤10^4) — the number of testcases. The description of t
testcases follows.

The first line of each testcase contains an integer n(1≤n≤10^5)— the number of elements in the array A.

The second line of each testcase contains n space separated integers a0,a1,...an(0≤ai≤10^9)— the elements 
of array A.

It is guaranteed that the sum of n over all testcases does not exceed 10^5.

Output
For each testcase, print n space separated integers — the ith integer should be the next greater element 
of the ith element in the array.

Example
Input
2
4
1 3 4 2
4
1 2 3 4
Output
3 4 -1 -1 
2 3 4 -1
*/

// Solution:-
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        // Initilaize next greater element for each value as -1
        vector<int>ans(n,-1);

        // We will use a stack to store the index of the elements
        stack<int>st;
        st.push(0); // 0th index

        // Iterate over the array from 1 to n-1 and find the next greater element for each element
        for(int i=1;i<n;i++){
            while(!st.empty() && a[i]>a[st.top()]){
                // If the current element is greater than the element at the top of the stack, pop the top element from stack and update the answer array
                int j=st.top();
                st.pop();
                ans[j]=a[i];
            }
            st.push(i); // push current index in the stack
        }
        for (auto i : ans) {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;

}

// Time Complexity: O(n)
// Space Complexity: O(n)