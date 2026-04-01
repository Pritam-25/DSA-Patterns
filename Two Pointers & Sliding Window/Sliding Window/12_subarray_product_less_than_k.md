# [🧠 Number of Subarrays with Product Less Than K (LeetCode 713)](https://leetcode.com/problems/subarray-product-less-than-k/description/)


## 🤔 Problem

Given:

* An array `nums` of positive integers
* An integer `k`

👉 Count the number of **contiguous subarrays** where:

```text
product of elements < k
```


## 💡 Core Concept

* Subarrays ⇒ continuous
* Condition ⇒ product < k

👉 Since all numbers are **positive**:

* Multiply when expanding
* Divide when shrinking


## 🐢 Brute Force Approach

### Idea

* Generate all subarrays
* Calculate product
* Count if `< k`


### 🧾 Code

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int product = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                if (product < k) count++;
                else break; // optimization (since product only increases)
            }
        }

        return count;
    }
};
```


### Complexity

```
⏱️ Time: O(n²)
📦 Space: O(1)
```


## 🚀 Optimal Approach (Sliding Window)

### Idea

* Use two pointers (`l`, `r`)
* Maintain current product
* Shrink window when product ≥ k


### 🔥 Key Formula

At each `r`:

```
subarrays = (r - l + 1)
```


### 🧾 Code

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // important edge case

        int n = nums.size();
        int count = 0;
        int product = 1;
        int l = 0;

        for (int r = 0; r < n; r++) {
            product *= nums[r];

            while (product >= k) {
                product /= nums[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }
};
```


### Complexity

```
⏱️ Time: O(n)
📦 Space: O(1)
```


## ⚠️ Important Edge Case

```
k <= 1 → answer = 0
```

👉 Because:

* Product of positive numbers ≥ 1
* No valid subarray exists


## 🔍 Example

```
nums = [10, 5, 2, 6], k = 100
```

Valid subarrays:

```
[10], [5], [2], [6]
[10,5], [5,2], [2,6]
[5,2,6]
```

✔ Output: `8`


## ⚡ Pattern Recognition

Whenever you see:

* Subarray
* Product / sum constraint
* All elements positive

👉 Think:

```
Sliding Window + Two Pointers
```


## 🔥 Final Takeaway

* Brute force ⇒ generate all subarrays
* Optimal ⇒ sliding window
* Key trick:

```
count += (r - l + 1)
```


