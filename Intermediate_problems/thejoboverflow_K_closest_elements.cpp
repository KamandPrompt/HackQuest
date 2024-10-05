/*
link to the problem : https://thejoboverflow.com/problem/285/

Problem:
    Given an N-sized array of integers and value 'X', find the k closest integers with respect to 'X'.
    It is guaranteed that X is present in the given array.
    In case there are two values with same distance from 'X', prefer the smaller value.

    Input
    First line contains a single integer corresponding to integer N.
    Second line contains N space separated integers corresponding to the values in the given array.
    Third line contains two space separated integers corresponding to 'k' and 'X'

    Constraints

    1≤k<N≤100000
    1≤arr[i],X≤109
    
    Example
    Input
    10
    1 2 3 4 5 10 9 8 7 6
    3 4

    Output
    2 3 5 
*/

/*
    Solution 1: Naive Approach : Sort the array and then iterate and compare the difference and store
                                accordingly to the array and then print them 

    Solution 2: Heap : Use heap of size k to store the elements in the pair form where first element of pair is 
                        difference between x and the second elements is element of array with which difference is taken.
                        1. Push the first k elements in the priority queue (max)
                        2. Then check if the pq's top is 0 if is it means that we have added by mistake the x also in the 
                            pq , so just pop it out and add the kth index element and its difference with x in pq 
                        3. Then iterate on remaining elements and compare that if difference of element and x is smaller than the top of pq's difference 
                            then pop top of pq and push the new one 
                        At last we will get k elements in our answer
                        Sort them and print them 
                        Complexity Analysis :
                            O(nlogk + klogk) = O(nlogk)                                
                        Space Complexity :
                            O(k) (not considering the array used for taking input of elements)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long  
int main() {
    int n;cin>>n;
    vector<ll> a(n);
    priority_queue<pair<ll,ll>> pq;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll k,x;cin>>k>>x;
    for(int i=0;i<n;i++){
        if (a[i]==x) continue;
        if(pq.size()<k) pq.push({abs(a[i]-x),a[i]});
        else{
            if(pq.top().first>abs(a[i]-x) || (abs(a[i]-x)==pq.top().first && a[i]<pq.top().second)) {pq.pop();pq.push({abs(a[i]-x),a[i]});}
        }
    }
    vector<ll> b;
    while(!pq.empty()){
        b.push_back(pq.top().second);
        pq.pop();
    }
    sort(b.begin(),b.end());
    for (int i = 0; i < b.size(); i++)
    {
        cout<<b[i]<<" ";
    }
    

    return 0;
}
//  all test cases passed 