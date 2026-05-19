# 🏋️‍♂️ Ninja Training — Complete DP Notes

> 🧩 **A classic Dynamic Programming problem that teaches:**
>
> - State definition
> - Overlapping subproblems
> - Memoization
> - Tabulation
> - Space optimization
> - State transition thinking

Problem references and DP concepts adapted from standard dynamic-programming tutorials and discussions. ([GeeksforGeeks][1])

## 📝 Problem Statement

A ninja has to train for `n` days.

Each day he can perform one of 3 tasks:

| Task | Meaning  |
| ---- | -------- |
| 0    | Running  |
| 1    | Fighting |
| 2    | Learning |

Each task gives some points.

**Constraint:**

```txt
Cannot perform same task on consecutive days.
```

**Goal:**

```txt
Maximize total points.
```

## 🔍 Example

```cpp
points = {
    {10, 40, 70},
    {20, 50, 80},
    {30, 60, 90}
};
```

Answer:

```txt
210
```

## 🛠️ Solutions

1. [🔄 Recursive Solution](#-recursive-solution)
2. [💾 Memoization](#-memoization)
3. [📊 Tabulation](#-tabulation)
4. [⚡ Space Optimization](#-space-optimization)

## ❓ Why Not Greedy?

### 💡 Greedy Thinking

Greedy means:

```txt id="9y5kho"
At every step,
choose the locally best option.
```

For this problem greedy would say:

```txt id="3h3wqe"
"Choose maximum points task for current day"
```

### 🚫 Why Greedy Fails

Because:

```txt id="4mjlwm"
best choice today
may block better choices tomorrow
```

Current decision affects future decisions.

That is the BIG reason greedy fails.

Greedy algorithms work only when a locally optimal choice always leads to a globally optimal solution, called the greedy-choice property. ([WSU Electrical Engineering][1])

### 🧪 Greedy Counter Example

```cpp id="j2jw0w"
points = {
    {100, 1, 1},
    {1000, 2, 2}
};
```

### 💡 Greedy Approach

#### Day 0

Choose maximum:

```txt id="9g9ye4"
100
```

Task:

```txt id="y8pklw"
0
```

#### Day 1

Cannot choose task 0 again.

Only:

```txt id="ajtx39"
2 or 2
```

Total:

```txt id="g55a2s"
100 + 2 = 102
```

### 🏆 Optimal Answer

Instead:

#### Day 0

Choose:

```txt id="68b9ks"
1
```

#### Day 1

Now task 0 allowed.

Choose:

```txt id="82hnyw"
1000
```

Total:

```txt id="3m7wz6"
1 + 1000 = 1001
```

### ⚠️ Huge Difference

| Approach | Answer |
| -------- | ------ |
| Greedy   | 102    |
| Optimal  | 1001   |

So greedy completely fails.

### 💡 Why DP Works

DP explores:

```txt id="8ob6eu"
ALL valid possibilities
```

and chooses the best overall answer.

Instead of committing early.

Dynamic programming is useful when problems have overlapping subproblems and optimal substructure, while greedy additionally requires the greedy-choice property. ([GeeksforGeeks][2])

## 🧐 Key Observation

At any day:

the future depends only on:

1. current day
2. previous task

So state becomes:

```txt
(day, last)
```

This is the MOST IMPORTANT insight.

## 🎯 State Definition

### Recursive State

```cpp
dfs(day, last)
```

Meaning:

```txt
Maximum points till this day
if previous task was "last"
```

### 📝 Example

```cpp
dfs(2, 1)
```

means:

```txt
On day 2,
task 1 is NOT allowed.
```

Allowed tasks:

```txt
0 and 2
```

## 🔄 Recursive Solution

### 💡 Recursive Thinking

For every day:

```txt
Try all possible tasks
```

If task is valid:

```txt
take current points
+
solve remaining subproblem
```

### 🧮 Recursive Formula

```txt
f(day,last) = max(points[day][task] + f(day-1, task))
```

where:

```txt
task != last
```

### [💻 Code](./01_recursion.cpp)

```cpp
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
```

#### ❔ Why `last = 3` ?

Tasks are:

```txt
0 1 2
```

So:

```txt
3 = no previous task
```

Used for initial state.

### ⏳ Time Complexity (Recursion)

At every day:

```txt
3 choices
```

Depth:

```txt
n
```

So:

```txt
O(3^N)
```

### 📦 Space Complexity (Recursion)

Recursive stack depth:

```txt
n
```

So:

```txt
O(N)
```

### ❌ Problem With Recursion

Same states are computed again and again.

Example:

```txt
f(1,0)
f(1,1)
f(1,2)
```

repeated multiple times.

This is called:

```txt
Overlapping Subproblems
```

## 💾 Memoization

### 💡 Idea

Store already computed states.

Before solving:

```cpp
if(dp[day][last] != -1)
```

return stored answer.

### 🗂️ DP Table

State:

```txt
(day,last)
```

So DP becomes:

```txt
2D DP
```

Size:

```cpp
dp[n][4]
```

Why 4?

Because:

```txt
last = 0,1,2,3
```

### [💻 Code](./02_memoization.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {

        // already solved
        if (dp[day][last] != -1) return dp[day][last];

        // base case
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
```

### ⏳ Time Complexity (Memoization)

#### Step 1 — Count States

State variables:

```txt
(day,last)
```

Possible values:

```txt
day  = n
last = 4
```

Total states:

```txt
n * 4
```

#### Step 2 — Work Per State

Inside every state:

```cpp
for(task=0; task<3; task++)
```

runs.

So work per state:

```txt
O(3)
```

#### Final Complexity

```txt
O(n * 4 * 3)
```

Simplify:

```txt
O(N)
```

because constants ignored.

### 📦 Space Complexity (Memoization)

#### DP Table

```txt
n * 4
```

So:

```txt
O(N)
```

#### Recursive Stack

Depth:

```txt
n
```

So:

```txt
O(N)
```

#### Total

```txt
O(N) + O(N)
=
O(N)
```

## 📊 Tabulation

### 💡 Core Idea

Convert:

```txt
Top Down → Bottom Up
```

Instead of recursion:

```txt
solve smaller states first
```

then build answer iteratively.

Tabulation fills states iteratively from smaller subproblems upward. ([GeeksforGeeks][1])

### 🧠 Most Important Intuition

Recursion state:

```cpp
dfs(day,last)
```

becomes table:

```cpp
dp[day][last]
```

### 🔄 Why 3 Loops?

Because recursion had:

#### State Variables

```txt
(day,last)
```

So:

```cpp
for(day)
for(last)
```

needed to traverse states.

#### Transition Choices

Recursion also had:

```cpp
for(task)
```

to try all possible tasks.

That becomes the 3rd loop.

### 🗂️ DP Meaning

```cpp
dp[day][last]
```

means:

```txt
Maximum points till this day
if previous task was last
```

### [💻 Code](./03_tabulation.cpp)

```cpp
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
                dp[day][last] = 0;

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
```

### ⏳ Time Complexity (Tabulation)

Three loops:

```cpp
for(day)   -> n
for(last)  -> 4
for(task)  -> 3
```

So:

```txt
O(n * 4 * 3)
```

Simplify:

```txt
O(N)
```

### 📦 Space Complexity (Tabulation)

DP table:

```txt
n * 4
```

So:

```txt
O(N)
```

No recursion stack.

## ⚡ Space Optimization

### 💡 Observation

Current row depends only on:

```txt
previous row
```

Meaning:

```cpp
dp[day]
```

depends only on:

```cpp
dp[day-1]
```

So entire table not needed.

### 🗂️ Replace Table With Arrays

Use:

```cpp
prev[4]
curr[4]
```

### [💻 Code](./04_space_optimization.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ninjaTraining(int n, vector<vector<int>>& points) {

        // prev array to store the maximum points for the previous day
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

        return prev[3];
    }
};
```

### ⏳ Time Complexity (Space Optimized)

Loops remain same:

```txt
O(n * 4 * 3)
```

Simplify:

```txt
O(N)
```

### 📦 Space Complexity (Space Optimized)

Only two arrays:

```txt
prev[4]
curr[4]
```

Total:

```txt
O(1)
```

Because fixed size.

## 📊 Complexity Analysis

| Approach        | Time Complexity     | Space Complexity |
| --------------- | ------------------- | ---------------- |
| Recursion       | `O(3^N)`            | `O(N)` stack     |
| Memoization     | `O(N*4*3)` → `O(N)` | `O(N)`           |
| Tabulation      | `O(N*4*3)` → `O(N)` | `O(N)`           |
| Space Optimized | `O(N*4*3)` → `O(N)` | `O(1)`           |

## 🎯 Interview Takeaways

This problem teaches:

```txt
State = Current Position + Previous Choice
```

Very common DP pattern.

## 🧩 Similar Problems

| Problem        | Similarity                 |
| -------------- | -------------------------- |
| Paint House    | Adjacent restriction       |
| Vacation DP    | Same pattern               |
| House Robber   | Previous choice dependency |
| Stock Cooldown | Previous state matters     |
| Grid Coloring  | Adjacent constraints       |
