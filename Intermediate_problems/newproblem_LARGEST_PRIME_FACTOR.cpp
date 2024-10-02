/*
# Problem Statement
You are given `t` test cases (1 ≤ t ≤ 10^5). For each test case, you are provided with an integer `n` such that 1 < n ≤ 10^6. Your task is to determine the largest prime factor of `n`.

Example : 
INPUT
5
2
5
10
17
1001

OUTPUT
2
5
5
17
13

## Approach
The solution involves a modified version of the Sieve of Eratosthenes:

### Precomputation
- Precompute the largest prime factor for all numbers up to 10^6 using a sieve approach.
- Create an array `largest_prime` where `largest_prime[i]` stores the largest prime factor of `i`.

### Answer Queries in Constant Time
- After precomputation, answer each query in O(1) time by simply looking up the value in the `largest_prime` array.

## Sieve of Eratosthenes Explanation
The Sieve of Eratosthenes is a simple and efficient algorithm for finding all prime numbers up to a specified integer. It works by iteratively marking the multiples of each prime number starting from 2. In this modified version, instead of only marking non-prime numbers, we record the largest prime factor for each number.

## Complexity Analysis
- **Time Complexity**:
  - Precomputation: O(n log log n), where n = 10^6.
  - Query Time: O(1) for each query.
  
- **Space Complexity**: 
  - O(n) for storing the largest prime factor for each number.

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;

// Create a vector to store the largest prime factor for each number
vector<int> largest_prime(MAX_N + 1, 0);

// Precompute the largest prime factor for each number using the modified sieve
void sieve_largest_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (largest_prime[i] == 0) {
            // i is a prime number
            for (int multiple = i; multiple <= MAX_N; multiple += i) {
                largest_prime[multiple] = i;
            }
        }
    }
}

int main() {
    // Precompute largest prime factors
    sieve_largest_prime();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Output the largest prime factor for n
        cout << largest_prime[n] << '\n';
    }

    return 0;
}
