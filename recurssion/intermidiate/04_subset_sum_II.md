# 🧠 Subsets II (With Duplicates)

## 🤔 Problem

Given:

```cpp
nums (may contain duplicates)
```

👉 Find all **unique subsets**

Constraints:

* No duplicate subsets allowed
* Order inside subset doesn’t matter
* Order of output doesn't matter

## 💡 Core Idea

```text
At each index:
1. TAKE → include element
2. NOT TAKE → skip element
```

BUT ⚠️ problem: duplicates exist → same subset can repeat

## 🌳 Version 1: TAKE / NOT TAKE + SET (Brute Fix)

## 🧠 Strategy

* Generate ALL subsets (including duplicates)
* Store in `set<vector<int>>` to remove duplicates

## 🧾 Code

```cpp
class Solution {
public:
    // Use set to handle duplicates
    set<vector<int>> st;

    void generate(int index,
                  vector<int>& nums,
                  vector<int>& ds) {

        if (index == nums.size()) {
            st.insert(ds);
            return;
        }

        // TAKE
        ds.push_back(nums[index]);
        generate(index + 1, nums, ds);

        // BACKTRACK
        ds.pop_back();

        // NOT TAKE
        generate(index + 1, nums, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // first sort to handle duplicates

        vector<int> ds;
        generate(0, nums, ds);

        return vector<vector<int>>(st.begin(), st.end());
    }
};
```

## 🌳 Idea Visualization

Each element has 2 choices:

```text
          []
       /      \
     take     not take
     /            \
  include         skip
```

👉 BUT duplicates explode → handled using `set`

## ⏱ Complexity

### Time

```text
O(2^n log K)
```

* 2^n subsets
* logK insertion in set

```text
k = current set size (number of unique subsets)
K ≈ 2^n in worst case (all unique)
```

### Space

```text
O(2^n)
```

(set storage)

## ❌ Problem with this approach

* Extra space (set)
* Slow
* Not interview optimal

# 🚀 Version 2: Optimized FOR LOOP (STANDARD INTERVIEW SOLUTION)

## 💡 Key Insight

Instead of binary recursion:

```text
Fix a start index
Loop forward
Skip duplicates intelligently
```

## 🧾 Code

```cpp
class Solution {
public:

    void solve(int index,
               vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans) {

        ans.push_back(ds); // every node is valid subset

        for (int i = index; i < nums.size(); i++) {

            // 🚨 SKIP DUPLICATES (VERY IMPORTANT)
            if (i > index && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);

            solve(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // critical

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};
```

##b 🌳 Mermaid Recursion Tree (WITH EXECUTION ORDER)

Example:

```cpp
nums = [1,2,2]
```

## 🌳 Tree

```mermaid
graph TD

A["1: f(0, []) | PRINT []"]

A -->|"i=0 add 1"| B["2: f(1, [1]) | PRINT [1]"]
A -->|"i=1 add 2"| F["5: f(2, [2]) | PRINT [2]"]
A -->|"i=2 skip duplicate 2"| X["(skip)"]

%% LEFT SIDE [1]
B -->|"i=1 add 2"| C["3: f(2, [1,2]) | PRINT [1,2]"]
B -->|"i=2 skip duplicate 2"| Y["(skip)"]

C -->|"i=2 add 2"| D["4: f(3, [1,2,2]) | PRINT [1,2,2]"]

D -->|"return (pop 2)"| C2["backtrack → [1,2]"]
C2 -->|"loop ends"| B2["backtrack → [1]"]

B2 -->|"return (pop 1)"| A2["backtrack → []"]

%% RIGHT SIDE [2]
F -->|"i=2 add 2"| G["6: f(3, [2,2]) | PRINT [2,2]"]

G -->|"return (pop 2)"| F2["backtrack → [2]"]
F2 -->|"loop ends"| A3["backtrack → []"]
```

## 🌀 Code Dry Run (arr = [1, 2, 2])

![image.png](../../images/subset_sum_II_recursion_loop_based.png)

# ⚡ Key Trick (MOST IMPORTANT)

## 🚫 Why duplicate skipping works

```cpp
if (i > index && nums[i] == nums[i - 1])
    continue;
```

👉 Meaning:

```text
If same level + same value → skip
```

## 🧠 Visual intuition

```text
[1,2,2]

Level 1:
   2 is only allowed once per level

So we avoid:
   [2 from index 1]
   [2 from index 2] ❌ duplicate
```

# 🔥 Final Mental Model

## Subset problems =

```text
Explore all subsets → DFS tree
```

## With duplicates:

```text
Either:
1. brute force + set
2. smart pruning (BEST)
```
