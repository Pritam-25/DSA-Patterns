# 🔍 [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## 🤔 Problem

Given:

```text
Sorted array rotated at some pivot
(No duplicates)
```

👉 Find:

```text
Minimum element in the array
```

## 🧠 Key Observation

```text
👉 In rotated sorted array:
   Minimum element = pivot point

👉 At least ONE half is always sorted
```

# 🐢 Brute Force

## 💡 Idea

```text
Traverse entire array
Keep track of minimum
```

## ⏱️ Complexity

```text
Time: O(n)
Space: O(1)
```

# ⚡ Slightly Better Approach

## 💡 Idea

```text
Find the point where order breaks:
nums[i] < nums[i-1]
```

## 🧾 Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};
```

## ⏱️ Complexity

```text
Time: O(n)
```

# ⚠️ Binary Search (Works but NOT Clean)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int mini = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < mini) {
                mini = min(nums[mid], mini);
            }

            if(nums[low] > nums[mid] && nums[high] > nums[mid]){
                low ++;
                high --;
            }
            else if (nums[low] < nums[mid] && nums[high] < nums[mid]) {
                if (nums[low] < nums[high]) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            } else if (nums[low] < nums[mid]) {
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return mini;
    }
};
```

👉 This approach works, but:

```text
❌ Overcomplicated conditions
❌ Hard to reason in interview
❌ Not optimal thinking
```

👉 Interviewers prefer **clear binary search pattern**

# 🚀 Optimal Approach (Clean Binary Search)

## 💡 Idea

```text
👉 If left half is sorted:
   minimum is nums[low]

👉 Else:
   minimum lies in unsorted half
```

## 🧠 Core Logic

```text
If nums[low] <= nums[mid]:
    left half is sorted
    → take nums[low]
    → search right

Else:
    right half is unsorted
    → take nums[mid]
    → search left
```

## 🧾 Code (Best Version)

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // ✅ If already sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // Left half sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half sorted (pivot lies left)
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
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
Binary Search on rotated array (finding pivot/minimum)
```

👉 Same pattern used in:

- Search in rotated array
- Rotation count
- Peak element variation

# ❌ Common Mistakes (VERY IMPORTANT)

## ❌ Mistake 1: Using `<` instead of `<=`

```text
Wrong:
nums[low] < nums[mid]

Correct:
nums[low] <= nums[mid]
```

### ⚡ Why?

```text
Case: [1] or [2,1]

If only one element:
low == mid

👉 must include equality
```

## ❌ Mistake 2: Forgetting to update answer

```text
If you don’t track min → you lose answer
```

✔ Always:

```cpp
ans = min(ans, ...)
```

## ❌ Mistake 3: Not understanding sorted half

```text
If nums[low] <= nums[mid]
→ left side sorted
→ minimum = nums[low] (NOT nums[mid])
```

## ❌ Mistake 4: Wrong direction move

```text
Sorted half NEVER contains pivot (minimum)

👉 Always go to UNSORTED half
```

# ⚡ Dry Run (Important)

```text
nums = [4,5,6,7,0,1,2]  
```

| low               | mid | high | Action                          |
| ----------------- | --- | ---- | ------------------------------- |
| 0                 | 3   | 6    | left sorted → take 4 → go right |
| 4                 | 5   | 6    | left sorted → take 0 → go right |
| done → answer = 0 |     |      |                                 |

# 🧠 One Line Intuition

```text
👉 Minimum always lies in UNSORTED half
👉 Sorted half gives candidate answer
```
