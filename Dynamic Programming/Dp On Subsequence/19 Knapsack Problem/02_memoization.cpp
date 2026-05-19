#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int index, int capacity, vector<int>& weight, vector<int>& value,
            vector<vector<int>>& dp) {
        // No items left
        if (index == weight.size()) return 0;

        if (dp[index][capacity] != -1) return dp[index][capacity];

        int take = 0;

        // Take current item if possible
        if (weight[index] <= capacity) {
            take = value[index] + dfs(index + 1, capacity - weight[index], weight, value, dp);
        }

        // Skip current item
        int notTake = dfs(index + 1, capacity, weight, value, dp);

        return dp[index][capacity] = max(take, notTake);
    }

    int knapsack(vector<int>& weight, vector<int>& value, int capacity) {
        vector<vector<int>> dp(weight.size(), vector<int>(capacity + 1, -1));
        return dfs(0, capacity, weight, value, dp);
    }
};

int main() {
    Solution sol;

    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 15, 40};
    int capacity = 6;

    int answer = sol.knapsack(weight, value, capacity);
    cout << answer << endl;
    return 0;
}