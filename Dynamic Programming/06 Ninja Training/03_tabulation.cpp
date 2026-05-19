#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        // dp table to store the maximum points for each day
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // BASE CASE
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        // BUILD TABLE
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                // dp[day][last] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = points[day][task] + dp[day - 1][task];

                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }

        return dp[n - 1][3];
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