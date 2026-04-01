# 🔍 [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

# 🤔 Problem

Given:

```text
Sorted array rotated at some pivot
(No duplicates)
Target value
```

👉 Find:

```text
Index of target
If not found → return -1
```

# 🧠 Key Observation

```text
In a rotated sorted array:
👉 At least ONE half is always sorted
```

# 🐢 Brute Force

## 💡 Idea

```text
Linear search
```

## ⏱️ Complexity

```text
Time: O(n)
```

# 🚀 Optimal Approach (Modified Binary Search)

## 💡 Idea

👉 Use binary search
👉 Identify which half is sorted
👉 Check if target lies in that half

## 🧠 Core Logic

```text
If left half is sorted:
    check → nums[low] <= target < nums[mid]

If right half is sorted:
    check → nums[mid] < target <= nums[high]
```

## 🧾 Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Right half sorted
            else {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
```

## ⏱️ Complexity

```text
Time: O(log n)
Space: O(1)
```

# 🔥 Pattern Recognition

This is:

```text
Binary Search on rotated array
```

👉 Same pattern used in:

- Find minimum in rotated array
- Search with duplicates
- Rotation count problems

# ❌ Common Mistakes (VERY IMPORTANT)

```text
1. Wrong condition:
   using → target >= nums[mid] ❌
   correct → target > nums[mid] ✔️

2. Forgetting strict inequalities:
   < vs <= matters a lot ❌

3. Not checking sorted half properly ❌
```

## ⚡ Why `target > nums[mid]` (NOT >=)

```text
Because nums[mid] is already checked:

if (nums[mid] == target) → return mid
```

👉 So:

```text
Using >= is redundant and can break logic
```

### Example Problem:

```text
nums = [4,5,6,7,0,1,2]
target = 0
```

👉 If you use:

```text
target >= nums[mid]
```

👉 It may incorrectly include mid in range and go wrong direction ❌
