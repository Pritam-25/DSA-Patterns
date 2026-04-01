# 🧠 Pivot Integer (LeetCode 2485)

## 🤔 Problem

Given a positive integer `n`, find an integer `x` such that:

* Sum of numbers from `1 → x`
* Equals sum of numbers from `x → n`

Return `x`, or `-1` if no such integer exists.


## 💡 Key Idea

* We are balancing **two parts of the number line**
* Left sum = Right sum
* Can be solved using:

  * brute force (check all)
  * prefix / two pointer idea
  * math optimization


## 🐢 Brute Force Approach

### Steps

1. Try every `x` from `1 → n`
2. Compute:

   * sum from `1 → x`
   * sum from `x → n`
3. If both equal → return `x`
4. Otherwise continue


### 🧾 Code

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        for (int x = 1; x <= n; x++) {
            int sum1 = 0, sum2 = 0;

            // sum from 1 to x
            for (int i = 1; i <= x; i++) {
                sum1 += i;
            }

            // sum from x to n
            for (int i = x; i <= n; i++) {
                sum2 += i;
            }

            if (sum1 == sum2) return x;
        }
        return -1;
    }
};
```


### Complexity

```
⏱️ Time: O(n²)
📦 Space: O(1)
```


## 🚚 Better Approach (Prefix Sum)

### Steps

1. Precompute total sum = `n(n+1)/2`
2. Iterate `x` from `1 → n`
3. Keep prefix sum (`leftSum`)
4. Compute right sum:

   * `rightSum = total - leftSum + x`
5. If equal → return `x`


### 🧾 Code

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n + 1)) / 2;

        int leftSum = 0;

        for (int x = 1; x <= n; x++) {
            leftSum += x;

            int rightSum = total - leftSum + x;

            if (leftSum == rightSum) return x;
        }

        return -1;
    }
};
```


### Complexity

```
⏱️ Time: O(n)
📦 Space: O(1)
```

## 🚚 Better Approach (Two Pointers from Both Ends)

### Steps

1. Initialize:

   * `l = 1`, `r = n`
   * `leftSum = l`, `rightSum = r`
2. While `l < r`:

   * If `leftSum < rightSum` → move left pointer
   * Else → move right pointer
3. When `l == r`:

   * Check if `leftSum == rightSum`
4. Return `l` or `-1`



## 🧾 Code

```cpp id="1y76l2"
class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n;

        int leftSum = l;
        int rightSum = r;

        while (l < r) {
            if (leftSum < rightSum) {
                l++;
                leftSum += l;
            } else {
                r--;
                rightSum += r;
            }
        }

        if (leftSum == rightSum) return l;

        return -1;
    }
};
```


## ⏱️ Complexity

```id="5m3l7j"
⏱️ Time: O(n)
📦 Space: O(1)
```


## 🚀 Optimal Approach (Math Formula)

### Steps

1. Let pivot = `x`
2. Write equation:

   * sum(1 → x) = sum(x → n)
3. Solve mathematically → reduces to:

[
x^2 = \frac{n(n+1)}{2}
]

4. Compute:

   * `total = n(n+1)/2`
   * `x = sqrt(total)`
5. If `x*x == total` → return `x`
6. Else return `-1`


### 🧾 Code

```cpp
class Solution {
public:
    int pivotInteger(int n) {
        int total = (n * (n + 1)) / 2;

        int x = sqrt(total);

        if (x * x == total) return x;

        return -1;
    }
};
```


### Complexity

```
⏱️ Time: O(1)
📦 Space: O(1)
```


## 🔍 Example

* Input: `n = 8`

Steps:

* total = 8×9/2 = 36
* √36 = 6

✔ Output: `6`


## ⚡ Quick Checklist

* Equal sum → try equation
* Avoid nested loops if possible
* Use prefix sum to optimize
* Check for **perfect square**


## 🚀 Pro Tip

* Whenever:

  * "left sum = right sum"
  * "partition into equal parts"

👉 Try converting into a **math equation instead of brute force**




