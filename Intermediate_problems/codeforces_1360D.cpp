// https://codeforces.com/problemset/problem/1360/D

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
 
typedef long long ll;
 
#define FOR(a, c) for (ll(a) = 0; (a) < (c); (a)++)
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll min_packages = LLONG_MAX;
        
        if (k >= n) {
            // If k is greater than or equal to n, we can buy n shovels in one go
            min_packages = 1;
        } else {
            // We need to find the minimum number of packages
            for (ll i = 1; i * i <= n; ++i) {
                if (n % i == 0) {
                    if (i <= k) {
                        min_packages = min(min_packages, n / i);
                    }
                    if (n / i <= k) {
                        min_packages = min(min_packages, i);
                    }
                }
            }
        }
        cout << min_packages << endl;
    }
    return 0;
}