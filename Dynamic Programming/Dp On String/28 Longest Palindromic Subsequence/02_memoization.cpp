#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(string& s1, string& s2, int index1, int index2, vector<vector<int>>& dp) {
        // base case
        if (index1 == s1.size() || index2 == s2.size()) return 0;

        if (dp[index1][index2] != -1) return dp[index1][index2];

        // string match
        if (s1[index1] == s2[index2]) {
            return dp[index1][index2] = 1 + dfs(s1, s2, index1 + 1, index2 + 1, dp);
        }

        return dp[index1][index2] =
                   max(dfs(s1, s2, index1 + 1, index2, dp), dfs(s1, s2, index1, index2 + 1, dp));
    }

   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        string s2 = s;  // copy original string
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return dfs(s, s2, 0, 0, dp);
    }
};

int main() {
    Solution sol;

    string s = "bbbab";
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}