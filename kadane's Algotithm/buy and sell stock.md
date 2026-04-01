# [🧠 Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

# 🤔 Problem

Given:

```text id="e1m2a1"
Array prices[] where prices[i] = price of stock on day i
```

👉 Find:

```text id="bqv4mv"
Maximum profit by buying once and selling once
(Buy before you sell)
```


# 🐢 Brute Force Approach (Check All Pairs)

## 💡 Idea

👉 Try all `(i, j)` pairs
👉 Ensure `i < j`
👉 Maximize `prices[j] - prices[i]`


## 🧾 Code

```cpp id="n0p4r3"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxProfit = max(maxProfit, prices[j] - prices[i]);
            }
        }

        return maxProfit;
    }
};
```


## ⏱️ Complexity

```text id="d4z8ya"
Time: O(n²)
Space: O(1)
```


# ⚡ Better Understanding (Pattern Insight)

From brute force:

```text id="g6v0q2"
For every day j → choose minimum price before it
```

👉 Leads to optimal solution


# 🚀 Optimal Approach (Prefix Minimum)

## 💡 Idea

👉 Track minimum price so far
👉 At each day, compute profit if sold today


## 🧠 Core Logic

```text id="w4tx8k"
minPrice → best day to buy so far
profit = current price - minPrice
maxProfit → best profit so far
```


## 🧾 Code (Your Code — Correct ✅)

```cpp id="p3k8qt"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, prices[i]);

            int currentProfit = prices[i] - minPrice;

            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};
```


## ⏱️ Complexity

```text id="3j1hsm"
Time: O(n)
Space: O(1)
```


## 🖼️ Visualization (Intuition)

```text id="7l5yfh"
prices = [7, 1, 5, 3, 6, 4]

min = 7
→ 1 → min = 1
→ 5 → profit = 5 - 1 = 4 ✅
→ 3 → profit = 3 - 1 = 2
→ 6 → profit = 6 - 1 = 5 ✅ (best)
→ 4 → profit = 4 - 1 = 3

Answer = 5
```


## ⚠️ Important Edge Case

```text id="4h0jfx"
Prices always decreasing
```

Example:

```text id="6g3k2v"
[9, 8, 7, 6]
```

👉 Output:

```text id="v1t7om"
0 (no profit possible)
```


# 🔥 Pattern Recognition

This is:

```text id="lq8z2d"
Prefix Minimum + Greedy
```

👉 Same as:

* Maximum Difference (LeetCode 2016)
* Kadane-style thinking


