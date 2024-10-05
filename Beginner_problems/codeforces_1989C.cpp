// // https://codeforces.com/problemset/problem/1989/C

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;  // Input number of test cases
    while (t--){  // Loop through all test cases
        int n;
        cin >> n;  // Input the size of the arrays
        vector<int> m1(n);  // Array to store the first set of ratings
        vector<int> m2(n);  // Array to store the second set of ratings
        
        // Input for the first array
        for(int i = 0; i < n; i++){
            cin >> m1[i];
        }
        
        // Input for the second array
        for(int i = 0; i < n; i++){
            cin >> m2[i];
        }
        
        int both_ones = 0;     // Count where both m1 and m2 are 1
        int both_neg_ones = 0; // Count where both m1 and m2 are -1
        int rating_m1 = 0;     // Separate rating contribution from m1
        int rating_m2 = 0;     // Separate rating contribution from m2

        // Analyze each pair of ratings in m1 and m2
        for(int i = 0; i < n; i++){
            if(m1[i] == 1 && m2[i] == 1){
                both_ones++;  // Both ratings are 1, count this scenario
            }
            else if(m1[i] == -1 && m2[i] == -1){
                both_neg_ones++;  // Both ratings are -1, count this scenario
            }
            else if(m1[i] == 1 && m2[i] <= 0){
                rating_m1++;  // m1 is 1, but m2 is less than or equal to 0
            }
            else if(m1[i] <= 0 && m2[i] == 1){
                rating_m2++;  // m1 is less than or equal to 0, but m2 is 1
            }
        }

        // Distribute the pairs where both are 1 to balance the ratings
        for(int i = 0; i < both_ones; i++){
            if(rating_m1 > rating_m2){
                rating_m2++;  // Increase rating_m2 to balance with rating_m1
            }
            else{
                rating_m1++;  // Otherwise, increase rating_m1
            }
        }

        // Distribute the pairs where both are -1 to balance the ratings
        for(int i = 0; i < both_neg_ones; i++){
            if(rating_m1 > rating_m2){
                rating_m1--;  // Decrease rating_m1 to balance with rating_m2
            }
            else{
                rating_m2--;  // Otherwise, decrease rating_m2
            }
        }

        // Output the minimum of the two ratings to ensure a balanced result
        cout << min(rating_m1, rating_m2) << endl;
    }
    return 0;
}