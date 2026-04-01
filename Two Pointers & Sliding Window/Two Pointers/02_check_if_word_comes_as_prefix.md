# 🧠 [Prefix of Word in a Sentence (LeetCode 1455)](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)


## 🤔 Problem

* Given a sentence (space-separated words)
* Given a `searchWord`

👉 Find the **first word (1-based index)** where:

```
searchWord is a prefix of that word
```

👉 If not found → return `-1`


## 💡 Core Concept

### ✅ What is a Prefix?

```
Prefix = substring starting at index 0
```

✔ Valid:

```
"burger", "burg" → ✅
```

❌ Invalid:

```
"burger", "urge" → ❌ (not starting at index 0)
```


## 🧩 Key Observations

* Words are separated by **spaces**
* Prefix check must happen only at:

```
start of each word
```


## 🔍 How to Identify Word Start

A character is start of word if:

```
i == 0 OR previous character is ' '
```


## 🧠 Approaches


## 🐢 1. Direct Traversal (Optimal Thinking)

### Idea:

* Traverse sentence character by character
* Detect word start
* Try matching `searchWord`


### 🧾 Code

```cpp
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();

        int word = 1;

        for (int i = 0; i < n; i++) {

            if (i == 0 || sentence[i - 1] == ' ') {
                int j = 0, k = i;

                while (k < n && j < m && sentence[k] == searchWord[j]) {
                    k++;
                    j++;
                }

                if (j == m) return word;
            }

            if (sentence[i] == ' ') word++;
        }

        return -1;
    }
};
```


### Characteristics:

```
✔ One pass
✔ No extra space
✔ More control
```


### Complexity:

```
⏱️ Time: O(n * m)   (worst case)
📦 Space: O(1)
```


### ⚠️ Important Insight

* Even though matching breaks early sometimes,
* Worst case still:

```
O(n * m)
```

👉 Because repeated comparisons can happen


## 🚚 2. Manual String Split

### Idea:

* Split sentence into words
* Check prefix for each word


### 🧾 Code

```cpp
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string temp = "";

        for (char ch : sentence) {
            if (ch == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        words.push_back(temp);

        for (int i = 0; i < words.size(); i++) {
            if (words[i].substr(0, searchWord.size()) == searchWord) {
                return i + 1;
            }
        }

        return -1;
    }
};
```


### Characteristics:

```
✔ Easy to understand
✔ Clean logic
❌ Uses extra space
```


### Complexity:

```
⏱️ Time: O(n)
📦 Space: O(n)
```


## 🚀 3. Using stringstream

### Idea:

* Use built-in splitting mechanism
* Extract words one by one


### 🧾 Code

```cpp
#include <sstream>

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int index = 1;

        while (ss >> word) {
            if (word.substr(0, searchWord.size()) == searchWord) {
                return index;
            }
            index++;
        }

        return -1;
    }
};
```


### Characteristics:

```
✔ Cleanest approach
✔ Less error-prone
✔ Readable
❌ Extra space used internally
```


### Complexity:

```
⏱️ Time: O(n)
📦 Space: O(n)
```


## ⚖️ Approach Comparison

| Approach         | Time     | Space | Notes               |
|- |-- |-- |- |
| Direct traversal | O(n * m) | O(1)  | Best for interviews |
| Manual split     | O(n)     | O(n)  | More control        |
| stringstream     | O(n)     | O(n)  | Cleanest            |


## 🔥 Important Edge Cases

1. **Single word**

```
"hello", "he" → 1
```

2. **No match**

```
"i love code", "xyz" → -1
```

3. **Prefix longer than word**

```
"hi", "hello" → -1
```

4. **Multiple matches**

```
"abc abcd abcde", "ab" → return first (1)
```

5. **Match at last word**

```
"i love burger", "burg" → 3
```


## ⚡ Quick Checklist

* Prefix must start at index `0`
* Always return **1-based index**
* Detect word boundary properly
* Avoid unnecessary comparisons









