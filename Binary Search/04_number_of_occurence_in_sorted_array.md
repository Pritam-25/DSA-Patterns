# 🔍 [🧠 Number of Occurrences in Sorted Array](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)

# 🤔 Problem

Given:

```text
Sorted array of integers
Target value
```

👉 Find:

```text
Total number of times target appears
```

---

# 😭 Normal Approach (Why It Fails ❌)

## 💡 Idea

```text
Use Binary Search
If arr[mid] == target → increase count
```

---

## ❌ Problem in Logic

```text
Binary Search only visits few elements (log n)

So you may miss many occurrences
```

### Example:

```text
arr = [2, 4, 4, 4, 6]
target = 4
```

👉 Your code may count:

```text
Only 1 or 2 (wrong ❌)
```

👉 Actual answer:

```text
3
```


# 💀 Correct Approach (Binary Search × 2)

## 💡 Idea

```text
Sorted array → duplicates are grouped together
```

👉 Instead of counting manually:

```text
Find:
First occurrence (Lower Bound)
Last occurrence (Upper Bound - 1)
```

👉 Answer:

```text
count = lastIndex - firstIndex + 1
```

---

# 🧠 Core Logic

```text
Lower Bound  → first index where arr[i] >= target
Upper Bound  → first index where arr[i] > target
```

---

# 🧾 Code

```cpp
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = high - (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = high - (high - low) / 2;

            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = lowerBound(arr, target);
        int last = upperBound(arr, target) - 1;

        if (first == arr.size() || arr[first] != target)
            return 0;

        return last - first + 1;
    }
};
```

---

## ⏱️ Complexity

```text
Time: O(log n)
Space: O(1)
```


# 🔥 Pattern Recognition

This is:

```text
Binary Search on Answers
+ Lower Bound + Upper Bound
```

👉 Same pattern as:

* Count occurrences
* First & Last position
* Range queries in sorted array



