# 🪟 Constant Window — Revision Notes

## 🧩 Problem

Given an integer array `arr` of size `n` and an integer `k`,
find the **maximum sum of any contiguous subarray of size `k`**.

```
Example:
arr = {-1, 2, 3, 3, 4, 5, -1}
k = 4

Output: 15
```

## 💡 Key Idea (Fixed Window)

👉 Maintain a **window of size `k`** and slide it across the array.

### Steps:

1. 🔹 Compute sum of first `k` elements (initial window)
2. 🔹 Slide the window one step at a time:
   - ➖ Remove left element
   - ➕ Add next right element

3. 🔹 Track the **maximum sum**

## ⚙️ Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxSum(vector<int> arr, int k) {
    int n = arr.size();

    int sum = 0;

    //  Step 1: Compute first window
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    int l = 0;
    int r = k - 1;

    //  Step 2: Slide the window
    while (r < n - 1) {
        sum -= arr[l];   //  remove left element
        l++;

        r++;
        sum += arr[r];   //  add right element

        maxSum = max(maxSum, sum); //  update answer
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;

    int result = findMaxSum(arr, k);
    cout << "Maximum sum is: " << result;
}
```

---

## ⏱ Complexity

```text
Time Complexity: O(N)
Each element is processed once

Space Complexity: O(1)
No extra space used (only variables)
```

---

## 🧠 Pattern Recognition

Use **Constant Window** when:

- ✅ Window size is **fixed (k)**
- ✅ Asked for **sum / max / min** of subarray of size `k`

---

## 🚀 Quick Revision Checklist

- ✅ Fixed window size? → Use **constant window**
- ✅ Initialize **first window correctly**
- ✅ Always:
  - ➖ Remove left
  - ➕ Add right

- ✅ Update answer **after each slide**

---

## 🔥 Pro Tip

👉 If window size is **not fixed**, then it's **NOT constant window**
➡️ Switch to **dynamic sliding window**
