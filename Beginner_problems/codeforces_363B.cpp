// https://codeforces.com/problemset/problem/363/B

#include<iostream>
#include<vector>
#include<cstdint>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    vector<int>vec;
    int sum=0;
    int min=INT32_MAX;
    int min_index=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
        if(i<=k-1){
            sum+=a;
        }
        else{
            sum+=a;
            sum-=arr[i-k];
        }
        if(i>=k-1 && min>sum){
            vec.push_back(sum);
            min_index=i-k+2; 
            min=sum;
        }
    }
    cout<<min_index<<endl;
 
    return 0;
}