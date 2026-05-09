#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int index, int lastJump, vector<int>& stones) {
        // reached last stone
        if (index == stones.size() - 1) return true;

        // // try all 3 possible jumps (k-1, k, k+1)
        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = stones[index] + jump;

            // search entire remaining array (find if this stone exists)
            for (int i = index + 1; i < stones.size(); i++) {
                //   optimization (as array is sorted)
                if (stones[i] > nextPos) break;

                if (stones[i] == nextPos) {
                    if (dfs(i, jump, stones)) return true;
                }
            }
        }

        return false;
    }

   public:
    bool canCross(vector<int>& stones) {
        return dfs(0, 0, stones);  // start at index 0, last jump = 0
    }
};

int main() {
    Solution sol;

    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};  // false
    //   {0, 1, 3, 5, 6, 8, 12, 17}       // true
    bool ans = sol.canCross(stones);
    ans ? cout << "true" << endl : cout << "false";
    return 0;
}
