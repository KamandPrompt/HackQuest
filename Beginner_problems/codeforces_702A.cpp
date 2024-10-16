/*

Problem added by Kaustubh Srivastava - B23141
Problem Link - https://codeforces.com/contest/702/problem/A

Problem ->
You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

Input ->
The first line contains single positive integer n (1 ≤ n ≤ 10⁵) — the number of integers.
The second line contains n positive integers a₁, a₂, ..., aₙ (1 ≤ aᵢ ≤ 10⁹).

Output ->
Print the maximum length of an increasing subarray of the given array.
*/


#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Accept the input
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    /*
    Using a sliding window
    If the subarray is increasing, keeping the leftPtr at the start of the window, keep incrementing the rightPtr increasing the window size
    When the element at index rightPtr is not greater than previous element, update maxLen with the length of the window in range [leftPtr, rightPtr) and move the window's starting point to index rightPtr
    */

    int leftPtr = 0, rightPtr = 1, maxLen = 1;
    while (rightPtr < n) {
        if (a[rightPtr] <= a[rightPtr - 1]) {
            maxLen = max(maxLen, rightPtr - leftPtr);
            leftPtr = rightPtr;
        }
        rightPtr++;
    }
    
    // Check once more as the longest increasing subarray could be at the end of the array in which case the if condition would never be executed
    maxLen = max(maxLen, rightPtr - leftPtr);

    // Display the output
    cout << maxLen << endl;
    return 0;
}