#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int dfs(int day, int last, vector<vector<int>>& points) {
        // BASE CASE
        if (day == 0) {
            int maxi = 0;

            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, points[0][task]);
                }
            }

            return maxi;
        }

        int maxPoint = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = points[day][task] + dfs(day - 1, task, points);

                maxPoint = max(maxPoint, point);
            }
        }

        return maxPoint;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {
        return dfs(n - 1, 3, points);
    }
};