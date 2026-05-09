tags: #DSA/BinarySearch/lower_and_upper_bound
# 🧠 LOWER BOUND & UPPER BOUND MASTER SHEET


## 🔥 Pattern: Boundary Binary Search

### 👉 Not finding value — finding position


# 📌 LOWER BOUND

## 👉 Definition

```text
First index where value >= target
```


## 💡 Idea

```text
Find smallest element that is NOT LESS than target
```


## 🧠 Intuition

```text
arr[mid] >= target → possible answer → go LEFT
arr[mid] < target → go RIGHT
```

👉 You don’t stop when found
👉 You try to find **better (leftmost) answer**


## 🧾 Code

```cpp
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // default (if not found)

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1; // move left
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
```


## 🎯 Example

```text
arr = [1, 2, 4, 4, 5]
target = 4

Lower Bound = index 2 (first 4)
```


## ⚡ Use Cases

```text
• First occurrence of element
• Search Insert Position
• Count occurrences
```



# 📌 UPPER BOUND

## 👉 Definition

```text
First index where value > target
```


## 💡 Idea

```text
Find smallest element STRICTLY greater than target
```


## 🧠 Intuition

```text
arr[mid] > target → possible answer → go LEFT
arr[mid] <= target → go RIGHT
```


## 🧾 Code

```cpp
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1; // move left
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
```


## 🎯 Example

```text
arr = [1, 2, 4, 4, 5]
target = 4

Upper Bound = index 4 (value 5)
```



## 🔥 KEY DIFFERENCE (VERY IMPORTANT)

| Condition | Lower Bound | Upper Bound            |
| --------- | ----------- | ---------------------- |
| Check     | >= target   | > target               |
| Meaning   | First valid | First strictly greater |



## 🧠 POWER FORMULA (VERY IMPORTANT)

### 👉 Count occurrences of target

```cpp
count = upperBound(arr, target) - lowerBound(arr, target);
```


## 🎯 Example

```text
arr = [1, 2, 4, 4, 4, 5]

LB = 2
UB = 5

count = 5 - 2 = 3
```



# ⚠️ EDGE CASES

## ❗ Case 1: Target not present

```text
arr = [1, 2, 3]
target = 4

Lower Bound = 3 (n)
Upper Bound = 3 (n)
```


## ❗ Case 2: All elements greater

```text
arr = [1, 2, 3]
target = 0

Lower Bound = 0
Upper Bound = 0
```


## ❗ Case 3: All elements same

```text
arr = [4, 4, 4, 4]

LB = 0
UB = 4
```


## ⏱ COMPLEXITY

```text
Time: O(log n)
Space: O(1)
```


## 🚀 INTERVIEW TRICK (GOLD 🔥)

Whenever you see:

```text
• First occurrence
• Last occurrence
• Count duplicates
• Insert position
```

👉 Think immediately:

```text
Lower Bound + Upper Bound
```

