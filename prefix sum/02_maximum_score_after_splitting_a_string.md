# [🧠 Maximum Score After Splitting a String (LeetCode 1422)](https://leetcode.com/problems/maximum-score-after-splitting-a-string/)

## 🤔 Problem

Given a binary string `s`, split it into two **non-empty** parts such that:

- Left part → count of `'0'`
- Right part → count of `'1'`

👉 Maximize:

```
score = zeros(left) + ones(right)
```

## 💡 Key Idea

- Try all possible split points `i`
- Left = `[0 → i]`
- Right = `[i+1 → n-1]`
- Track:
  - zeros in left
  - ones in right

## 🐢 Brute Force Approach

### Steps

1. Try every split `i` from `0 → n-2`
2. Count:
   - zeros in left
   - ones in right

3. Take max

### 🧾 Code

```cpp
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int maxScore = 0;

        for (int i = 0; i < n - 1; i++) { // exclude last index (important)
            int zero = 0, one = 0;

            // sum of zeros in the first part
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') zero++;
            }

            // sum of ones in the second part
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') one++;
            }

            maxScore = max(maxScore, zero + one);
        }

        return maxScore;
    }
};
```

### Complexity

```
⏱️ Time: O(n²)
📦 Space: O(1)
```

## 🚚 Better Approach (Prefix Count using Map)

### Steps

1. Store:
   - `zeros[i]` → zeros from `0 → i`
   - `ones[i]` → ones from `i → n-1`

2. For each split:

   ```
   score = zeros[i] + ones[i+1]
   ```

### 🧾 Code

```cpp
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        map<int, int> zeros, ones;

        int zero = 0, one = 0;

        // calculate zeros count and occurence from start
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zero++;
            zeros[i] = zero;
        }

        // calculate ones count and occurence from end
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '1') one++;
            ones[i] = one;
        }

        int maxScore = 0;

        for (int i = 0; i < n - 1; i++) {
            maxScore = max(maxScore, zeros[i] + ones[i + 1]);
            /*
            ones[i+1]   because ones[0] ❌ doesn’t exist → default = 0
            left = [0 → i]
            right = [i+1 → n-1]
            */
        }

        return maxScore;
    }
};
```

### Complexity

```
⏱️ Time: O(n)
📦 Space: O(n)
```

## 🚀 Optimal Approach (Prefix Sum)

### Steps

1. Count total number of `'1'`
2. Traverse string:
   - maintain:
     - `zero` (left zeros)
     - `one` (left ones)

3. Compute:

```
score = zero + (totalOne - one)
```

### 🧾 Code

```cpp
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalOne = 0;

        // first calculate total number of ones
        for (char ch : s) {
            if (ch == '1') totalOne++;
        }

        int zero = 0, one = 0;
        int maxScore = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zero++;
            else one++;

            maxScore = max(maxScore, zero + totalOne - one);
        }

        return maxScore;
    }
};
```

### Complexity

```
⏱️ Time: O(n)
📦 Space: O(1)
```

## 🔥 Best Approach (One Pass Optimization)

### Steps

1. Convert:

```
zeros(left) + ones(right)
```

👉 into:

```
(zeros - ones) + totalOnes
```

2. Traverse once:
   - track `zeros` and `ones`
   - update `max(zeros - ones)`

3. Add total ones at end

### 🧾 Code

```cpp
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int zeros = 0, ones = 0;
        int maxScore = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') ones++;
            else zeros++;

            maxScore = max(maxScore, zeros - ones);
        }

        // include last character in total ones
        if (s[n - 1] == '1') ones++;

        return maxScore + ones;
    }
};
```

### Complexity

```
⏱️ Time: O(n)
📦 Space: O(1)
```

## 🔍 Example

- Input: `"011101"`

Best split:

- Left = `"01110"` → zeros = 2
- Right = `"1"` → ones = 1

✔ Output: `3`

## ⚡ Quick Checklist

- Always split till `n-2` (non-empty right)
- Convert:

```
left + right → running + constant
```

- Avoid recomputation
- Think prefix or transformation

## 🚀 Pro Tip

Whenever you see:

- split into two parts
- maximize left + right

👉 Try:

```
(left contribution) + (total - left contribution)
```

🔥 This trick appears in MANY problems (very high ROI)
