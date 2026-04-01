# 🧠 STOCK PROBLEMS MASTER SHEET


# 🔥 Pattern 1: Single Transaction

## 👉 Best Time to Buy and Sell Stock


## 💡 Idea

```text
Buy once, sell once
Maximize profit
```


## 🧠 Core Logic

```text
minPrice → best buy so far
profit = sell - buy
```


## 🧾 Code

```cpp
int minPrice = INT_MAX, maxProfit = 0;

for (int price : prices) {
    minPrice = min(minPrice, price);
    maxProfit = max(maxProfit, price - minPrice);
}
```


## 🎯 Pattern

```text
Prefix Minimum
```


# 🔥 Pattern 2: Infinite Transactions

## 👉 Best Time to Buy and Sell Stock II


## 💡 Idea

```text
Buy and sell multiple times
Take every profit opportunity
```


## 🧠 Core Logic

```text
If next price is higher → take profit
```


## 🧾 Code

```cpp
int profit = 0;

for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1]) {
        profit += prices[i] - prices[i - 1];
    }
}
```


## 🎯 Pattern

```text
Greedy (take all increasing slopes)
```


# 🔥 Pattern 3: At Most 2 Transactions

## 👉 Best Time to Buy and Sell Stock III


## 💡 Idea

```text
Split into 2 parts
Left → max profit
Right → max profit
```


## 🧠 Core Logic

```text
leftProfit[i] → best till i
rightProfit[i] → best from i
```


## 🧾 Code (Important)

```cpp
int n = prices.size();
vector<int> left(n, 0), right(n, 0);

// left pass
int minPrice = prices[0];
for (int i = 1; i < n; i++) {
    minPrice = min(minPrice, prices[i]);
    left[i] = max(left[i-1], prices[i] - minPrice);
}

// right pass
int maxPrice = prices[n-1];
for (int i = n-2; i >= 0; i--) {
    maxPrice = max(maxPrice, prices[i]);
    right[i] = max(right[i+1], maxPrice - prices[i]);
}

// combine
int ans = 0;
for (int i = 0; i < n; i++) {
    ans = max(ans, left[i] + right[i]);
}
```


## 🎯 Pattern

```text
Prefix + Suffix DP
```


# 🔥 Pattern 4: At Most K Transactions

## 👉 Best Time to Buy and Sell Stock IV


## 💡 Idea

```text
Generalized DP
```


## 🧠 State

```text
dp[k][i] → max profit with k transactions till day i
```


## 🧾 Code (Optimized)

```cpp
vector<vector<int>> dp(k+1, vector<int>(n, 0));

for (int t = 1; t <= k; t++) {
    int maxDiff = -prices[0];

    for (int i = 1; i < n; i++) {
        dp[t][i] = max(dp[t][i-1], prices[i] + maxDiff);
        maxDiff = max(maxDiff, dp[t-1][i] - prices[i]);
    }
}
```


## 🎯 Pattern

```text
DP + Optimization
```


# 🔥 Pattern 5: With Cooldown

## 👉 Best Time to Buy and Sell Stock with Cooldown


## 💡 Idea

```text
After selling → 1 day cooldown
```


## 🧠 States

```text
buy, sell, cooldown
```


## 🧾 Code

```cpp
int buy = -prices[0], sell = 0, cooldown = 0;

for (int i = 1; i < prices.size(); i++) {
    int prevBuy = buy;

    buy = max(buy, cooldown - prices[i]);
    cooldown = sell;
    sell = max(sell, prevBuy + prices[i]);
}
```


## 🎯 Pattern

```text
State Machine DP
```


# 🔥 Pattern 6: With Transaction Fee

## 👉 Best Time to Buy and Sell Stock with Transaction Fee


## 💡 Idea

```text
Each sell has a fee
```


## 🧠 Core Logic

```text
Subtract fee while selling
```


## 🧾 Code

```cpp
int buy = -prices[0], sell = 0;

for (int i = 1; i < prices.size(); i++) {
    buy = max(buy, sell - prices[i]);
    sell = max(sell, buy + prices[i] - fee);
}
```


## 🎯 Pattern

```text
DP with cost adjustment
```


# 🔥 MASTER PATTERN SUMMARY

| Problem Type    | Pattern Used     |
| --------------- | ---------------- |
| 1 Transaction   | Prefix Min       |
| Infinite        | Greedy           |
| 2 Transactions  | Prefix + Suffix  |
| K Transactions  | DP               |
| Cooldown        | State Machine DP |
| Transaction Fee | DP with cost     |


# 🧠 HOW TO IDENTIFY IN INTERVIEW

```text
1. Only one buy/sell → Prefix min
2. Unlimited → Greedy
3. Limited K → DP
4. Restrictions → State machine
```


