#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxSum(vector<int>& arr) {
        int next1 = 0;  // [i+1]
        int next2 = 0;  // [i+2]

        // fill from back
        for (int i = arr.size() - 1; i >= 0; i--) {
            int take = arr[i] + next2;
            int skip = next1;

            int curr = max(take, skip);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 1, 4, 9};

    cout << sol.findMaxSum(arr);

    return 0;
}