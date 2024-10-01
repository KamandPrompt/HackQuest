# Problem Statement
You are given \( t \) test cases \((1 \leq t \leq 10^5)\). For each test case, you are provided with an integer \( n \) such that \( 1 < n \leq 10^6 \). Your task is to determine the largest prime factor of \( n \).

## Approach
The solution involves a Modified Sieve of Eratosthenes:

### Precomputation:
- Precompute the largest prime factor for all numbers up to \( 10^6 \) using a sieve approach.
- Create an array `largest_prime` where `largest_prime[i]` stores the largest prime factor of \( i \).

### Answer Queries in Constant Time:
- After precomputation, answer each query in \( O(1) \) time by simply looking up the value in the `largest_prime` array.

## Sieve of Eratosthenes Explanation
The Sieve of Eratosthenes is a simple and efficient algorithm for finding all prime numbers up to a specified integer. It works by iteratively marking the multiples of each prime number starting from 2. In our modified version, instead of only marking prime numbers, we record the largest prime factor for each number.

For a more detailed explanation, you can read about it [here](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).

## Complexity Analysis
- **Time Complexity:**
  - Precomputation: \( O(n \log \log n) \), where \( n = 10^6 \).
  - Query Time: \( O(1) \) for each query.
  
- **Space Complexity:** 
  - \( O(n) \) for storing the largest prime factor for each number.

## C++ Code Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1e6;

// Create a vector to store the largest prime factor for each number
vector<int> largest_prime(MAX_N + 1, 0);

void sieve_largest_prime() {
    // Step 1: Precompute largest prime factors using modified sieve
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
    // Step 2: Precompute largest prime factors
    sieve_largest_prime();

    int t;
    cout << "Enter number of test cases (1 <= t <= 5): ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter value of n (1 < n <= 10^6): ";
        cin >> n;

        // Output the largest prime factor for n
        cout << largest_prime[n] << endl;
    }

    return 0;
}
