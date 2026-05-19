#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(int index1, int index2, string& s1, string& s2) {
        // One string exhausted (base case)
        if (index1 == s1.size() || index2 == s2.size()) return 0;

        // Characters match
        if (s1[index1] == s2[index2]) {
            return 1 + dfs(index1 + 1, index2 + 1, s1, s2);
        }

        // Skip from either string
        return max(dfs(index1 + 1, index2, s1, s2), dfs(index1, index2 + 1, s1, s2));
    }

   public:
    int longestCommonSubsequence(string s1, string s2) {
        return dfs(0, 0, s1, s2);
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