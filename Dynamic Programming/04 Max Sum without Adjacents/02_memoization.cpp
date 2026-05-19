#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int i, vector<int>& arr, vector<int>& dp) {
        // base case
        if (i >= arr.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int take = arr[i] + dfs(i + 2, arr, dp);
        int skip = dfs(i + 1, arr, dp);

        return dp[i] = max(take, skip);
    }

    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size(), -1);
        return dfs(0, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 9};
    cout << sol.findMaxSum(arr) << endl;  // Output: 13 (3 + 10)
    return 0;
}