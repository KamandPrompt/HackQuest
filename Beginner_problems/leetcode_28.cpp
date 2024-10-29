/*
    Problem Added by Pragyansh Saxena - B23328
*/

/*
PROBLEM STATEMENT :---

    https://leetcode.com/problems/merge-sorted-array/

    Tags - Array, Two Pointers

    You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, 
    representing the number of elements in `nums1` and `nums2` respectively.

    Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function but instead be stored inside the array `nums1`. 
    To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, 
    and the last `n` elements are set to 0 and should be ignored. `nums2` has a length of `n`.
    
*/

/* 
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
*/

/*
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers for the end of nums1 and nums2, and to insert position in nums1
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        // Compare elements from end of nums1 and nums2, placing largest at the end of nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // If nums2 has remaining elements, copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;
    int m, n;  // Sizes of nums1 and nums2
    cout << "Enter the number of elements in nums1: ";
    cin >> m;
    cout << "Enter the number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n, 0), nums2(n);
    cout << "Enter the elements of nums1 (sorted and with extra space for merging): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    cout << "Enter the elements of nums2 (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    // Call the merge function
    sol.merge(nums1, m, nums2, n);

    // Output the merged sorted array in nums1
    cout << "Merged array: ";
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
