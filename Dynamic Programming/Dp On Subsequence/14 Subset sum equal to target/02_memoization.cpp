#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index >= arr.size() || target < 0) return false;

        if (dp[index][target] != -1) return dp[index][target];

        // Include the current element
        if (dfs(index + 1, target - arr[index], arr, dp)) {
            return true;
        }

        // Exclude the current element
        return dp[index][target] = dfs(index + 1, target, arr, dp);
    }

    bool countSubsets(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return dfs(0, target, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;

    bool answer = sol.countSubsets(arr, target);
    cout << answer << endl;
    return 0;
}