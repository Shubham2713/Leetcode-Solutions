//https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        int p=n-1;//pointer at last element
        //this can also be atest
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)//when we encounter a val
            {
                while(p>i && nums[p]==val)//we find a number from behind not equal to val and swap it with nums[i]
                {
                    p--;//but that number should be greater than i 
                }
                swap(nums[i],nums[p]);
            }
        }
        int c=0;//counter
        for(int i=0;i<n;i++)
        if(nums[i]!=val)
        c++;

        return c;
    }
};

/*
Here are the interview questions that commonly get asked around **Remove Element (LeetCode 27)**, with strong, ready-to-say answers.

## 1) What’s the main idea of your solution?

**Answer:**
We need to remove all occurrences of `val` in-place and return `k`, the count of remaining elements. Since order doesn’t matter, we can either:

* **Compact** non-`val` values to the front using a write pointer (stable), or
* **Swap with the end** to reduce work when `val` is frequent (not stable).

---

## 2) Why is the write-pointer approach correct?

**Answer:**
We maintain an invariant: indices `[0..k-1]` always contain elements not equal to `val`.
When we see a non-`val` element at `i`, we place it at `nums[k]` and increment `k`.
At the end, the first `k` elements are exactly the elements we keep.

---

## 3) What’s the time and space complexity?

**Answer:**
Time: **O(n)** because we scan once.
Space: **O(1)** extra space because we modify in place.

---

## 4) Does your solution preserve order?

**Answer:**
The **write-pointer** solution preserves relative order of non-`val` elements (stable).
The **swap-from-end** solution does not guarantee order, but it’s allowed by the problem.

---

## 5) When is “swap with end” better than “write pointer”?

**Answer:**
When `val` occurs very frequently, swapping with the end can reduce the number of assignments because we don’t copy every kept element forward; we only swap when we hit a `val`.

---

## 6) Explain the “swap with end” approach and why it works.

**Answer:**
Use two pointers: `i` from start, `p` from end.
If `nums[i] == val`, swap it with `nums[p]` and decrement `p` (shrinking valid range).
If `nums[i] != val`, increment `i`.
Invariant: indices `(p+1..end)` are all `val` (removed zone).
Stop when `i > p`. Remaining count is `p+1`.

---

## 7) What’s wrong with doing `erase` in a loop in C++?

**Answer:**
`erase` shifts elements and is **O(n)** per erase, so worst case becomes **O(n²)**. Also iterators/indexes become tricky after erase.

---

## 8) Why does the function return `k` instead of the new array?

**Answer:**
Because the problem is designed to test in-place array manipulation. The first `k` values in `nums` are the valid result; anything after `k` is irrelevant.

---

## 9) What happens if `val` doesn’t exist in the array?

**Answer:**
`k` ends up equal to `n`, and the array remains unchanged.

---

## 10) What happens if all elements are `val`?

**Answer:**
`k` becomes 0, and we return 0. The array content doesn’t matter after index 0.

---

## 11) Can you do it in one pass?

**Answer:**
Yes, both main solutions are one-pass:

* Write-pointer: one loop
* Swap-from-end: `i` moves forward, `p` moves backward; each element handled at most once.

---

## 12) What invariant do you maintain in the write-pointer method?

**Answer:**
Before processing index `i`, the segment `[0..k-1]` contains only elements not equal to `val`, in their original relative order.

---

## 13) What invariant do you maintain in the swap-from-end method?

**Answer:**
At all times:

* `[0..i-1]` contains elements not equal to `val` (processed valid zone)
* `[p+1..n-1]` contains only `val` (removed zone)
* `[i..p]` is unknown/unprocessed

---

## 14) Why do you not increment `i` after swapping in the end-swap method?

**Answer:**
Because the element swapped into `i` is unprocessed; it could still be `val`, so we must check it again.

---

## 15) In your code, what bug/risk exists if you use a `for(i=0; i<n; i++)` with end swapping?

**Answer:**
If you always increment `i` (as `for` does), you may skip re-checking the swapped-in value. The safer structure is a `while(i <= p)` loop where you control `i`.

---

## 16) How would you rewrite your swap solution in the clean interview form?

**Answer (code-level explanation):**
Use `i=0`, `p=n-1`.
While `i <= p`:

* If `nums[i] == val`, swap `nums[i]` with `nums[p]`, decrement `p`
* Else increment `i`
  Return `p+1`.

---

## 17) Can you show the optimal code you’d present in an interview?

**Answer (stable version):**

```cpp
int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}
```

**Answer (swap version):**

```cpp
int removeElement(vector<int>& nums, int val) {
    int i = 0, p = (int)nums.size() - 1;
    while (i <= p) {
        if (nums[i] == val) swap(nums[i], nums[p--]);
        else i++;
    }
    return p + 1;
}
```

---

## 18) Why is the stable version sometimes preferred?

**Answer:**
It’s simpler, predictable, preserves order, and is usually easiest to reason about and verify.

---

## 19) How do you test it quickly?

**Answer:**
Test edge cases:

* `[]` doesn’t happen here because `n>=1`, but small sizes
* `[1]` with `val=1` → `k=0`
* `[1]` with `val=2` → `k=1`
* `[3,3,3]` with `val=3` → `k=0`
* `[3,2,2,3]` with `val=3` → `k=2`
* `val` in middle, at ends, alternating patterns

---

## 20) What if the interviewer asks for “minimum number of writes”?

**Answer:**
Use the swap-from-end method. It avoids shifting lots of elements forward when many values are removed.

---

## 21) Can this be generalized to “remove elements based on a condition”?

**Answer:**
Yes. Replace `nums[i] != val` with any predicate (e.g., keep only positives). The same write-pointer compaction pattern applies.

---

## 22) What common patterns does this question test?

**Answer:**
Two-pointer compaction, in-place array manipulation, loop invariants, and careful pointer movement—skills used in partitioning, deduplication, and window-based problems.

---

If you want, I’ll also generate a **mock interview script**: interviewer asks, you answer (30–60 seconds each), including follow-up traps like “order must be preserved” or “minimize swaps.”

*/
