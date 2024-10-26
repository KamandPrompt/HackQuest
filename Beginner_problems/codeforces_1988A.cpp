// Problem added by Priansh Yajnik-B24318
/*
PROBLEM STATEMENT
https://codeforces.com/problemset/problem/1988/A

Tags - brute force , greedy ,implementation , math*900

A multiset is a set of numbers in which there can be equal elements, and the order of the numbers does not matter. For example, {2,2,4}
is a multiset.

You have a multiset S
. Initially, the multiset contains only one positive integer n
. That is, S={n}
. Additionally, there is a given positive integer k
.

In one operation, you can select any positive integer u in S and remove one copy of u from S.
Then, insert no more than k positive integers into S so that the sum of all inserted integers is equal to u.

Find the minimum number of operations to make S contain n ones.

Input:
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000).
 
  Description of the test cases follows.

The only line of each testcase contains two integers n,k
 (1≤n≤1000,2≤k≤1000).

Output:
For each testcase, print one integer, which is the required answer.
*/

//Solution to the problem:

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

int main() {
    int tc; // Variable to store number of test cases
    cin >> tc; // Read number of test cases
    for (int u = 0; u < tc; u++) { // Loop through each test case
        int n; // Variable to store the value of n
        int k; // Variable to store the value of k
        cin >> n >> k; // Read n and k for the current test case
        int step = 0; // Initialize step counter
        list<int> v; // Create a list to store values
        v.push_back(n); // Push the initial value n into the list

        // If n is 1, the answer is 0 (no steps needed)
        if (n == 1) {
            cout << 0 << endl; // Output 0
            continue; // Move to the next test case
        }

        // If n is less than or equal to k, only one step is needed
        if (n <= k) {
            cout << 1 << endl; // Output 1
            continue; // Move to the next test case
        }

        // If k is 1, the answer is simply n (as we can only decrement by 1)
        if (k == 1) {
            cout << n << endl; // Output n
        } else {
            while (*(v.begin()) > k) { // While the front of the list is greater than k
                int ct = 0; // Counter for steps taken
                int flag = 0; // Flag to check if we need to break the loop
                // Inner loop to decrement n by k until ct equals k-1
                while (ct != k - 1) {
                    n -= k; // Decrease n by k
                    ct++; // Increment counter
                    v.push_back(k); // Add k to the list
                    // Check if n is less than or equal to k
                    if (n <= k) {
                        flag = 1; // Set flag to indicate we should break
                        // Depending on the value of n, add either 1 or n to the list
                        if (n <= k - ct) {
                            v.push_back(1); // Push 1 if n is small enough
                        } else {
                            v.push_back(n); // Otherwise, push n
                        }
                        v.pop_front(); // Remove the front element from the list
                        break; // Break out of the inner loop
                    }
                }
                step += 1; // Increment step count
                // If flag is set, break out of the outer loop
                if (flag == 1) {
                    break;
                } else {
                    v.pop_front(); // Remove the front element
                    v.push_front(n); // Push the updated n to the front of the list
                }
            }
            // Count how many elements in the list are not equal to 1
            for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it != 1) {
                    step++; // Increment step for each element not equal to 1
                }
            }
            
            cout << step << endl; // Output the final step count
        }
    }
}
