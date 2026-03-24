# 📏 Largest Subarray / Substring Type — Revision Notes

## 🧩 Pattern Goal

Find the **longest valid segment** (subarray / substring) under a condition.

In your current files, condition is:

- longest subarray with sum $\leq k$

---

## 1) 🐢 Brute Force Approach

### 💡 Idea

Try every start index `i`, keep extending `j`, and stop when condition breaks.

### ⚙️ Code (from brute_force_approach.cpp)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxLength(vector<int> arr, int k) {
    int n = arr.size();

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break;
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    int k = 7;

    int result = findMaxLength(arr, k);
    cout << "maximum length is: " << result;
}
```

### ⏱ Complexity

```text
Time Complexity: O(N^2)
Space Complexity: O(1)
```

---

## 2) 🚶 Better Approach (Two Pointer + While Shrink)

### 💡 Idea

Expand right pointer $r$, and whenever sum becomes $> k$, keep shrinking from left until valid again.

### ⚠️ Important

Works reliably for **non-negative arrays**.

### ⚙️ Code (from better_approach.cpp)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxLength(vector<int> arr, int k) {
    int n = arr.size();

    int maxLen = 0;
    int sum = 0;
    int l = 0;
    int r = 0;

    while (r < n) {
        sum += arr[r];

        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {3, 1, 2, 7, 4, 2, 1};
    int k = 8;

    int result = findMaxLength(arr, k);
    cout << "maximum length is: " << result;
}
```

### ⏱ Complexity

```text
Time Complexity: O(N)
Space Complexity: O(1)
```

---

## 3) ⚡ Optimal Variant (Single Shrink Step)

### 💡 Idea

Expand $r$ and do only one left-shrink step when sum exceeds $k$.

### ⚠️ Important

- This is a **specific variant**, not universally safe.
- For sum-based sliding window patterns, positivity assumptions are crucial.

### ⚙️ Code (from optimal_approach.cpp)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxLength(vector<int> arr, int k) {
    int n = arr.size();

    int maxLen = 0;
    int sum = 0;
    int l = 0;
    int r = 0;

    while (r < n) {
        sum += arr[r];

        if (sum > k) {
            sum -= arr[l];
            l++;
        }

        if (sum <= k) {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {3, 1, 2, 7, 4, 2, 1};
    int k = 8;

    int result = findMaxLength(arr, k);
    cout << "maximum length is: " << result;
}
```

### ⏱ Complexity

```text
Time Complexity: O(N)
Space Complexity: O(1)
```

---

## 📊 Revision Summary

| Approach                | Time   | Space | Use                             |
| ----------------------- | ------ | ----- | ------------------------------- |
| Brute Force             | O(N^2) | O(1)  | Baseline / easy to verify       |
| Better (while shrink)   | O(N)   | O(1)  | Preferred on positive arrays    |
| Optimal (single shrink) | O(N)   | O(1)  | Specific variant, use carefully |

---

## 🧠 Pattern Recognition

Use this pattern when:

- ✅ You need **maximum length** subarray/substring
- ✅ Condition is maintained by moving pointers
- ✅ Window can grow/shrink dynamically

---

## 🚀 Quick Revision Checklist

- ✅ Fixed size? → Constant window
- ✅ Variable size + condition? → Two pointers
- ✅ If using sum-based shrinking window, verify element-sign constraints
- ✅ Update answer only when window is valid
