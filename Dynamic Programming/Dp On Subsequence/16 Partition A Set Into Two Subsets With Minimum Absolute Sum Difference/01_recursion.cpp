#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void dfs(int index, int currentSum, vector<int>& currentSubset, vector<int>& nums, int totalSum,
             int& minDifference) {

        if (currentSubset.size() == nums.size() / 2) {
            int otherSubsetSum = totalSum - currentSum;

            minDifference = min(minDifference, abs(currentSum - otherSubsetSum));

            return;
        }

        if (index == nums.size()) return;

        // Take
        currentSubset.push_back(nums[index]);

        dfs(index + 1, currentSum + nums[index], currentSubset, nums, totalSum, minDifference);

        currentSubset.pop_back();

        // Not take
        dfs(index + 1, currentSum, currentSubset, nums, totalSum, minDifference);
    }

    int minDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int value : nums) {
            totalSum += value;
        }

        vector<int> currentSubset;

        int minDifference = INT_MAX;

        dfs(0, 0, currentSubset, nums, totalSum, minDifference);

        return minDifference;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 6, 11, 5};
    cout << sol.minDifference(nums) << endl;
    return 0;
}