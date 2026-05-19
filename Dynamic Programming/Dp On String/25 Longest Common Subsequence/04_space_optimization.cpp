#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> nextRow(m + 1, 0);
        vector<int> currentRow(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Characters match
                if (text1[i] == text2[j]) {
                    currentRow[j] = 1 + nextRow[j + 1];
                }

                // Characters do not match
                else {
                    currentRow[j] = max(nextRow[j], currentRow[j + 1]);
                }
            }

            nextRow = currentRow;
        }

        return nextRow[0];
    }
};