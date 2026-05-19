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
    int minInsertionsOrDeletions(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lcs = dfs(0, 0, s1, s2, dp);

        // Minimum insertions or deletions required (m+n - 2*lcs)
        int insertions = n - lcs;
        int deletions = m - lcs;

        return insertions + deletions;
    }
};

int main() {
    Solution sol;

    string s1 = "abcde";
    string s2 = "abc";

    int ans = sol.minInsertionsOrDeletions(s1, s2);
    cout << ans << endl;

    return 0;
}