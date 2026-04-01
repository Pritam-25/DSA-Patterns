# [🍎 Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/description/)

## 🤔 Same Problem as

Find the length of the longest subarray with at most 2 distinct elements.

## 💡 Key Idea (Sliding Window)

- Maintain a window `[l...r]` that contains at most 2 fruit types.
- Expand `r` by adding `fruits[r]` to frequency map.
- If distinct types become more than 2, shrink `l` until valid again.
- Track the maximum window length.

## 🐢 Brute Force Approach

### Steps

1. Start from every index `i`.
2. Use a set to store distinct fruits in current subarray.
3. Expand `j` from `i` while distinct count is at most 2.
4. Update answer with current length.

### 🧾 Code

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            set<int> s;

            for (int j = i; j < n; j++) {
                s.insert(fruits[j]);

                if (s.size() > 2) break;

                maxCount = max(maxCount, j - i + 1);
            }
        }

        return maxCount;
    }
};
```

### Complexity

```
⏱️ Time: O(n²)
📦 Space: O(1)
```


## ⚡ Better Sliding Window (with frequency map + while)

### Steps

1. Keep two pointers `l` and `r`.
2. Add `fruits[r]` into map.
3. While map size is more than 2, remove from left and move `l`.
4. Update `maxCount` with valid window length.

### 🧾 Code

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int maxCount = 0;
        unordered_map<int, int> freq;

        for (int r = 0; r < n; r++) {
            freq[fruits[r]]++;

            while (freq.size() > 2) {
                freq[fruits[l]]--;

                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }

                l++;
            }

            maxCount = max(maxCount, r - l + 1);
        }

        return maxCount;
    }
};
```

### Complexity

```
⏱️ Time: O(2n) = O(n)
📦 Space: O(1)
```


## 🚀 One-Shrink Version (remove innner while loop) -- best

### Steps

1. Expand `r` and add current fruit.
2. If distinct fruits exceed 2, shrink only once.
3. Update max length.

### 🧾 Code

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int maxCount = 0;
        unordered_map<int, int> freq;

        for (int r = 0; r < n; r++) {
            freq[fruits[r]]++;

            if (freq.size() > 2) {
                freq[fruits[l]]--;

                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }

                l++;
            }

            maxCount = max(maxCount, r - l + 1);
        }

        return maxCount;
    }
};
```

### Complexity

```
⏱️ Time: O(n)
📦 Space: O(1)
```


## ⚠️ Important Note

- The one-shrink version is not always safe.
- In some cases, window needs multiple shrinks to become valid.
- The while-based sliding window is the standard reliable version.

## 🧠 Final Conclusion (Interview Ready)

| Approach               | Status               | When to Use                        |
| ---------------------- | -------------------- | ---------------------------------- |
| Brute Force            | ❌ Not practical     | Only for understanding             |
| Sliding Window + while | ✅ Best and standard | Always safe                        |
| Without while          | ⚠️ Risky             | Only when one shrink is guaranteed |


## Quick Checklist

- Use hashmap frequency for distinct-count window problems.
- Keep shrinking while window is invalid.
- Update answer only when window is valid.

## Pro Tip

👉 Never use `set` in sliding window when:

- duplicates exist
- window needs shrinking

👉 Always use:

```cpp
unordered_map<int, int> freq;
```
