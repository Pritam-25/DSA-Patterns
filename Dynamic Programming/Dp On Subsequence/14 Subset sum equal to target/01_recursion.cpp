#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool dfs(int index, int target, vector<int>& arr) {
        if (target == 0) return true;
        if (index >= arr.size() || target < 0) return false;

        // Include the current element
        if (dfs(index + 1, target - arr[index], arr)) {
            return true;
        }

        // Exclude the current element
        return dfs(index + 1, target, arr);
    }

    bool countSubsets(vector<int>& arr, int target) {
        return dfs(0, target, arr);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;

    bool answer = sol.countSubsets(arr, target);
    answer ? cout << "true\n" : cout << "false\n";
    return 0;
}