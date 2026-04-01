# 🧠 BINARY SEARCH 

## 👉 Find Element in Sorted Array

## 💡 Idea

```text
Search in sorted array
Divide search space into half
```

## 🧠 Intuition

```text
Middle element decides direction

arr[mid] == target → found
arr[mid] < target → go right
arr[mid] > target → go left
```

## 🧾 Code (Iterative)

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}
```

## 🧾 Code (Recursive)

```cpp
int binarySearch(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target);
    else
        return binarySearch(arr, low, mid - 1, target);
}
```

## ⚠️ Overflow Case (VERY IMPORTANT)

### ❌ Wrong

```cpp
int mid = (low + high) / 2;
```

### 💥 Why?

```text
If low and high are large → (low + high) overflows INT
```

### ✅ Correct

```cpp
int mid = low + (high - low) / 2;
```

## 🎯 Pattern

```text
Divide and Conquer
```

## ⏱ Complexity

```text
Time: O(log n)
Space: O(1) iterative
Space: O(log n) recursive (call stack)
```

