# <img src="https://assets.leetcode.com/static_assets/public/icons/favicon-32x32.png" width="28"> [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

## 🤔 Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the i-th day.

- You may buy one stock and sell one stock.
- You must buy before you sell.

Return the maximum profit you can achieve. If you cannot achieve any profit, return `0`.

### Example

Input: `prices = [7,1,5,3,6,4]`
Output: `5` (Buy at 1, sell at 6)

## 🐢 Brute Force Approach

### 💡 Idea

Try every possible pair:

- Buy on day `i`
- Sell on day `j`
- where `j > i`

Calculate:

```text id="azl6jq"
profit = prices[j] - prices[i]
```

Keep the maximum profit.

### 🗒️ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;

        for(int buy = 0; buy < n; buy++) {

            for(int sell = buy + 1; sell < n; sell++) {

                int currentProfit = prices[sell] - prices[buy];

                maxProfit = max(maxProfit, currentProfit);
            }
        }

        return maxProfit;
    }
};
```

### ❌ Why Brute Force is Bad?

We check all pairs:

```text id="6b8npd"
(n × n)
```

### ⏱️ Complexity Analysis

| Metric           | Complexity |
| ---------------- | ---------: |
| Time complexity  |     O(N^2) |
| Space complexity |       O(1) |

## 🚀 Optimal Greedy Approach

### 🔥 Main Observation

Instead of checking all previous buy days repeatedly:

We only need:

```text id="c44swu"
minimum stock price seen so far
```

Because:

```text id="mg87ks"
Best profit today =
today's price - minimum previous price
```

### 🧠 Core Idea

While traversing the array:

- maintain `minPrice`
- calculate profit if sold today
- update `maxProfit`

### 🗒️ Code

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            // Sell today
            if(prices[i] > minPrice) {
                int currentProfit = prices[i] - minPrice;
                maxProfit = max(maxProfit, currentProfit);
            }

            // Update minimum buying price
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
```

### ⏱️ Complexity Analysis

| Metric           | Complexity |
| ---------------- | ---------: |
| Time complexity  |       O(N) |
| Space complexity |       O(1) |

## 🎯 Why Greedy Works?

At every index:

```text id="evu7jk"
We already know the cheapest buying price
before today.
```

So we instantly compute:

```text id="u5r54f"
best profit if sold today
```

This removes the inner loop completely.

The standard optimal approach is maintaining the minimum prefix value while scanning once through the array.

## ⚠️ Common Mistake

### ❌ Wrong Order

```cpp
minPrice = min(minPrice, prices[i]);
profit = prices[i] - minPrice;
```

Why risky?

Because:
you may accidentally consider:

```text id="7x8c2n"
buy and sell on same day
```

### ✅ Correct Order

1. Calculate profit first
2. Then update minimum price

## ⏱️ Complexity Comparison

| Approach       | Time  | Space |
| -------------- | ----- | ----- |
| Brute Force    | O(N²) | O(1)  |
| Optimal Greedy | O(N)  | O(1)  |

## 🎥 Video Tutorial

[![Watch the video](https://img.youtube.com/vi/excAOvwF_Wk/maxresdefault.jpg)](https://youtu.be/excAOvwF_Wk?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)
