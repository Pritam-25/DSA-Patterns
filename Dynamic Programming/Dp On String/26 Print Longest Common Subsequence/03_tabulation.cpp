#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Characters match
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                // Characters do not match
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtracking
        int i = n;
        int j = m;

        string lcs = "";

        while (i > 0 && j > 0) {
            // Characters match
            if (s1[i - 1] == s2[j - 1]) {
                lcs += s1[i - 1];
                i--;
                j--;
            }

            // Move upward
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }

            // Move left
            else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        return lcs;
    }
};

int main() {
    Solution sol;

    string s1 = "brute";
    string s2 = "groot";

    string ans = sol.longestCommonSubsequence(s1, s2);
    cout << ans << endl;

    return 0;
}