#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int index, int lastJump, vector<int>& stones, unordered_map<int, int>& pos,
             map<pair<int, int>, bool>& dp) {
        // reached last stone
        if (index == stones.size() - 1) return true;

        // already solved
        if (dp.count({index, lastJump})) return dp[{index, lastJump}];

        // try all 3 possible jumps (k-1, k, k+1)
        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            // jump must be positive
            if (jump <= 0) continue;

            int nextPos = stones[index] + jump;

            /**
             * Check if nextPos exists in the map
             * If it does, get the corresponding index and continue DFS
             */
            if (pos.count(nextPos)) {
                int nextIndex = pos[nextPos];
                // if any of the jumps lead to a solution, return true
                if (dfs(nextIndex, jump, stones, pos, dp)) return dp[{index, lastJump}] = true;
            }
        }

        // update dp with false if no jump leads to a solution
        return dp[{index, lastJump}] = false;
    }

   public:
    bool canCross(vector<int>& stones) {
        // map stone position to index for O(1) lookups
        unordered_map<int, int> pos;

        // memoization table: (index, lastJump) -> canReachEnd
        map<pair<int, int>, bool> dp;

        for (int i = 0; i < stones.size(); i++) {
            pos[stones[i]] = i;
        }

        return dfs(0, 0, stones, pos, dp);
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 2, 3, 4, 12};  // false
    //   {0, 1, 3, 5, 6, 8, 12, 17}       // true
    //   {0, 1, 2, 3, 4, 8, 9, 11};       // false
    bool ans = sol.canCross(stones);
    ans ? cout << "true" << endl : cout << "false";
    return 0;
}