#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(int index1, int index2, string& s1, string& s2, vector<vector<int>>& dp) {
        // One string exhausted (base case)
        if (index1 == s1.size() || index2 == s2.size()) return 0;

        // Already solved
        if (dp[index1][index2] != -1) return dp[index1][index2];

        // Characters match
        if (s1[index1] == s2[index2]) {
            return dp[index1][index2] = 1 + dfs(index1 + 1, index2 + 1, s1, s2, dp);
        }

        // Skip from either string
        return dp[index1][index2] =
                   max(dfs(index1 + 1, index2, s1, s2, dp), dfs(index1, index2 + 1, s1, s2, dp));
    }

   public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = dfs(0, 0, s1, s2, dp);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "abc";
    string s2 = "adc";

    int ans = sol.longestCommonSubsequence(s1, s2);
    cout << ans << endl;

    return 0;
}