#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSum = INT_MIN;
    void dfs(int i, int sum, vector<int>& ds, vector<int>& arr) {
        maxSum = max(sum, maxSum);

        if (i == arr.size()) {
            return;
        }

        ds.push_back(arr[i]);
        if (i + 2 <= arr.size()) dfs(i + 2, sum + arr[i], ds, arr);

        ds.pop_back();
        dfs(i + 1, sum, ds, arr);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int sum = 0;
        vector<int> ds;

        dfs(0, sum, ds, arr);

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 4, 9};
    cout << sol.findMaxSum(arr) << endl;  // Output: 13 (3 + 10)
    return 0;
}