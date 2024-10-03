/*
This problem is 1987B from codeforce
Problem link:https://codeforces.com/contest/1987/problem/B

Problem Statement:-

You are given an array of integers a of length n.

You can apply the following operation any number of times (maybe, zero):
First, choose an integer k such that 1≤k≤n and pay k+1 coins.
Then, choose exactly k indices such that 1≤i1<i2<…<ik≤n.
Then, for each x from 1 to k , increase aix by 1.
Find the minimum number of coins needed to make a non-decreasing. That is, a1≤a2≤…≤an.

Input
Each test contains multiple test cases. The first line of input contains a single integer t (1≤t≤104)— the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n(1≤n≤105) — the length of the array a.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array a.
It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, output a single integer — the minimum number of coins needed to make a non-decreasing.

Example
Input
4
3
1 7 9
5
2 1 4 7 6
4
1 3 2 4
1
179
Output
0
3
2
0
*/

// Solution:-
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
 
long long fun() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    long long k = 0;
    long long maxIncrement = 0;
 
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            long long increment = static_cast<long long>(a[i]) - a[i + 1];
            k += increment;
            a[i + 1] = a[i];
            maxIncrement = max(maxIncrement, increment);
        }
    }
 
    return k + maxIncrement;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        cout << fun() << endl;
    }
 
    return 0;
}