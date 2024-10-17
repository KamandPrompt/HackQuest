/* Problem link: https://codeforces.com/problemset/problem/2025/A

Problem Statement: 

There are two screens which can display sequences of uppercase Latin letters. Initially, both screens display nothing.

In one second, you can do one of the following two actions:

- choose a screen and an uppercase Latin letter, and append that letter to the end of the sequence displayed on that screen;
- choose a screen and copy the sequence from it to the other screen, overwriting the sequence that was displayed on the other screen.

You have to calculate the minimum number of seconds you have to spend so that the first screen displays the sequence s, and the second screen displays the sequence t.

Input:
The first line contains one integer q (1 ≤ q ≤ 500) — the number of test cases.
Each test case consists of two lines. The first line contains the string s
, and the second line contains the string t (1 ≤ |s|,|t| ≤ 100). Both strings consist of uppercase Latin letters.

Output:
For each test case, print one integer — the minimum possible number of seconds you have to spend so that the first screen displays the sequence s, and the second screen displays the sequence t.
*/

/*
Algorithm:

1. Input: Number of test cases q, followed by input of strings s and t for each test case q.

2. For each test case:
   
   Case 1: If at least the first two characters of s and t are common(cutstart == 2)
   - Find the common prefix of strings s and t
     - Iterate till k < smaller size (size of string t or size of string s)
     - if (s[k]==t[k]) then increment cut (counter) by one
     - and if at any value of k if condition (s[k]==t(k)) is not satisfied, then break the loop (i.e. stop the counter); 
   - Let cut(a variable) be the length of common prefix
   - Output: cut + 1 + (length of s - cut) + (length of t - cut)

   Case 2: If the first two characters are not common (cutstart != 2)
   - If t is longer or equal to s:
     - If s is a prefix of t:
       Output: 1 + length of s + (length of t - length of s)
     - Else:
       Output: length of s + length of t
   - If s is longer than t:
     - If t is a prefix of s:
       Output: 1 + length of t + (length of s - length of t)
     - Else:
       Output: length of s + length of t
*/

#include <bits/stdc++.h>
using namespace std;

int main()  {
    int q;                      //We take number of test cases as input
    cin>>q;
    vector <int> outputVec;
    for(int i=0;i<q;i++) {      //Run a for loop which iterate until all the test cases are done
        string s;
        cin>>s;
        string t;
        cin>>t;
        int cutstart=0;         //Here we check whether first two characters of string s and t are atleast common or not
            if(s[0]==t[0]) {
                cutstart++;
                if(s[1]==t[1]) {
                    cutstart++;
                }
            }
            if(cutstart==2) {   //Here we apply the algo if atleast first two characters of string s and t are common
                if(t.size()>=s.size()) {
                    int cut=0;
                    for(int k=0;k<s.size();k++) {
                        if(s[k]==t[k]) {
                            cut++;
                        }
                        else {
                            break;
                        }
                    }
                    cout<<cut+1+(s.size()-cut)+(t.size()-cut)<<endl;
                }
                else {         //Here we apply the algo if atleast first two characters are not common of string s and t
                    int cut=0;
                    for(int k=0;k<t.size();k++) {
                        if(t[k]==s[k]) {
                            cut++;
                        }
                        else {
                            break;
                        }
                    }
                    cout<<cut+1+(t.size()-cut)+(s.size()-cut)<<endl;
                }
            }
            else {
                    if(t.size()>=s.size()) {
                        string r=t.substr(0,s.size());   // string.substr(satrt position, number of characters to go) will slice the string
                        if(s==r) {
                            cout<<1+s.size()+(t.size()-r.size())<<endl;
                        }
                        else {
                            cout<<s.size()+t.size()<<endl;
                        }
                    }
                    else {
                        string r=s.substr(0,t.size());
                        if(t==r) {
                            cout<<1+t.size()+(s.size()-r.size())<<endl;
                        }
                        else {
                            cout<<t.size()+s.size()<<endl;
                        }
                    }
                }
    }
    return 0;
}
