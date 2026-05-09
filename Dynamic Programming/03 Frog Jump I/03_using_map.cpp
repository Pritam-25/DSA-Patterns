#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool dfs(int index, int lastJump, vector<int>& stones, unordered_map<int, int> pos) {
        if (index == stones.size() - 1) return true;

        for (int jump = lastJump - 1; jump <= lastJump + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = stones[index] + jump;

            if (pos.count(nextPos)) {
                int nextIndex = pos[nextPos];

                if (dfs(nextIndex, jump, stones, pos)) return true;
            }
        }

        return false;
    }

   public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> pos;

        for (int i = 0; i < stones.size(); i++) {
            pos[stones[i]] = i;
        }

        return dfs(0, 0, stones, pos);
    }
};
int main() {
    Solution sol;

    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};  // true

    bool ans = sol.canCross(stones);
    ans ? cout << "true" << endl : cout << "false";
    return 0;
}
