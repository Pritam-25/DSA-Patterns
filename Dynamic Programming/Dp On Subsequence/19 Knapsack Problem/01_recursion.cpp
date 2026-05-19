#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int index, int capacity, vector<int>& weight, vector<int>& value) {
        // No items left
        if (index == weight.size()) return 0;

        int take = 0;

        // Take current item if possible
        if (weight[index] <= capacity) {
            take = value[index] + dfs(index + 1, capacity - weight[index], weight, value);
        }

        // Skip current item
        int notTake = dfs(index + 1, capacity, weight, value);

        return max(take, notTake);
    }

    int knapsack(vector<int>& weight, vector<int>& value, int capacity) {
        return dfs(0, capacity, weight, value);
    }
};

int main() {
    Solution sol;

    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 15, 40};
    int capacity = 6;

    int answer = sol.knapsack(weight, value, capacity);
    cout << answer << endl;
    return 0;
}