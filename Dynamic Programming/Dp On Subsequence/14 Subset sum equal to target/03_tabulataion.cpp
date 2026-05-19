#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Sum 0 always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int index = 1; index <= n; index++) {
            for (int sum = 1; sum <= target; sum++) {

                bool take = false;
                // Include current element
                if (arr[index - 1] <= sum) {
                    take = dp[index - 1][sum - arr[index - 1]];
                }

                // Exclude current element
                bool notTake = dp[index - 1][sum];

                dp[index][sum] = take || notTake;
            }
        }

        return dp[n][target];
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;

    bool answer = sol.isSubsetSum(arr, target);
    answer ? cout << "true\n" : cout << "false\n";

    return 0;
}