    # [🧠 Segregate 0s and 1s](https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1)

    ## 🤔 Problem

    Given:

    * Array with only `0` and `1`

    👉 Rearrange:

    ```text
    All 0s → left
    All 1s → right
    ```


    # 🐢 Brute Force Approach (Sorting)

    ## 💡 Idea

    👉 Just sort the array

    Since:

    ```text
    0 < 1
    ```

    Sorting automatically gives desired result


    ## 🧾 Code

    ```cpp
    class Solution {
    public:
        void segregate0and1(vector<int> &arr) {
            sort(arr.begin(), arr.end());
        }
    };
    ```


    ## ⏱️ Complexity

    ```text
    Time: O(n log n)
    Space: O(1) (if in-place sort)
    ```


    ## ❗ Drawback

    ```text
    Unnecessary work (full sorting not needed)
    ```


    # ⚡ Better Approach (Counting)

    ## 💡 Idea

    👉 Count number of `0`s
    👉 Fill array accordingly


    ## 🧾 Code

    ```cpp
    class Solution {
    public:
        void segregate0and1(vector<int> &arr) {
            int count0 = 0;

            for (int x : arr) {
                if (x == 0) count0++;
            }

            for (int i = 0; i < count0; i++) {
                arr[i] = 0;
            }

            for (int i = count0; i < arr.size(); i++) {
                arr[i] = 1;
            }
        }
    };
    ```


    ## ⏱️ Complexity

    ```text
    Time: O(n)
    Space: O(1)
    ```


    ## ❗ Drawback

    ```text
    Overwrites entire array (not minimal swaps)
    ```



    # 🚀 Optimal Approach (Two Pointers)

    ## 💡 Idea

    👉 Partition using two pointers

    ```text
    l → from start
    r → from end
    ```



    ## 🧠 Logic

    ```text
    If arr[l] = 1 and arr[r] = 0 → swap
    Else:
        if arr[l] = 0 → l++
        else → r--
    ```


    ## 🧾 Code

    ```cpp
    class Solution {
    public:
        void segregate0and1(vector<int> &arr) {
            int l = 0, r = arr.size() - 1;

            while (l < r) {
                if (arr[l] == 1 && arr[r] == 0) {
                    swap(arr[l], arr[r]);
                    l++;
                    r--;
                }
                else if (arr[l] == 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
    };
    ```



    ## ⏱️ Complexity

    ```text
    Time: O(n)
    Space: O(1)
    ```



    ## ✅ Why Optimal?

    ```text
    ✔ Single pass
    ✔ In-place
    ✔ Minimum swaps
    ```



    # 🔥 Pattern Recognition

    This is:

    ```text
    2-way partition problem
    ```

    👉 Base of:

    * QuickSort partition
    * Dutch National Flag (0,1,2)



    # ⚡ Final Comparison

    | Approach            | Time       | Space | Notes      |
    | ------------------- | ---------- | ----- | ---------- |
    | Brute (Sort)        | O(n log n) | O(1)  | Overkill   |
    | Better (Count)      | O(n)       | O(1)  | Overwrites |
    | Optimal (2-pointer) | O(n)       | O(1)  | Best       |


    # 🎯 Final Takeaway

    ```text
    If only 0s and 1s → never sort
    Use partition (two pointers)
    ```


