//Codeforces-1901A--A line trip
//https://codeforces.com/contest/1901/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    //creating a loop for number of test cases
    int query;
    vector<int> fuel;
    cin >> query;
    while(query--){
    //declaring and initializing variables for the input    
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int i=1;
    int max_gap = arr[0];
    //Finding the maximum gap between two stations
    while(i<n && arr[i]<x){
        max_gap = max(arr[i]-arr[i-1], max_gap); 
        i++;
    }
    max_gap= max(max_gap, 2*(x-arr[i-1]));
    //adding answer to the final vector
    fuel.push_back(max_gap);
    }
    //Displaying the answers of every test cases
    for (int i =0;i<fuel.size();i++)
    {
        cout<<fuel[i]<<endl;
    }
    
    return 0;
}