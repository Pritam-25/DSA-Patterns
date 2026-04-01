# 🧠 Clear Digits (LeetCode 3174)

## 🤔 Problem

Given a string `s`, repeatedly perform:

* Delete the **first digit**
* Delete the **closest non-digit character to its left**

Return the final string.


## 💡 Key Idea

* Each digit removes **one previous character**
* This behaves like a **stack (LIFO)**:

  * push characters
  * pop when digit appears


## 🐢 Brute Force Approach

### Steps

1. Find the **first digit** in the string.
2. Traverse left to find the **nearest non-digit**.
3. Remove both:

   * the digit
   * the left character
4. Repeat until no valid operation exists.


### 🧾 Code

```cpp
class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            int digitIndex = -1;

            // find first digit
            for (int i = 0; i < s.size(); i++) {
                if (isdigit(s[i])) {
                    digitIndex = i;
                    break;
                }
            }

            if (digitIndex == -1) break;

            // find closest non-digit to left
            int leftIndex = -1;
            for (int i = digitIndex - 1; i >= 0; i--) {
                if (isalpha(s[i])) {
                    leftIndex = i;
                    break;
                }
            }

            if (leftIndex == -1) break;

            // remove digit first, then left char
            s.erase(digitIndex, 1);
            s.erase(leftIndex, 1);
        }

        return s;
    }
};
```


### Complexity

```
⏱️ Time: O(n²)
📦 Space: O(1)
```


## 🚚 Better Approach (Explicit Stack)

### Steps

1. Use a `stack<char>`
2. Traverse string:

   * If **letter → push**
   * If **digit → pop (if stack not empty)**
3. Build result from stack


### 🧾 Code

```cpp
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (char ch : s) {
            if (isalpha(ch)) {
                st.push(ch);
            } else {
                if (!st.empty()) st.pop();
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```


### Complexity

```
⏱️ Time: O(n)
📦 Space: O(n)
```


## 🚀 Optimal Approach (String as Stack)

### Steps

1. Use a string as a stack (`ans`)
2. Traverse string:

   * If **letter → append**
   * If **digit → pop_back()**
3. Return result

---

### 🧾 Code

```cpp
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";

        for (char ch : s) {
            if (isalpha(ch)) {
                ans += ch;
            } else {
                if (!ans.empty()) ans.pop_back();
            }
        }

        return ans;
    }
};
```

### Complexity

```
⏱️ Time: O(n)
📦 Space: O(n)
```


## 🔍 Example

* Input: `"cb34"`
* Steps:

  * push `c`, push `b`
  * `3` → pop `b`
  * `4` → pop `c`
* Output: `""`


## ⚡ Quick Checklist

* Digit = **remove previous character**
* Think → **stack pattern**
* Avoid `erase()` in optimal → costly O(n)
* Prefer `pop_back()` → O(1)


## 🚀 Pro Tip

* Whenever:

  * "remove previous element"
  * "undo last operation"

👉 Immediately think **STACK**


