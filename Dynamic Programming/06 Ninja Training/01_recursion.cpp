#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int day, int last, vector<vector<int>>& points) {
        // base case
        if (day == 0) {
            int maxi = 0;

            // find the maximum point for the first day, excluding the last task
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxPoint = 0;

        // try all tasks for the current day, excluding the last task
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = points[day][task] + dfs(day - 1, task, points);

                maxPoint = max(maxPoint, point);
            }
        }

        return maxPoint;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {
        // start from the last day and try all tasks, excluding the last task (3 means no task was
        // done on the previous day)
        return dfs(n - 1, 3, points);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    int n = points.size();

    int maxPoint = solution.ninjaTraining(n, points);
    cout << maxPoint << endl;
    return 0;
}