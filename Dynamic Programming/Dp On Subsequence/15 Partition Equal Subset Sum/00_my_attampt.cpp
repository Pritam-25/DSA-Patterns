#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int index, int target, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == (double)sum / 2) return true;

        if (index == nums.size()) return false;

        if (dp[index][target] != -1) return dp[index][target];

        if (dfs(index + 1, target + nums[index], sum, nums, dp)) return true;

        return dp[index][target] = dfs(index + 1, target, sum, nums, dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // odd sum impossible
        if (sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return dfs(0, 0, sum, nums, dp);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 5, 11, 5};

    bool answer = sol.canPartition(nums);
    answer ? cout << "true\n" : cout << "false\n";

    return 0;
}