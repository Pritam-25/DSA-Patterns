#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        // prev array to store the maximum points for the previous day, where prev[0], prev[1], and
        // prev[2] represent the maximum points for tasks 0, 1, and 2 respectively, and prev[3]
        // represents the maximum points when no task was done on the previous day
        vector<int> prev(4, 0);

        // BASE CASE
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; day++) {
            vector<int> curr(4, 0);

            for (int last = 0; last < 4; last++) {
                // try all tasks for the current day, excluding the last task
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        curr[last] = max(curr[last], points[day][task] + prev[task]);
                    }
                }
            }

            // update prev to curr for the next iteration
            prev = curr;
        }

        // the answer will be in prev[3] because it represents the maximum points when no task was
        // done on the last day, which means we can choose any task on the last day
        return prev[3];
    }
};