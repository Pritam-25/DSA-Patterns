#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (index >= arr.size() || target < 0) return 0;

        if (dp[index][target] != -1) return dp[index][target];

        // Include the current element
        int take = dfs(index + 1, target - arr[index], arr, dp);
        
        // Exclude the current element
        int notTake = dfs(index + 1, target, arr, dp);

        return dp[index][target] = take + notTake;
    }

    int countSubsets(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return dfs(0, target, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;

    int answer = sol.countSubsets(arr, target);
    cout << answer << endl;
    return 0;
}