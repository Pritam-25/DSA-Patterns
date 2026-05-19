#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();

        // extra 2 size to safely access dp[i+2]
        vector<int> dp(n + 2, 0);

        // fill from back
        for (int i = n - 1; i >= 0; i--) {
            int take = arr[i] + dp[i + 2];
            int skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 1, 4, 9};

    cout << sol.findMaxSum(arr);

    return 0;
}