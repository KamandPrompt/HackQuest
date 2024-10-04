/*
Problem link: https://codeforces.com/contest/2004/problem/A

Problem statement:

Consider a set of points on a line. The distance between two points i and j is |i - j|.
The point i from the set is the closest to the point j from the set if there is no other point k in the set such that the distance from j to k is strictly less than the distance from j to i. In other words, all other points from the set have a distance to j greater than or equal to |i - j|.

Example:
Consider a set of points {1, 3, 5, 8}:
- For the point 1, the closest point is 3 (other points have a greater distance than |1 - 3| = 2).
- For the point 3, there are two closest points: 1 and 5.
- For the point 5, the closest point is 3 (but not 8, since its distance is greater than |3 - 5|).
- For the point 8, the closest point is 5.

Task:
You are given a set of points. You have to add an integer point into this set in such a way that:
1. It is different from every existing point in the set.
2. It becomes the closest point to every point in the set.

Is it possible?

Input:
The first line contains one integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case consists of two lines:

- The first line contains one integer n (2 ≤ n ≤ 40) — the number of points in the set.
- The second line contains n integers x_1, x_2, ... , x_n (1 ≤ x_1 < x_2 < ... < x_n < 100) — the points in the set.

Output:
For each test case, print "YES" if it is possible to add a new point according to the conditions from the statement. Otherwise, print "NO".
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;               //Number of test cases
    while(t--){
        int n;
        cin>>n;             //Number of points in the set
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];             //Input the points
        }

        if(n!=2){                   //Such a point is only possible for n=2
            cout<<"NO"<<endl;
        }
        else{
        if(abs(a[0]-a[1])>1){       //Minimum distance between two points should be 1 to insert a point between them
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            }
        
        }
        }
    }
