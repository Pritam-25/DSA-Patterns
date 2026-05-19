#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestCommonSubstring(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> previousRow(m + 1, 0);
        vector<int> currentRow(m + 1, 0);

        int maximumLength = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Characters match
                if (s1[i - 1] == s2[j - 1]) {
                    currentRow[j] = 1 + previousRow[j - 1];
                    maximumLength = max(maximumLength, currentRow[j]);
                }

                // Characters do not match
                else {
                    currentRow[j] = 0;
                }
            }

            previousRow = currentRow;
        }

        return maximumLength;
    }
};