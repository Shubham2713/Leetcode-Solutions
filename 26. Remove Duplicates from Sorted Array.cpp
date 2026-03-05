// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0;
        int n= nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=nums[c]) {
                c++;
                nums[c] = nums[i];
            }
        }
        
        return c+1;
    }
};

/*
Here are the interview questions that usually come up around **Remove Duplicates from Sorted Array (LC 26)**, with solid answers.

## Core understanding

### 1) What’s the main idea of your solution?

**Answer:**
Because the array is sorted, duplicates are adjacent. I use two pointers: `c` is the index of the last unique element (write position), and `i` scans the array. When `nums[i]` differs from `nums[c]`, I found a new unique value, so I increment `c` and write it at `nums[c]`.

### 2) Why does sorting matter here?

**Answer:**
Sorting guarantees all duplicates are grouped together, so I only need to compare the current element with the last unique element. Without sorting, duplicates could appear anywhere and this approach wouldn’t work.

### 3) What invariant are you maintaining?

**Answer:**
At any time, `nums[0..c]` contains the unique elements in sorted order, with no duplicates. Everything after `c` is irrelevant.

---

## Correctness and edge cases

### 4) Walk through an example.

**Answer:**
For `[0,0,1,1,1,2,2,3]`
Start `c=0` (unique: `[0]`)
Scan `i`:

* `0` same → skip
* `1` different → `c=1`, write `1`
* next `1`s skip
* `2` different → `c=2`, write `2`
* `3` different → `c=3`, write `3`
  Return `c+1=4`. First 4 values are `[0,1,2,3]`.

### 5) What happens if the array is empty?

**Answer:**
Your current code returns `1` incorrectly, because it assumes at least one element. The correct handling is:

* if `n == 0` return `0`
  Then proceed.

### 6) What happens if all elements are the same?

**Answer:**
`c` stays 0, we return `1`. The first element remains as the only unique value.

### 7) What happens if there are no duplicates?

**Answer:**
Every element differs from the previous unique, so `c` ends at `n-1` and we return `n`. The array stays unchanged.

---

## Complexity

### 8) Time and space complexity?

**Answer:**
Time: **O(n)**, single pass.
Space: **O(1)** extra space, in-place.

### 9) How many writes do you perform?

**Answer:**
At most `k-1` writes (where `k` is number of unique elements), because we only write when we find a new unique.

---

## Code-level / implementation questions

### 10) Why do you return `c+1`?

**Answer:**
`c` is the index of the last unique element. Count = last_index + 1 = `c + 1`.

### 11) Why do you compare `nums[i] != nums[c]` instead of `nums[i] != nums[i-1]`?

**Answer:**
Comparing with `nums[c]` ties directly to the “last unique” element, so it stays correct even as we overwrite values. Comparing to `nums[i-1]` can also work in sorted arrays, but `nums[c]` is the clean invariant-based approach.

### 12) Does this preserve order?

**Answer:**
Yes. Since we only move forward and copy in sequence, the relative order of unique elements is preserved.

---

## Follow-ups interviewers love

### 13) Can you solve it using a different pointer style?

**Answer:**
Yes: `write = 1`, loop `i` from 1. If `nums[i] != nums[i-1]`, write `nums[write++] = nums[i]`.
Both are valid because the array is sorted.

### 14) What if I ask you to remove duplicates but allow each value at most twice? (LC 80)

**Answer:**
Use a write pointer and allow writing if `write < 2` or `nums[i] != nums[write-2]`. That ensures each value appears at most twice.

### 15) What if the input is not sorted and you must remove duplicates in-place?

**Answer:**
If order must be preserved, you typically need a hash set → **O(n)** extra space.
If order doesn’t matter, you can sort first (O(n log n)) then use this method.

### 16) Can you do it in one pass without extra space for unsorted?

**Answer:**
Not in general while preserving order. Without sorting or extra memory, detecting duplicates requires remembering seen elements, which implies extra space or multiple passes.

---

## “Gotcha” questions

### 17) What bug exists in your current code?

**Answer:**
It fails for `n == 0` because it returns `c+1` which is 1. Fix by:

```cpp
if (nums.empty()) return 0;
```

### 18) Why is it safe to overwrite `nums[c]`?

**Answer:**
Because `c` always lags behind or equals `i`, so we only overwrite positions that are no longer needed for future comparisons. The source of truth for comparisons remains the last unique value, which we maintain.

---

## Interview-ready 30-second explanation

**Answer:**
“Since the array is sorted, duplicates are adjacent. I keep a write index `c` that points to the last unique element. I scan with `i`. When `nums[i]` differs from `nums[c]`, I increment `c` and copy `nums[i]` to `nums[c]`. At the end, the first `c+1` elements are the unique values, so I return `c+1`. This is O(n) time and O(1) space.”

---

If you want, paste the LC 80 version you’re practicing next (remove duplicates allowing at most twice) and I’ll give you the same “all interview questions + answers” set for that too.

*/