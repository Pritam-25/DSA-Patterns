# 🔍 [🧠 Search Insert Position (Binary Search)](https://leetcode.com/problems/search-insert-position/)

# 🤔 Problem

Given:

```text
Sorted array of integers (ascending order)
Target value
```

👉 Find:

```text
Index of target if found

Otherwise:
Index where it should be inserted
to maintain sorted order
```

# 🐢 Brute Force Approach (Linear Search)

## 💡 Idea

👉 Traverse array from left
👉 First position where `nums[i] >= target` → return `i`

## 🧾 Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};
```

## ⏱️ Complexity

```text
Time: O(n)
Space: O(1)
```

# 🚀 Optimal Approach (Binary Search - Lower Bound)


```text
Array is sorted → think Binary Search
```

👉 We need:

```text
First position where element >= target
```

👉 This is exactly:

```text
Lower Bound
```


## 💡 Idea

👉 Use binary search to narrow range
👉 If target found → return index
👉 Else → return insertion position (`low`)

## 🧠 Core Logic

```text
low → possible answer
high → discard invalid range

At end:
low = correct insert position
```

## 🧾 Code

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = high - (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
```

## ⏱️ Complexity

```text
Time: O(log n)
Space: O(1)
```

# ⚠️ Important Edge Cases

### 1️⃣ Target smaller than all elements

```text
nums = [3,5,7]
target = 1

👉 insert at index 0
```

### 2️⃣ Target greater than all elements

```text
nums = [3,5,7]
target = 10

👉 insert at index n
```

### 3️⃣ Target exists

```text
nums = [1,3,5,6]
target = 5

👉 return exact index
```

# ❌ Common Mistakes

```text
1. Returning high ❌ (wrong for insert position)
```

