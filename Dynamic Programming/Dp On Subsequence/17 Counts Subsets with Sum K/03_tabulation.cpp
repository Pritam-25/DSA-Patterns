#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countSubsets(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int index = 1; index <= n; index++) {
            for (int sum = 1; sum <= target; sum++) {
                int take = 0;

                if (arr[index - 1] <= sum) {
                    take = dp[index - 1][sum - arr[index - 1]];
                }

                int notTake = dp[index - 1][sum];

                dp[index][sum] = take + notTake;
            }
        }

        return dp[n][target];
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