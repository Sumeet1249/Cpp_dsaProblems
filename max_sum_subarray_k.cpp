#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Function to calculate the maximum sum of a subarray of size k
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();

    if (n < k) {
        cerr << "Window size k is larger than array size." << endl;
        return -1;
    }

    // Step 1: Compute sum of first window of size k
    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: Slide the window, one element at a time
    for (int i = k; i < n; ++i) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    // Example input
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    // Function call
    int result = maxSumSubarray(arr, k);

    // Output the result
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}
