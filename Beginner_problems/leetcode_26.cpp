/*
    Problem Added by Pragyansh Saxena - B23328
*/

/*
PROBLEM STATEMENT :---

    https://leetcode.com/problems/remove-duplicates-from-sorted-array/

    Tags - Implementation

    Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that 
    each unique element appears only once. The relative order of the elements should be kept the same. 
    Then return the number of unique elements in `nums`.

    Custom Judge:

    The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }

    If all assertions pass, then your solution will be accepted.

    Input: -- 
        nums: A sorted array of integers.
    Output: -- 
        The number of unique elements `k`, with the first `k` elements being unique in the array.
*/

/* 
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.

Constraints:
1 <= nums.length <= 3 * 10^4
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // We need at least one unique element, so start k at 1.
        int k = 1;
        
        // Loop through the array starting from the second element.
        for(int i = 1; i < nums.size(); i++) {
            // If the current element is not equal to the previous one, it's unique.
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i]; // Move the unique element to the next position.
                ++k;  // Increment the count of unique elements.
            }
        }
        
        return k; // Return the count of unique elements.
    }
};

int main() {
    Solution sol;
    int n;  // Length of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];  // Input the sorted array
    }

    // Call the removeDuplicates function and get the count of unique elements.
    int k = sol.removeDuplicates(nums);

    // Output the number of unique elements.
    cout << "Number of unique elements: " << k << endl;

    // Output the array with unique elements.
    cout << "The modified array with unique elements: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}