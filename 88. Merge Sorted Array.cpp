//https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    //we traverse from back to front placing the larger element at the end of nums1 using 3 pointer 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int p1=m-1;//pointer at last non zero elemet of nums1
        int p2=n-1;// pointer at last non zero element of nums2
        int p=m+n-1;// pointer at end of array nums1
        //this is atest
        while(p1>=0 && p2>=0)
        {
            if(nums1[p1 ] >nums2[p2])
            {
                nums1[p--]=nums1[p1--];
            }
            else
            {
                nums1[p--]=nums2[p2--];
            }
        }

        while(p1>=0)
        {
            nums1[p--]=nums1[p1--];
        }
        while(p2>=0)
        {
            nums1[p--]=nums2[p2--];
        }

        


    }
};

/*
Here are the interview questions that typically come up around **Merge Sorted Array (LC 88)**, with tight answers you can speak out loud.

## Concept and Approach

### 1) What’s the core idea of your solution?

**Answer:**
`nums1` has extra space at the end, so I merge **from the back** to avoid overwriting unprocessed elements in `nums1`. I compare the largest remaining elements from both arrays and write the larger one into the last available slot.

### 2) Why do you merge from the end instead of the start?

**Answer:**
If I merge from the start, I’d overwrite elements in `nums1` that I still need to compare later. Merging from the end uses the buffer space safely and keeps everything in-place.

### 3) What pointers do you use and what do they represent?

**Answer:**

* `p1 = m-1`: last valid element in `nums1`
* `p2 = n-1`: last element in `nums2`
* `p = m+n-1`: last write position in `nums1`

### 4) What invariant are you maintaining?

**Answer:**
After each step, `nums1[p+1 ... m+n-1]` contains the **largest elements in sorted order**, already finalized.

---

## Correctness and Edge Cases

### 5) Why is the algorithm correct?

**Answer:**
At any point, the largest element among remaining candidates must be either `nums1[p1]` or `nums2[p2]`. Placing the max at `nums1[p]` is always correct. Repeating this finalizes the array from right to left.

### 6) Why do you only copy remaining elements from `nums2` and not from `nums1`?

**Answer:**
If `nums2` has leftovers, they belong at the front and must be written. If `nums1` has leftovers, they’re already in the correct positions because we only move elements to the right, never disrupting the earlier part.

### 7) What happens if `n = 0`?

**Answer:**
`p2 = -1`, loops don’t run, `nums1` stays the same.

### 8) What happens if `m = 0`?

**Answer:**
`p1 = -1`, we skip the main loop and copy all of `nums2` into `nums1`.

### 9) How does it behave with duplicates?

**Answer:**
Works naturally since comparisons handle `<=` and `>=`. Sorted order remains non-decreasing.

### 10) Is the merge stable?

**Answer:**
Not guaranteed stable across arrays because when equal I take from `nums2` first (due to `else`). If stability is required (keep `nums1` elements before `nums2` for equals), I’d change the comparison to `>=` and take from `nums1` first.

---

## Complexity

### 11) Time complexity?

**Answer:**
**O(m+n)**. Each pointer moves left at most its array length.

### 12) Space complexity?

**Answer:**
**O(1)** extra space. All merging is done inside `nums1`.

---

## Common Follow-ups / Variations

### 13) If `nums1` didn’t have extra space, how would you do it?

**Answer:**
Use an auxiliary array of size `m+n` (or merge into a new vector) then copy back if needed. That becomes **O(m+n)** time and **O(m+n)** space.

### 14) How would you merge in descending order?

**Answer:**
Same structure, but compare accordingly (largest/smallest depends on direction). For descending arrays, you’d still pick the “correct next element” to fill from the end or start based on avoiding overwrite.

### 15) Can you do it recursively?

**Answer:**
Yes, but recursion adds call stack space and offers no advantage here. Iterative is cleaner and truly O(1) extra space.

### 16) What if both arrays are huge and you care about cache friendliness?

**Answer:**
This is already cache-friendly because it’s linear scans from the end. Access patterns are predictable.

---

## Tricky Interview “Gotchas”

### 17) Why do you initialize `p = m+n-1`?

**Answer:**
That’s the last index of `nums1`, where the final largest element must go.

### 18) What if you mistakenly used `p = m+n`?

**Answer:**
Out-of-bounds write. `p` must be the last valid index.

### 19) Why is the condition `while(p1>=0 && p2>=0)` and not `||`?

**Answer:**
Because we compare only while both sides have remaining valid elements. If one side is exhausted, we handle leftovers separately.

### 20) What’s the worst-case number of writes?

**Answer:**
At most `m+n` writes into `nums1`. Every position is written at most once.

### 21) Can you early-exit in some cases?

**Answer:**
Yes. If `n == 0`, done immediately. Also if `m == 0`, just copy `nums2`. Some implementations also stop if `p2 < 0`.

---

## Code-Level Questions

### 22) What happens if `nums1` and `nums2` refer to the same memory?

**Answer:**
This problem assumes distinct arrays. If they alias, behavior is undefined for this approach.

### 23) Why is it safe to overwrite `nums1[p]`?

**Answer:**
Because `p` always points to an index beyond the last unprocessed element in `nums1` (`p >= p1`). We’re writing into the buffer region or into slots that are already “consumed” from the back.

### 24) What if inputs are not sorted?

**Answer:**
This algorithm relies on sorted order. If not sorted, result won’t be sorted. You’d need to sort first or use a different strategy.

---

## Interview-Ready Explanation (30–40 seconds)

**Answer:**
“I use three pointers starting from the end: `p1` at the last real element of `nums1`, `p2` at the last element of `nums2`, and `p` at the last index of `nums1`. I compare `nums1[p1]` and `nums2[p2]`, place the larger at `nums1[p]`, and move the corresponding pointer left. This fills the array from right to left without overwriting unprocessed values in `nums1`. If anything remains in `nums2`, I copy it over. Time is O(m+n), space is O(1).”

---

If you want, I can also give you the **top 10 “follow-up twist” versions** interviewers use (k arrays, linked lists, streaming merge, stability constraints, counting comparisons, etc.) and how to answer each.

*/
