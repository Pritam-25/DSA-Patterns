#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // filling the dp table (LCS lengths)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // build the shortest common supersequence by backtracking
        string ans = "";
        int i = n;
        int j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            } else {
                ans += s2[j - 1];
                j--;
            }
        }

        // append remaining characters
        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s1 = "brute";
    string s2 = "groot";

    string ans = sol.shortestCommonSupersequence(s1, s2);
    cout << ans << endl;
    cout << ans.length() << endl;
    return 0;
}