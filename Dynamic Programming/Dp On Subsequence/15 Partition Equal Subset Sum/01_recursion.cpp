#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        // target formed
        if (target == 0) return true;

        // no elements left
        if (index == nums.size()) return false;

        // already solved
        if (dp[index][target] != -1) return dp[index][target];

        // take
        if (nums[index] <= target) {
            if (dfs(index + 1, target - nums[index], nums, dp)) {
                return dp[index][target] = true;
            }
        }

        // not take
        return dp[index][target] = dfs(index + 1, target, nums, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) sum += num;

        // odd sum impossible
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return dfs(0, target, nums, dp);
    }
};