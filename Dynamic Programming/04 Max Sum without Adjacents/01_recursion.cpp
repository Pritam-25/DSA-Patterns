#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int i, vector<int>& arr) {
        // base case
        if (i >= arr.size()) return 0;

        int take = arr[i] + dfs(i + 2, arr);
        int skip = dfs(i + 1, arr);

        return max(take, skip);
    }

    int findMaxSum(vector<int>& arr) {
        return dfs(0, arr);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 9};
    cout << sol.findMaxSum(arr) << endl;  // Output: 13 (3 + 10)
    return 0;
}