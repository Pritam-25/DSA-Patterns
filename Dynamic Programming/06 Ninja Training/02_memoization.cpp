#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if (dp[day][last] != -1) return dp[day][last];

        if (day == 0) {
            int maxi = 0;

            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return dp[day][last] = maxi;
        }

        int maxPoint = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = points[day][task] + dfs(day - 1, task, points, dp);

                maxPoint = max(maxPoint, point);
            }
        }

        return dp[day][last] = maxPoint;
    }
    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return dfs(n - 1, 3, points, dp);
    }
};

int main() {
    Solution solution;
    // vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    vector<vector<int>> points = {{10, 20, 50}, {30, 10, 10}, {50, 30, 90}, {40, 20, 60}};

    int n = points.size();

    int maxPoint = solution.ninjaTraining(n, points);
    cout << maxPoint << endl;
    return 0;
}