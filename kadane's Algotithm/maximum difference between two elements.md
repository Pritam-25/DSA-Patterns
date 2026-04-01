# [🧠 Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

# 🤔 Problem

Given:

```text
Array of integers
```

👉 Find:

```text
Maximum value of nums[j] - nums[i]
such that:
i < j AND nums[j] > nums[i]
```


# 🐢 Brute Force Approach (Check All Pairs)

## 💡 Idea

👉 Try all pairs `(i, j)`
👉 Ensure `i < j`
👉 Check valid condition and track max difference


## 🧾 Code

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    maxDiff = max(maxDiff, nums[j] - nums[i]);
                }
            }
        }

        return maxDiff;
    }
};
```


## ⏱️ Complexity

```text
Time: O(n²)
Space: O(1)
```


## ❗ Drawback

```text
Checks unnecessary pairs → inefficient for large n
```


# ⚡ Better Understanding (Pattern Insight)

From brute force:

```text
For every j → we need smallest i before it
```

👉 This leads to optimization


# 🚀 Optimal Approach (Prefix Minimum)

## 💡 Idea

👉 Track minimum element so far
👉 At each index, compute best possible difference


## 🧠 Core Logic

```text
minValue → smallest value before current index
maxDiff → best answer so far
```


## 🧾 Code

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minValue) {
                maxDiff = max(maxDiff, nums[i] - minValue);
            }
            minValue = min(minValue, nums[i]);
        }

        return maxDiff;
    }
};
```


## ⏱️ Complexity

```text
Time: O(n)
Space: O(1)
```

## ⚠️ Important Edge Case

```text
No valid pair exists
```

Example:

```text
[9, 8, 7]
```

👉 Output:

```text
-1
```


# 🔥 Pattern Recognition

This is:

```text
Prefix Minimum + Greedy
```

👉 Same pattern as:

* Stock Buy and Sell (Best Time to Buy/Sell)
* Kadane-style optimization


# ❌ Common Mistakes

```text
1. Using two pointers (l, r) ❌
2. Not maintaining order (i < j) ❌
```


# 🧠 Key Trick

```text
For every element:
→ treat it as "sell"
→ use smallest previous as "buy"
```

# 🎯 Final Takeaway

```text
If problem says:
→ maximize difference
→ with condition i < j

Think:
👉 "Keep minimum so far"
👉 "Check difference at each step"
```

