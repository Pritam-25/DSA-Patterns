# 🧠 Sliding Window Counting Cheat Sheet

## ⚔️ Two Powerful Patterns
| Pattern                           | Formula       |
| --------------------------------- | ------------- |
| Count subarrays **ending at r**   | `(r - l + 1)` |
| Count subarrays **starting at l** | `(n - r)`     |



# 🟢 1. `(r - l + 1)` → “Ending at r”

## 💡 When to Use

👉 When condition ensures:

```text
All subarrays ending at index r are valid
```


## 🧠 Intuition

Fix `r`, move `l` to maintain validity:

```text
[l ... r] is valid
```

Then:

```text
[l...r], [l+1...r], [l+2...r], ... [r...r]
```

👉 Total:

```text
r - l + 1
```


## 📌 Typical Problems

* Subarray sum ≤ k
* Product < k (**LeetCode 713**)
* Longest substring without repeating characters


## 🔥 Example

```cpp
count += (r - l + 1);
```


## 🎯 Visual

```text
Array:  [ a  b  c  d ]
Index:   0  1  2  3

r = 3, l = 1

Valid subarrays:
[b,c,d]
[c,d]
[d]

Count = 3 = (3 - 1 + 1)
```


# 🔴 2. `(n - r)` → “Starting at l”

## 💡 When to Use

👉 When condition ensures:

```text
Once valid → all future extensions are also valid
```


## 🧠 Intuition

Fix `l`, expand `r`:

```text
[l ... r] is valid
```

Then:

```text
[l...r], [l...r+1], [l...r+2], ... [l...n-1]
```

👉 Total:

```text
n - r
```


## 📌 Typical Problems

* Element appears ≥ k times
* Subarray with at least k occurrences
* Problems with **“at least” condition**


## 🔥 Example

```cpp
subArr += (n - r);
```


## 🎯 Visual

```text
Array:  [ a  b  c  d  e ]
Index:   0  1  2  3  4

l = 1, r = 3

Valid subarrays:
[b,c,d]
[b,c,d,e]

Count = 2 = (5 - 3)
```


# 🔥 Ultimate Difference

| Feature         | `(r - l + 1)`         | `(n - r)`        |
| --------------- | --------------------- | ---------------- |
| Focus           | Ending at `r`         | Starting at `l`  |
| Direction       | Backward              | Forward          |
| Condition type  | “at most / less than” | “at least / ≥”   |
| Window behavior | Expand → shrink       | Expand → shrink  |
| Counting        | Left variations       | Right extensions |



# 🧠 Decision Trick (INTERVIEW GOLD)

## 👉 Ask yourself:

### ❓ “After condition is satisfied…”

### Case 1:

```text
How many subarrays END at r?
```

✅ Use:

```text
(r - l + 1)
```


### Case 2:

```text
Can I extend r further and still remain valid?
```

✅ Use:

```text
(n - r)
```


# 🔥 One-Line Memory Trick

```text
(r - l + 1) → count left side
(n - r)     → count right side
```


# 🚀 Pro Tip (VERY IMPORTANT)

### 👉 Keywords:

| Keyword in Question | Pattern       |
|- |- |
| less than / at most | `(r - l + 1)` |
| at least / ≥ k      | `(n - r)`     |


# 🎯 Final Takeaway

```text
If validity spreads LEFT → use (r - l + 1)
If validity spreads RIGHT → use (n - r)
```


