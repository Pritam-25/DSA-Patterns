#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;

        // initialize
        for (int stone : stones) {
            dp[stone] = {};
        }

        dp[0].insert(0);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {
                    if (nextJump <= 0) continue;

                    int nextStone = stone + nextJump;

                    if (dp.count(nextStone)) {
                        dp[nextStone].insert(nextJump);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};

int main() {
    Solution sol;

    vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << sol.canCross(stones1) << endl;  // Output: true

    vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << sol.canCross(stones2) << endl;  // Output: false

    return 0;
}