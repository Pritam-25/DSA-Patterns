#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int index, int lastJump, vector<int>& stones) {
        // reached last stone
        if (index == stones.size() - 1) return true;

        // try:
        // k-1, k, k+1
        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            // invalid jump
            if (jump <= 0) continue;

            // next position frog wants to reach
            int nextPos = stones[index] + jump;

            // binary search
            // returns iterator to first element >= nextPos
            auto stoneIterator = lower_bound(stones.begin(), stones.end(), nextPos);

            // verify stone actually exists & position equal to nextPos
            if (stoneIterator != stones.end() && *stoneIterator == nextPos) {
                // convert iterator to index
                int nextIndex = stoneIterator - stones.begin();

                // recursive dfs
                if (dfs(nextIndex, jump, stones)) return true;
            }
        }

        return false;
    }

   public:
    bool canCross(vector<int>& stones) {
        return dfs(0, 0, stones);
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};

    bool ans = sol.canCross(stones);

    ans ? cout << "true" : cout << "false";
}